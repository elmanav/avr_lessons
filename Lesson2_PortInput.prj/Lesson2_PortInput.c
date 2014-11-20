/*
 * Lesson2_PortInput.c
 *
 * Created: 20.11.2014 21:37:06
 *  Author: Elman
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0x01;	// PortB_0 - OUT, PortB_1 - IN
	PORTB = 0x02;	// Port B(0) - level "0"; Port B(1) - pull resist
	
	while(1)
	{
		int i = PINB;
		if (!(i & (1<<PINB1)))
		{
			PORTB |= (1<<0);
			_delay_ms(1000);
			PORTB &= ~(1<<0);
			_delay_ms(1000);
		}
	}
}