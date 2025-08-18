/*
 * Int.c
 *
 * Created: 2025-08-13 오후 1:26:47
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char Font[10] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 
	0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	
unsigned char count = 0;
	
ISR(INT4_vect)
{
	count++;
	if (count > 9) {
		count = 0;
	}
	PORTA = Font[count];
	_delay_ms(10);
	
}

int main(void)
{
	DDRA = 0xff;		// LED
	DDRD = 0x00;		// push 입력
	DDRG = 0xff;
	PORTG = 0x07;		// FND첫번째 자리
	
	//EICRA = ( ISC01 = 1 | ISC00 = 1 );
	//EICRA = ( 1 << ISC01 | 1 << ISC00 );
	//EIMSK = 1 << INT0;
	
	EICRB = ( 1 << ISC41 | 1 << ISC40 );
	EIMSK = 1 << INT4;
	
	sei();
	
	PORTA = Font[0];
	
    while (1) 
    {
    }
}

