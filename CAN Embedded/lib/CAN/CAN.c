/*
 * CAN.c
 *
 *  Created on: 30 Mar 2015
 *      Author: RobThePyro
 *
 *      CAN application layer
 */

#include "CAN.h"
#include "../mcp2515/mcp2515.h"


// Setup the RX Buffer
#define CAN_RX_BUFFER_MASK	(CAN_RX_BUFFER_SIZE - 1 )
#if ( CAN_RX_BUFFER_SIZE & CAN_RX_BUFFER_MASK )
#error RX buffer size is not a power of 2
#endif

// Create the buffer
static volatile CANMessage CAN_Rx_Buffer[CAN_RX_BUFFER_SIZE];
static volatile uint8_t CAN_Rx_Head;
static volatile uint8_t CAN_Rx_Tail;
volatile uint8_t 	flag;
//WE NEED AN ISR!

ISR(INT0_vect){
	uint8_t tmphead;
	//uint8_t lastRxError;

	// WE HAVE A MESSAGE
	/* calculate buffer index */
		tmphead = ( CAN_Rx_Head + 1) &CAN_RX_BUFFER_MASK;

		if ( tmphead == CAN_Rx_Tail ) {
			/* error: receive buffer overflow */
		//	lastRxError = CAN_BUFFER_OVERFLOW >> 8;
			flag = CAN_FAIL;
		}else{
			/* store new index */
			CAN_Rx_Head = tmphead;
			/* store received data in buffer */
			CANMessage msg;
			CAN_readMessage(&msg);
			CAN_Rx_Buffer[tmphead] = msg;
			flag = CAN_MSGAVAIL;
		}
		//CAN_LastRxError = lastRxError;


}

/*************************************************************************
Function: CAN_Init()
Purpose:  Init the CAN interface
Input:    Bit time speed setup
Returns:  Ok / Fail
**************************************************************************/
uint8_t CAN_Init(uint8_t speedset)
{
	CAN_Rx_Head = 0;
	CAN_Rx_Tail = 0;
	uint8_t res;

	res = mcp2515_init(speedset);

	if (res == MCP2515_OK) return CAN_OK;
	else return CAN_FAILINIT;
}


void CAN_setupInt0(void){
	// setup pin int
	DDRD &= ~(1<<PD2);   //Set pin as input
	PORTD |= (1<<PD2);
	EICRA |= (1<<ISC01); //Falling edge of INT0
	EIMSK |= (1<<INT0);  //enable int
	flag = CAN_NOMSG;
}

uint8_t CAN_getMessage_Buffer(CANMessage *msg){
    uint8_t tmptail, res;

    if ( CAN_Rx_Head == CAN_Rx_Tail ) {
    	res = CAN_NOMSG;
    	flag = CAN_NOMSG;
        return res;   /* no data available */
    }

    /* calculate /store buffer index */
    tmptail = (CAN_Rx_Tail + 1) & CAN_RX_BUFFER_MASK;
    CAN_Rx_Tail = tmptail;

    /* get data from receive buffer */
    //CANMessage message = CAN_Rx_Buffer[tmptail];
    //msg = &message;
    *msg = CAN_Rx_Buffer[tmptail];

    res = CAN_OK;
    return res;

}


/*************************************************************************
Function: CAN_sendMessage()
Purpose:  Takes a CAN message and sends it out :)
Input:    CANMessage Struct
Returns:  Ok / Fail
**************************************************************************/
uint8_t CAN_sendMessage(const CANMessage* message)
{
	uint8_t length = message->length;

	// ID set
	mcp2515_setRegister ( MCP_TXB0SIDH, ( uint8_t ) ( message->id>> 3 ) ) ;
	mcp2515_setRegister ( MCP_TXB0SIDL, ( uint8_t ) ( message->id<< 5 ) ) ;

	// If the message is a "Remote Transmit Request"
	if ( message->rtr )
	{
	/* Although A RTR message has a length, but no data */

	// Set message length + RTR
	mcp2515_setRegister( MCP_TXB0DLC, ( 1 <<RTR ) | length ) ;
	}
	else
	{
		// Set message length
	mcp2515_setRegister( MCP_TXB0DLC, length ) ;

	// Data
	for ( uint8_t i= 0 ;i<length;i++ ) {
	mcp2515_setRegister( MCP_TXB0D0 + i, message->data [ i ] ) ;
	}
	}

	// Send CAN message
	#define	SPI_RTS			0x80
	MCP2515_SELECT();
	SPI_ReadWrite( SPI_RTS | 0x01 ); // Sends the message!
	MCP2515_UNSELECT();

	return CAN_OK;

	//TODO: Implement this fancy stuff.. for now we use the germans!
//	uint8_t res, txbuf_n;
//	uint8_t timeout = 0;
//	uint16_t time;
//	time = timebase_actTime();
//
//	do {
//		res = mcp2515_getNextFreeTXBuf(&txbuf_n); // info = addr.
//		if (timebase_passedTimeMS(time) > CANSENDTIMEOUT ) timeout = 1;
//	} while (res == MCP_ALLTXBUSY && !timeout);
//
//	if (!timeout) {
//		mcp2515_write_canMsg( txbuf_n, msg);
//		mcp2515_start_transmit( txbuf_n );
//		return CAN_OK;
//	}
//	else {
//#if (CANDEBUG)
//		term_puts_P("Transmit timeout\n");
//#endif
//		return CAN_FAILTX;
//	}
}

/*************************************************************************
Function: CAN_readMessage()
Purpose:  Takes a CAN message pointer and stores the data into it
Input:    CANMessage Struct
Returns:  CAN_OK / CAN_NOMSG
**************************************************************************/
uint8_t CAN_readMessage(CANMessage *msg)
{
	uint8_t stat, res;

	stat = mcp2515_readStatus();

	if ( stat & MCP_STAT_RX0IF ) {
		// Msg in Buffer 0
		mcp2515_read_canMsg( MCP_RXBUF_0, msg);
		mcp2515_modifyRegister(MCP_CANINTF, MCP_RX0IF, 0);
		res = CAN_OK;
	}
	else if ( stat & MCP_STAT_RX1IF ) {
		// Msg in Buffer 1
		mcp2515_read_canMsg( MCP_RXBUF_1, msg);
		mcp2515_modifyRegister(MCP_CANINTF, MCP_RX1IF, 0);
		res = CAN_OK;
	}
	else {
		res = CAN_NOMSG;
	}

	return res;
}


/*************************************************************************
Function: CAN_checkReceiveAvaliable()
Purpose:  Checks if there is any CAN message sitting in a buffer?
Input:    None
Returns:  either
 #define CAN_MSGAVAIL   (3) - a message has been received
 #define CAN_NOMSG      (4) - no new message
**************************************************************************/
uint8_t CAN_checkReceiveAvailable(void)
{
	uint8_t res;

	res = mcp2515_readStatus(); // RXnIF in Bit 1 and 0
	if ( res & MCP_STAT_RXIF_MASK ) {
		return CAN_MSGAVAIL;
	}
	else {
		return CAN_NOMSG;
	}
}

/*************************************************************************
Function: CAN_checkError
Purpose:  Checks Controller-Error-State (Only errors, not warnings.)
Input:    None
Returns:  CAN_OK or CAN_CTRLERROR
**************************************************************************/
uint8_t CAN_checkError(void)
{
	uint8_t eflg = mcp2515_readRegister(MCP_EFLG);

	if ( eflg & MCP_EFLG_ERRORMASK ) {
		return CAN_CTRLERROR;
	}
	else{
		return CAN_OK;
	}
}
