/*
 * Timer3.c
 *
 * Created: 2025-08-19 오전 10:25:15
 * Author : COMPUTER
  1초마다 2진카운터 1씩증가하며 LED에 점등
 */

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int t_cnt = 0, m_cnt = 0;

void LED(int N)
{
	PORTA = N;
}

ISR(TIMER3_OVF_vect)
{
	TCNT3H = 0xf4;
	TCNT3L = 0xc0;
	t_cnt++;
	if(t_cnt >= 5){
		t_cnt = 0;
		m_cnt++;
		if(m_cnt > 255)
			m_cnt = 0;
	}
}

int main(void)
{
	DDRA = 0xff;
	PORTA = 0xff;
	
	ASSR = 0;
	TIMSK = 0x00;
	ETIMSK = 0x04;
	TCCR3A = 0;
	TCCR3B = 0x05;		// 분주비 1024
	TCNT3H = 0xf4;
	TCNT3L = 0xc0;
	TIFR = 0;
	ETIFR = 0;
	
	sei();
	
    while (1) 
    {
		LED(m_cnt);
    }
}

