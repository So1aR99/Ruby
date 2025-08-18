/*
 * Fnd2.c
 *
 * Created: 2025-08-12 오전 10:39:31
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned char Font[18] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
	0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71 }; 
// A 0111 0111 B 0111 1111 C 0011 1001 D 0011 1111 E 0111 1001 F 0111 0001

int main(void)
{
	DDRB = 0xff;
	DDRG = 0xff;
//	PORTG = 0x00;
    while (1) 
    {
		PORTG = 0x0E;	 // 0000 1110
		PORTB = Font[10];
		_delay_ms(1);
		PORTG = 0x0D;    // 0000 1101
		PORTB = Font[11];
		_delay_ms(1);
		PORTG = 0x0B;    // 0000 1011
		PORTB = Font[12];
		_delay_ms(1);
		PORTG = 0x07;    // 0000 0111
		PORTB = Font[13];
		_delay_ms(1);

	/*	for (int i=0; i<17; i++){
			PORTB = Font[i];
			_delay_ms(500);
		}*/
	/*	PORTB = Font[0];
		_delay_ms(500);
		PORTB = Font[1];
		_delay_ms(500);
		PORTB = Font[2];
		_delay_ms(500);
		PORTB = Font[3];
		_delay_ms(500);
		PORTB = Font[4];
		_delay_ms(500);
		PORTB = Font[5];*/
    }
	return 0;
}

