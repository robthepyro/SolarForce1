/*
 * Display_Node.c
 *
 *  Created on: 01 Apr 2015
 *      Author: RobThePyro
 */

#include "Display_Node.h"

int main(void)
{
	// HACK
	// LCD SCKCTL Output
	LCD_SCKCTL_DDR |= (1<<LCD_SCKCTL);
	LCD_UNSELECT();				// Disable the sck line of LCD to bypass ST7920 bug

	// Init SPI
	SPI_Init();

	// Init CAN
	CAN_Init(CAN_125KBPS_16MHZ); // Setup CAN Bus with our desired speed
	CAN_setupPCINT0();			 // Setup CAN Message buffer using PCINT ISR

	// Init LCD
	Screen = SCREEN_MAIN;
	//Screen = SCREEN_MPPT;
	LCD_SELECT();				// Enable the sck line of LCD to bypass ST7920 bug
	GFX_LCD_u8g_setup();				// Call u8glib setup for the LCD
	LCD_UNSELECT();				// Disable sck of LCD to prevent crap being displayed when
								// Talking to other things on SPI
	flagUpdateLCD = TRUE; 		// Signal that an update is needed;

	// Init LCD Backlight
	Timer1_init();				// Setup the timer for PWM
	LCD_BackLight = 64;		// Set the default backlight value
	Timer1_PWM_On();			// Turn backlight on

	// Init the throttle PWM output?
	Timer2_init();

	// Init Timer0 for mS Counter
	Timer0_init();

	// Init Hardware
	IOInit();

	// Init Btn press stuff
	btn_press_flag = FALSE;
	setupPCINT2();

	// Create a new message
	CANMessage message;
	heartbeat_Msg = (CANMessage) {.id=0x0888,.rtr=0,.length=5,.data={'A','L','I','V','E'}};
	reqMPPT1_Msg = (CANMessage) {.id=0x0711,.rtr=1,.length=0,.data={}};
	reqMPPT2_Msg = (CANMessage) {.id=0x0712,.rtr=1,.length=0,.data={}};
	reqMPPT3_Msg = (CANMessage) {.id=0x0713,.rtr=1,.length=0,.data={}};
	reqMPPT4_Msg = (CANMessage) {.id=0x0714,.rtr=1,.length=0,.data={}};

	// Enable Interrupts
	sei();

	// Loop for all the time ever!!! (Hopefully...)
    while(1) {


    	// Check if there are any messages in the buffer, loop on more messages
    	while(flag == CAN_MSGAVAIL){
    		// Fetch a message and if valid, decode it
			if(CAN_getMessage_Buffer(&message) == CAN_OK){
				// Decode a message and if a field of importance is found, signal LCD update
				if(CAN_Decode(&message) == CAN_MSG_DECODED){
					// Set the LCD update flag
					flagUpdateLCD = TRUE;
				}
			// no valid message, reset the CAN Buffer flag ?
			//TODO: There might be a logic fail here that leads to an overflow... must check..
			}else if(flag == CAN_FAIL){ // Backup Plan?
				flag = CAN_NOMSG;
			}
			// Improve buffer performance?
			//cli();
			//if(~CHECKBIT(PINB,PB0))
			//{
			//	CAN_fillBuffer();
			//}
			//sei();
    	}

    	// lockout for at least 10 mS after last interrupt
    	if(gMilliSecTick - int_mS > 9){
			// If an LCD update is needed, then do it!
			if(flagTimerUpdateLCD == TRUE && flagUpdateLCD == TRUE){
				// get the temp
				//AVR_Temp = ADC_getTemp();
				// Call the update function
				LED_ON(LED_RF);
				GFX_LCD_DrawMain();
				LED_OFF(LED_RF);
				// reset the flag
				flagUpdateLCD = FALSE;
				flagTimerUpdateLCD = FALSE; // Sneaky!
			}
			// If time to req MPPT data then do it!
			if(flagTimerReqMPPT == TRUE){
				CAN_sendMessage(&reqMPPT1_Msg);
				CAN_sendMessage(&reqMPPT2_Msg);
				CAN_sendMessage(&reqMPPT3_Msg);
				CAN_sendMessage(&reqMPPT4_Msg);
				// finally reset flag
				flagTimerReqMPPT = FALSE;

				// hack
				//ADC_start(0);
				//gCANVars.MPPT1_Vin = ADC;
				//gCANVars.MPPT1_Vin |= ADCH<<8;
				//flagUpdateLCD = TRUE;
			}
    	}

    	if(gMilliSecTick - heartbeat_mS > HEATBEAT_MS){ // shoot off a heartbeat message
        	// If the int pin is held low then we wont have an ISR!
        	// Disable the interrupts and process all outstanding buffer calls
        	cli();
        	if(~CHECKBIT(PINB,PB0))
        	{
        		LED_ON(LED_B);
        		CAN_fillBuffer();
        		LED_OFF(LED_B);
        	}
        	sei();

    		heartbeat_mS = gMilliSecTick;
    		CAN_sendMessage(&heartbeat_Msg);


    	}



    } // FOREVER LOOP :0
} // Life...


