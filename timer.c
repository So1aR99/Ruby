/*
 * Timer0Normal.c
 *
 * Created: 2025-08-18 오전 10:04:50
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

ISR(TIMER0_OVF_vect){
	cli();
	TCNT0 = 0xf2;
	t_cnt++;
	if(t_cnt >= 1000) {
		t_cnt = 0;
		m_cnt++;
	}	
	sei();
}

int main(void)
{	
	// 포트 C를 7-세그먼트 Common 단자로 사용하기 위해 출력으로 설정
	DDRA = 0xff;
	DDRC = 0x0f;
	PORTA = 0xff;
	PORTC = 0x0f;
	ASSR = 0;		// 디폴트 값, 내부 클럭 사용
	TCCR0 = 0x06;	// (111=7) 1024 분주, (110=6) 256 분주, 타이머/카운트 n (n에따라 분주비달라짐)
	TIMSK = 0x01;	// 타이머/카운터 0 인터럽트 사용
	TCNT0 = 0xf2;
	TIFR = 0;
	
	sei();
	
    while (1) 
    {
		Segment(m_cnt);
    }
}

