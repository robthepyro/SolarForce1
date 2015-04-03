/*
 * GFX_LCD.h
 *
 *  Created on: 21 Mar 2015
 *      Author: RobThePyro
 */

#ifndef GFX_LCD_H_
#define GFX_LCD_H_

#include "../lib/u8glib/src/u8g.h"
#include "../lib/CAN/CAN.h" // CANMessage Struct?
#include <string.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

// Hardware:
#define GFX_CS_PORT PORTD
#define GFX_CS_DDR  DDRD
#define GFX_CS_BIT  PD3


#define GFX_SELECT() 	( GFX_CS_PORT |=  (1<<GFX_CS_BIT) )
#define GFX_UNSELECT()  ( GFX_CS_PORT &= ~(1<<GFX_CS_BIT) )

void u8g_setup();
void u8g_prepare();
void GFX_Cnt(int);
void GFX_LCD_Draw(CANMessage*);
void draw(CANMessage*);

#endif /* GFX_LCD_H_ */