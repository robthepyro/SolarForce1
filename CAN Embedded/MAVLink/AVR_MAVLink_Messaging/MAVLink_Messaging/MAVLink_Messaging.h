/*
 * MAVLink_Messaging.h
 *
 * Created: 2015/03/31 10:51:38 PM
 *  Author: Matt
 */ 


#ifndef MAVLINK_MESSAGING_H_
#define MAVLINK_MESSAGING_H_

//#define MAVLINK_USE_CONVENIENCE_FUNCTIONS

//------------Port Naming/ System Defines-----------------//

#define F_CPU 16000000UL
#define UART_BAUD_RATE 9600


#define TELEMETRY_UART_OUT	DDD1
#define GPS_UART_DATA_IN	DDD0
#define TELEMETRY_UART_IN	DDD0

#define CANINT_DDR			DDRB
#define CANINT_PORT			PORTB
#define CANINT_LED			PORTB1

#define LED_DIAG_DDR		DDRD
#define LED_DIAG_PORT		PORTD
#define LED_DIAG_ORG		PORTD2
#define LED_DIAG_GRN		PORTD3	

#define UART_DDR			DDRD

#define UART_REG			UCSR0A
#define TX_ENABLE			(1<<TXEN0)
#define TX_DISABLE			(0<<TXEN0)

//------------Library and AVR Includes--------------------//

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <string.h>
#include "../lib/uart/uart.h"					//UART library

#include "../lib/CAN/CAN.h"			//CAN Framework
#include "../lib/mcp2515/mcp2515.h"	//bit timings for MCP2515

#include "mavlink_bridge_header.h"  //UART & convenience headers


//------------Library Objects----------------------------//

CANMessage CANBusInput;				//CAN library object

volatile int counter=0;
volatile int ctr2=0;

char MAV_Rx_buff[10];

//------------Function Prototypes------------------------//

		int system_type = MAV_TYPE_GROUND_ROVER;
		int autopilot_type = MAV_AUTOPILOT_GENERIC;
		int base_mode = MAV_MODE_FLAG_AUTO_ENABLED;
		int custom_mode = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
		int system_status = MAV_STATE_ACTIVE;

void CAN_readData(void);
void MAV_msg_pack();
void MAV_uart_send(uint8_t [],uint8_t);
void GPS_readData(void);

static inline void mavlink_msg_motor_driver_decode(const mavlink_message_t* msg, mavlink_motor_driver_t* motor_driver);


 

#endif /* MAVLINK_MESSAGING_H_ */