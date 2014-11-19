/*
 * Tutorial1_LED.c
 *
 * Created: 19.11.2014 23:42:21
 *  Author: Elman
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xFF; // DDRB_1 - OUT
	PORTB = 0x00; // level on Port B(0) - 0 
	while(1)
    {
        PORTB = 0x01;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);		
    }
}