// Sets up the IO...
void 	IOInit(void){
	// LEDs Outputs
	LED_DDR |= (1<<LED_RF)|(1<<LED_B);
	LED_ON(LED_RF);
	LED_OFF(LED_B);

	// Btn inputs
	BTN_DDR &= ~((1<<BTN_1)|(1<<BTN_3)|(1<<BTN_4));
	// Btn Pullups
	BTN_PORT |= (1<<BTN_1)|(1<<BTN_3)|(1<<BTN_4);

	// Throttle ADC Stuff..
	// Make input
	CRUISE_ADC_DDR &= ~(1<<CRUISE_ADC_THR);
	// no pullup
	CRUISE_ADC_PORT &= ~(1<<CRUISE_ADC_THR);


}

//CAN Message selective decoding
uint8_t CAN_Decode(CANMessage *message){
	uint8_t	decode_result;

	// Decode the message into global external vars
	switch(message->id){

	case CANID_SPEED:
		// We found a speed message!
		// get the speed value;
		gSpeed = (message->data[0]);
		gSpeed_HESSpd = (message->data[1]);
		gSpeed_HESRPM = (message->data[3] <<8)|(message->data[2]);
		gSpeed_MTSpd = (message->data[4]);
		gSpeed_MTRPM = (message->data[5] <<8)|(message->data[6]);
		gSpeed_status = (message->data[7]);

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

	break; //CANID_SPEED

	case CANID_BMS2:
		gBMS_State  	 = message->data[0];
		gBMS_Flags  	 = message->data[3];
		gBMS_Faults 	 = message->data[4];
		gBMS_LevelFaults = message->data[5];
		gBMS_Warnings    = message->data[6];

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;
	break; //CANID_BMS2

	case CANID_BMS3:
		gBMS_PackVoltage = (message->data[0]<<8)|(message->data[1]);
		gBMS_MaxVTG 	 = message->data[4];

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;
	break; //CANID_BMS3

	case CANID_BMS4:
		gBMS_PackCurrent = (message->data[0]<<8)|(message->data[1]);

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;
	break; //CANID_BMS4

	case CANID_BMS6:
		gBMS_soc = message->data[0]; // State of charge

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

	break; //CANID_BMS6

	case CANID_BMS7:
		gBMS_Temp = message->data[0]; // Average Temp

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

	break; //CANID_BMS7

	case CANID_GYRO_ANGLESI:
		gGyro_AngleTHE = (message->data[0]<<24)|(message->data[1]<<16)|(message->data[2]<<8)|(message->data[0]);
		gGyro_AngleSI = (message->data[4]<<24)|(message->data[5]<<16)|(message->data[6]<<8)|(message->data[7]);

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

	break; //CANID_GYRO_ANGLESI

	case CANID_IMU_GYRO:
		gGyro_AnglePHI = (message->data[4]<<24)|(message->data[5]<<16)|(message->data[6]<<8)|(message->data[7]);

		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

	break; //CANID_GYRO_ANGLEPHI

	case CANID_MPPT1:
		gCANVars.MPPT1_Status = message->data[0]&0xF0 ; // Mask off status bits
		gCANVars.MPPT1_Vin    = ((message->data[0]&0x03)<<8)|(message->data[1]); // Get Vin
		gCANVars.MPPT1_Iin    = ((message->data[2]&0x03)<<8)|(message->data[3]); // Get Iin
		gCANVars.MPPT1_Vout   = ((message->data[4]&0x03)<<8)|(message->data[5]); // Get Vout
		gCANVars.MPPT1_Tamb   = message->data[6]; // get Tamb
		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

		// Do conversions for units?
		// Vin >> 150.49 mV / bit
		// Vout >> 208.79 mV / bit
		// Iin >> 8.72 mA / bit

		// we should maybe do this conversion when we fetch the data and the store in the structure?
		// Also, we prob want to do this as floating point, or keep as mV and do conversion when we display?

		//Vin
		tempVar = gCANVars.MPPT1_Vin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT1_Vin = tempVar; // Store back in the original variable?

		//Vout
		tempVar = gCANVars.MPPT1_Vout; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VOUT_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT1_Vout = tempVar; // Store back in the original variable?

		//Iin
		tempVar = gCANVars.MPPT1_Iin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_IIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT1_Iin = tempVar; // Store back in the original variable?


	break; //CANID_MPPT1

	case CANID_MPPT2:
		gCANVars.MPPT2_Status = message->data[0]&0xF0 ; // Mask off status bits
		gCANVars.MPPT2_Vin    = ((message->data[0]&0x03)<<8)|(message->data[1]); // Get Vin
		gCANVars.MPPT2_Iin    = ((message->data[2]&0x03)<<8)|(message->data[3]); // Get Iin
		gCANVars.MPPT2_Vout   = ((message->data[4]&0x03)<<8)|(message->data[5]); // Get Vout
		gCANVars.MPPT2_Tamb   = message->data[6]; // get Tamb
		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;

		//Vin
		tempVar = gCANVars.MPPT2_Vin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT2_Vin = tempVar; // Store back in the original variable?

		//Vout
		tempVar = gCANVars.MPPT2_Vout; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VOUT_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT2_Vout = tempVar; // Store back in the original variable?

		//Iin
		tempVar = gCANVars.MPPT2_Iin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_IIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT2_Iin = tempVar; // Store back in the original variable?

	break; //CANID_MPPT2

	case CANID_MPPT3:
		gCANVars.MPPT3_Status = message->data[0]&0xF0 ; // Mask off status bits
		gCANVars.MPPT3_Vin    = ((message->data[0]&0x03)<<8)|(message->data[1]); // Get Vin
		gCANVars.MPPT3_Iin    = ((message->data[2]&0x03)<<8)|(message->data[3]); // Get Iin
		gCANVars.MPPT3_Vout   = ((message->data[4]&0x03)<<8)|(message->data[5]); // Get Vout
		gCANVars.MPPT3_Tamb   = message->data[6]; // get Tamb
		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;


		//Vin
		tempVar = gCANVars.MPPT3_Vin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT3_Vin = tempVar; // Store back in the original variable?

		//Vout
		tempVar = gCANVars.MPPT3_Vout; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VOUT_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT3_Vout = tempVar; // Store back in the original variable?

		//Iin
		tempVar = gCANVars.MPPT3_Iin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_IIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT3_Iin = tempVar; // Store back in the original variable?
	break; //CANID_MPPT3

	case CANID_MPPT4:
		gCANVars.MPPT4_Status = message->data[0]&0xF0 ; // Mask off status bits
		gCANVars.MPPT4_Vin    = ((message->data[0]&0x03)<<8)|(message->data[1]); // Get Vin
		gCANVars.MPPT4_Iin    = ((message->data[2]&0x03)<<8)|(message->data[3]); // Get Iin
		gCANVars.MPPT4_Vout   = ((message->data[4]&0x03)<<8)|(message->data[5]); // Get Vout
		gCANVars.MPPT4_Tamb   = message->data[6]; // get Tamb
		// let the caller know we found something!
		decode_result = CAN_MSG_DECODED;


		//Vin
		tempVar = gCANVars.MPPT4_Vin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT4_Vin = tempVar; // Store back in the original variable?

		//Vout
		tempVar = gCANVars.MPPT4_Vout; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_VOUT_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT4_Vout = tempVar; // Store back in the original variable?

		//Iin
		tempVar = gCANVars.MPPT4_Iin; // put in 32 bit holder to prevent overflows?
		tempVar = tempVar * MPPT_IIN_MUL; // convert to mV
		tempVar = tempVar / 1000; // convert to V?
		gCANVars.MPPT4_Iin = tempVar; // Store back in the original variable?
	break; //CANID_MPPT4

	default:
		// We didn't find any message we are looking for...
		decode_result = CAN_NODECODE;
	break;
	}

	// Let the caller know if we found something useful
	return decode_result;

}

