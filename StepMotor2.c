/*
 * StepMotor2.c
 *
 * Created: 2025-08-21 오전 9:44:37
 *  Author: COMPUTER
 스테핑 모터제어 1-2상여자 방식
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

unsigned char Step[8] = {
	0x09, 0x08, 0x0c, 0x04, 
	0x06, 0x02, 0x03, 0x01};

int main(void)
{
	int i = 0, t = 0;
	DDRB = 0x0f;
	while(1)
	{
		for (i=0; i<24; i++)
		{
			PORTB = Step[t];
			t = t + 1;
			if(t > 7) t = 0;
			_delay_ms(10);
		}
		_delay_ms(1000);
	}
}