/*
 * Lesson3_7Segment.c
 *
 * Created: 21.11.2014 21:33:36
 *  Author: Elman
 */

// Sample details http://avr-start.ru/?p=435

#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char Digits[] = 
{
	0x3F, // "0"
	0x06, // "1"
	0x5B, // "2"
	0x4F, // "3"
	0x66, // "4"
	0x6D, // "5"
	0x7D, // "6"
	0x07, // "7"
	0x7F, // "8"
	0x6F, // "9"	
};
char Dot = 0x80; // "dot"
char counter = 0;

void initController()
{
	DDRB = 0xFF;
	PORTB = 0xFF;
}

void initTimer()
{
	// работаем с таймером T/C 1
	TIMSK = (1 << TOIE1); // прерывания по overflow
	TCNT1 = 34285;	// начинаем счет
	TCCR1B = (1 << CS12);	// делитель 256 f => clk(I/O)/256
	
}

ISR (TIMER1_OVF_vect)
{
	TCNT1 = 34285;
	counter++;
	if (counter == 10) counter = 0;
	PORTB = ~Digits[counter];
}

int main(void)
{
	initController();
	initTimer();
	sei();
	while(1){};
}