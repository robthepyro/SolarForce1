/*

  main.c 
  
  Hello World for ATMEGA Controller

  Universal 8bit Graphics Library
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "u8glib/src/u8g.h"

#define F_CPU	16000000

#define GFX_CS_PORT PORTD
#define GFX_CS_DDR  DDRD
#define GFX_CS_BIT  PD3


#define GFX_SELECT() 	( GFX_CS_PORT |=  (1<<GFX_CS_BIT) )
#define GFX_UNSELECT()  ( GFX_CS_PORT &= ~(1<<GFX_CS_BIT) )

// Standard AVR includes
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

#include <stdio.h>
#include <stdlib.h>


#if defined(__AVR__)
#include <avr/interrupt.h>
#include <avr/io.h>
#endif


/* 
  Software SPI:
  uint8_t u8g_InitSPI(u8g_t *u8g, u8g_dev_t *dev, uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t a0, uint8_t reset); 

  Hardware SPI:
  uint8_t u8g_InitHWSPI(u8g_t *u8g, u8g_dev_t *dev, uint8_t cs, uint8_t a0, uint8_t reset);

  Parallel Interface:
  uint8_t u8g_Init8Bit(u8g_t *u8g, u8g_dev_t *dev, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, 
    uint8_t en, uint8_t cs1, uint8_t cs2, uint8_t di, uint8_t rw, uint8_t reset);

  Visit 
    http://code.google.com/p/u8glib/wiki/device 
  for a list of valid devices (second argument of the constructor).

  The following examples will use the dogm132 device: u8g_dev_st7565_dogm132_sw_spi

  Note: The device must match the setup: For example, do not use a sw_spi device with u8g_InitHWSPI().
*/

u8g_t u8g;

void GFX_LCD_u8g_setup(void)
{  
  /*
    Test Envionment 1, ATMEGA and DOGM132 
    CS: PORTB, Bit 2
    A0: PORTB, Bit 1
    SCK: PORTB, Bit 5
    MOSI: PORTB, Bit 3
  */
  //u8g_InitSPI(&u8g, &u8g_dev_st7565_dogm132_sw_spi, PN(1, 5), PN(1, 3), PN(1, 2), PN(1, 1), U8G_PIN_NONE);

  /*
    Test Envionment 2, ATMEGA and Seeedstudio 96x96 OLED via I2C
    SCL: Port C, Bit 5
    SDA: Port C, Bit 4
  */
  
  /* activate pull-up, set ports to output, init U8glib */  
  //u8g_SetPinInput(PN(2,5)); u8g_SetPinLevel(PN(2,5), 1); u8g_SetPinOutput(PN(2,5));
  //u8g_SetPinInput(PN(2,4)); u8g_SetPinLevel(PN(2,4), 1); u8g_SetPinOutput(PN(2,4));
  //u8g_InitI2C(&u8g, &u8g_dev_ssd1327_96x96_gr_i2c, U8G_I2C_OPT_NONE);
  //u8g_InitI2C(&u8g, &u8g_dev_ssd1306_128x64_i2c, U8G_I2C_OPT_NONE);
  

  /*
    Test Envionment 3, ATMEGA and NHD 192x32 ST7920 special SPI
    R/W, MOSI, Red: 	Port C, Bit 5
    RS, CS, Yellow: 	Port C, Bit 4
    EN, SCK, Green:	Port C, Bit 3
    Arguments for u8g_InitSPI are: SCK, MOSI, CS, A0, Reset
      A0 and Reset are not used.
  */
   //u8g_InitSPI(&u8g, &u8g_dev_st7920_128x64_sw_spi, PN(2, 0), PN(2, 1), PN(2, 2), U8G_PIN_NONE, U8G_PIN_NONE);
   u8g_InitHWSPI(&u8g, &u8g_dev_st7920_128x64_hw_spi, PN(3, 7), U8G_PIN_NONE, U8G_PIN_NONE);
   u8g_Begin(&u8g);
   //u8g_Init8Bit(&u8g, &u8g_dev_ks0108_128x64, PN(1, 2), PN(1, 1), PN(1, 0), PN(3, 7), PN(3, 6), PN(3, 5), PN(3, 4), PN(3, 3), PN(2, 5), PN(2, 1), PN(2, 0), PN(2,2), PN(2, 3), U8G_PIN_NONE);


  
}

void sys_init(void)
{
#if defined(__AVR__)
  /* select minimal prescaler (max system speed) */
  CLKPR = 0x80;
  CLKPR = 0x00;
#endif
}

void u8g_prepare(void) {
  u8g_SetFont(&u8g, u8g_font_6x10);
  u8g_SetFontRefHeightExtendedText(&u8g);
  u8g_SetDefaultForegroundColor(&u8g);
  u8g_SetFontPosTop(&u8g);
}

void u8g_box_frame(uint8_t a) {
  u8g_DrawStr(&u8g, 0, 0, "drawBox");
  u8g_DrawBox(&u8g, 5,10,20,10);
  u8g_DrawBox(&u8g, 10+a,15,30,7);
  u8g_DrawStr(&u8g, 0, 30, "drawFrame");
  u8g_DrawFrame(&u8g, 5,10+30,20,10);
  u8g_DrawFrame(&u8g, 10+a,15+30,30,7);
}

void u8g_string(uint8_t a) {
  u8g_DrawStr(&u8g, 30+a,31, " 0");
  u8g_DrawStr90(&u8g, 30,31+a, " 90");
  u8g_DrawStr180(&u8g, 30-a,31, " 180");
  u8g_DrawStr270(&u8g, 30,31-a, " 270");
}

void u8g_line(uint8_t a) {
  u8g_DrawStr(&u8g, 0, 0, "drawLine");
  u8g_DrawLine(&u8g, 7+a, 10, 40, 55);
  u8g_DrawLine(&u8g, 7+a*2, 10, 60, 55);
  u8g_DrawLine(&u8g, 7+a*3, 10, 80, 55);
  u8g_DrawLine(&u8g, 7+a*4, 10, 100, 55);
}

void u8g_ascii_1(void) {
  char s[2] = " ";
  uint8_t x, y;
  u8g_DrawStr(&u8g, 0, 0, "ASCII page 1");
  for( y = 0; y < 6; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 32;
      u8g_DrawStr(&u8g, x*7, y*10+10, s);
    }
  }
}

void u8g_ascii_2(void) {
  char s[2] = " ";
  uint8_t x, y;
  u8g_DrawStr(&u8g, 0, 0, "ASCII page 2");
  for( y = 0; y < 6; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 160;
      u8g_DrawStr(&u8g, x*7, y*10+10, s);
    }
  }
}


uint8_t draw_state = 0;

void draw(void) {
	  u8g_prepare();
	  switch(draw_state >> 3) {
	    case 0: u8g_box_frame(draw_state&7); break;
	    case 1: u8g_string(draw_state&7); break;
	    case 2: u8g_line(draw_state&7); break;
	    case 3: u8g_ascii_1(); break;
	    case 4: u8g_ascii_2(); break;
	  }
}

int main(void)
{
	GFX_SELECT();
  sys_init();
  GFX_LCD_u8g_setup();

  for(;;)
  {  
    u8g_FirstPage(&u8g);
    do
    {
      draw();
    } while ( u8g_NextPage(&u8g) );

    draw_state++;
    if ( draw_state >= 5*8 )
      draw_state = 0;

    u8g_Delay(150);
  }
}
