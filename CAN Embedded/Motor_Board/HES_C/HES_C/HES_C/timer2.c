/*
 * timer2.c
 *
 * Created: 19/04/2015 02:58:10 AM
 *  Author: Terayza
 */ 

// For aTmega328p

#include "timer2.h"

//timer0 overflow
ISR(TIMER2_OVF_vect)
{
	TCNT2 = TIMEBASE_RELOAD2; //reload timer
	//timer will be reloaded to the highest value(overflow value) - 0.5ms
	count2++;
}

//timer2 setup
void timer2_init(void)
{
	// set the timer to overflow ever 1mS
	TCCR2B = (1<<CS22) | (0<<CS21) | (0<<CS20); // prescaler: 64
	TCNT2 = TIMEBASE_RELOAD2; // set initial reload-value
	TIFR2  |= (1<<TOV2);  // clear overflow int.
	TIMSK2 |= (1<<TOIE2); // enable overflow-interrupt
}


