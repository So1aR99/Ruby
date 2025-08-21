/*
 * StepMotor1.c
 *
 * Created: 2025-08-21 오전 9:44:37
 *  Author: COMPUTER
 스테핑 모터제어 2상여자 방식
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i;
	DDRB = 0x0f;
	while(1)
	{
		for(i=0; i<12; i++){
			PORTB = 0x03;
			_delay_ms(10);
			PORTB = 0x09;
			_delay_ms(10);
			PORTB = 0x0C;
			_delay_ms(10);
			PORTB = 0x06;
			_delay_ms(10);
		}
		_delay_ms(5000);
	}
}