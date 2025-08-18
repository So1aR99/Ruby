/*
 * TimerFnd.c
 *
 * Created: 2025-08-18 오후 1:08:11
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char Font[18] =
{
	0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
	0x7c, 0x07, 0x7f, 0x67, 0x77, 0x7c,
	0x39, 0x5e, 0x79, 0x71, 0x08, 0x80
};

void Segment(int);

int t_cnt = 0, m_cnt = 0;
volatile unsigned char STOP = 0;

void Segment(int N)
{
	int i;
	unsigned char N1000, N100, N10, N1;
	int Buff;
	
	N1000 = N / 1000;
	Buff = N % 1000;
	
	N100 = Buff / 100;
	Buff = Buff % 100;
	
	N10 = Buff / 10;
	N1 = Buff % 10;
	
	for(i=0; i<30; i++) {
		PORTC = 0x0e;			// 왼쪽 첫 번째 세그먼트
		PORTA = Font[N1000];	// 천의 자리 숫자 출력
		_delay_ms(1);
		
		PORTC = 0x0d;			// 왼쪽 두 번째 세그먼트
		PORTA = Font[N100];		// 백의 자리 숫자 출력
		_delay_ms(1);
		
		PORTC = 0x0b;			// 왼쪽 세 번째 세그먼트
		PORTA = Font[N10];		// 십의 자리 숫자 출력
		_delay_ms(1);
		
		PORTC = 0x07;			// 왼쪽 네 번째 세그먼트
		PORTA = Font[N1];		// 일의 자리 숫자 출력
		_delay_ms(1);
	}
}

ISR(TIMER2_OVF_vect){
	cli();
	TCNT2 = 112;
	t_cnt++;
	if(t_cnt >= 200){
		if(STOP == 0){
			t_cnt = 0;
			m_cnt++;
		}
		t_cnt = 0;
	}
	sei();
}

ISR(INT0_vect){
	cli();
	if(STOP == 0) STOP = 1;
	else STOP = 0;
	sei();
}

int main(void)
{
	DDRA = 0xff;
	DDRC = 0x0f;
	PORTA = 0xff;
	PORTC = 0x0f;
	ASSR = 0;
	TCCR2 = 0x04;		// 14745600/64 = 230,400 1/230400 = 4.34us 256-112 = 144
	TIMSK = 0x40;
	TCNT2 = 112;		// 0.000625s -> 0.625ms
	TIFR = 0;
	
	EICRA = (ISC01<< 1 | ISC00 << 1);		// 외부 인터럽트
	EIMSK = 1 << INT0;
	DDRD = 0x00;

	sei();

	while(1)
	{
		Segment(m_cnt);
	
	}
	return 0 ;
}