/*
 * StepMotor.c
 *
 * Created: 2025-08-21 오전 9:40:23
 *  Author: COMPUTER
 스테핑 모터제어 1상여자 방식
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int i = 0;
	DDRB = 0x0f;
	while(1)
	{
		for(i=0; i<36; i++){		// 시계방향으로 3바퀴 회전
			PORTB = 0x08;			// 한주기 4개 12주기 1바퀴
			_delay_ms(10);
			PORTB = 0x04;
			_delay_ms(10);
			PORTB = 0x02;
			_delay_ms(10);
			PORTB = 0x01;
			_delay_ms(10);
		}

		_delay_ms(2000);			// 2초정지후
		
		for(i=0; i<36; i++){		// 반시계방향으로 회전
			PORTB = 0x01;
			_delay_ms(10);
			PORTB = 0x02;
			_delay_ms(10);
			PORTB = 0x04;
			_delay_ms(10);
			PORTB = 0x08;
			_delay_ms(10);
		}
		_delay_ms(2000);
	}
}