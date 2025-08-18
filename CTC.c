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


ISR(TIMER2_COMP_vect){
	t_cnt++;
	if(t_cnt >= 100){
		m_cnt++;
		t_cnt = 0;
	}
}

int main(void)
{
	// 포트G를 7-세그먼트 Common 단자로 사용하기 위해 출력으로 설정한다
	DDRA = 0xff;
	DDRC = 0xff;
	PORTA = 0xff;
	PORTC = 0x0f;
	ASSR = 0; // 내부 클럭을 사용한다
	TCCR2 = 0x0d; // 1024 분주 ==> 14.7456 KHz:
	TIMSK = 0x80; // 출력 비교 인터럽트 OCIE2 = 1
	/* TCNT2는 값을 안써주어도 상관없다
	TCNT2의 값이 144개 변하면 인터럽트가 발생하도록 하기 위해서는
	OCR2를 144으로 써 넣어 주어야 한다.
	단, 주의 할 점은 초기화 할때 TCNT2의 값과 OCR2의 값을 다르게 넣어
	주어야 한다. */
	TCNT2 = 0x00;
	OCR2 = 144; // 0.0000694444 [sec] * 144 = 9.999 msec 주기
	TIFR = 0;
	sei();

	while(1)
	{
		Segment(m_cnt);
	
	}
	return 0 ;
}