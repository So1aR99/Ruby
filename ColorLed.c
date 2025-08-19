/*
 * FullLed.c
 *
 * Created: 2025-08-19 오후 1:09:23
 * Author : COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xe0;
	
    while (1) 
    {
		PORTB = 0x00;		// Black
		_delay_ms(1000);
		
		PORTB = 0x80;		// Blue
		_delay_ms(1000);
		
		PORTB = 0x40;		// Green
		_delay_ms(1000);
		
		PORTB = 0xc0;		// Cyan
		_delay_ms(1000);
		
		PORTB = 0x20;		// Red
		_delay_ms(1000);
		
		PORTB = 0xa0;		// Magenta
		_delay_ms(1000);
		
		PORTB = 0x60;		// Yellow
		_delay_ms(1000);
		
		PORTB = 0xe0;		// White
		_delay_ms(1000);
    }
}

