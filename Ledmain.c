/*
 * Led.c
 *
 * Created: 2025-08-11 오후 2:28:21
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRE = 0xff;		// DDRE(방향설정 레지스트: 1 출력, 0 입력) = 1111 1111
	DDRA = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
	DDRF = 0xff;
	DDRG = 0xff;
    while (1) 
    {
		PORTB = 0xff;
		_delay_ms(500);
		PORTB = 0x00;
		_delay_ms(500);
    }
}

