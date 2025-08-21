/*
 * 0821.c
 *
 * Created: 2025-08-21 오전 9:21:09
 * Author : COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRE = 0x01;
    while (1) 
    {	
		PORTE = 0x01;		// 릴레이 on -> FAN 구동
		_delay_ms(5000);
		PORTE = 0x00;		// 릴레이 off -> FAN 정지
		_delay_ms(5000);
    }
}