void setupPCINT2(void){
	// setup pin int
	BTN_DDR &= ~((1<<BTN_4)|(1<<BTN_3));   //Set pin as input
	BTN_PORT |= (1<<BTN_4)|(1<<BTN_3);   //Pullup
	PCICR |= (1<<PCIE2); //Enable on PCINT0 pins
	PCMSK2 |= (1<<PCINT4)|(1<<PCINT5); //Mask PD4, PD5
}

// CAN Interrupt ISR!
ISR(PCINT0_vect){

	LED_ON(LED_B);
	CAN_fillBuffer();
	int_mS = gMilliSecTick;
	LED_OFF(LED_B);

}

// Push button ISR
ISR(PCINT2_vect){
	// We had int from Btn 3 or Btn 4?
	if(FALSE == btn_press_flag){ // start the debounce stuff
		btn_press_flag = TRUE;
		btn_int_mS = gMilliSecTick;

		// otherwise check how long it has been (30mS debounce)
	}else if ((gMilliSecTick - btn_int_mS > 40) && btn_press_flag){

		// it has been 30mS, reset the flag
		btn_press_flag = FALSE;
		// check if the button is still pressed:
		if(!CHECKBIT(BTN_PIN,BTN_3)){ // Screen Change
			if (Screen == SCREEN_MAIN ){
				Screen = SCREEN_SPD;
			}else if(Screen == SCREEN_SPD){
				Screen = SCREEN_MPPT;
			}else{
				Screen =SCREEN_MAIN;
			}
			// tell the lcd it needs to updagte
			flagUpdateLCD = TRUE;
		}else if(!CHECKBIT(BTN_PIN,BTN_4)){ // Backlight Change
			LCD_BackLight = LCD_BackLight + 64;
		}
	}



}
