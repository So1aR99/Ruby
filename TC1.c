/*
 * TC1.c
 *
 * Created: 2025-08-19 오후 2:44:48
 *  Author: COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char Font[18] = {
	0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
	0X7C, 0X07, 0X7F, 0X67, 0X77, 0X7C,
	0X39, 0X5E, 0X79, 0X71, 0X08, 0X80};

void Segment(int);
unsigned int m_cnt = 0;

void Segment ( int N )
{
	int i;
	unsigned char N1000, N100, N10, N1;
	int Buff;
	
	N1000 = N /1000; // 세그먼트에서 사용하는 천의 자리를 추출
	Buff = N % 1000;
	
	N100 = Buff / 100; // 세그먼트에서 사용하는 백의자리 추출
	Buff = Buff % 100;
	
	N10 = Buff /10; // 세그먼트에서 사용하는 십의 자리 추출
	N1 = Buff % 10; // 세그먼트에서 사용하는 일의 자리 추출

	for( i = 0; i < 30; i++ ) {
		PORTC = 0x0e; // 왼쪽 첫 번째 세그먼트 ON
		PORTA = Font[N1000]; // 천의 자리 숫자를 출력해 준다
		_delay_ms(1);
		
		PORTC = 0x0d; // 왼쪽 두 번째 세그먼트 ON
		PORTA = Font[N100]; // 백의 자리 숫자를 출력해 준다
		_delay_ms(1);
		
		PORTC = 0x0b; // 왼쪽 세 번째 세그먼트 ON
		PORTA = Font[N10]; // 십의 자리 숫자를 출력해 준다
		_delay_ms(1);
		
		PORTC = 0x07; // 왼쪽 네 번째 세그먼트 ON
		PORTA = Font[N1]; // 일의 자리 숫자를 출력해 준다
		_delay_ms(1);
	}
}

// 상승에지 마다 인터럽트가 발생한다
ISR(TIMER1_CAPT_vect)
{
	// 내부 카운터를 계수한 값이 있는 ICR1에서 값을 가져 온다.
	m_cnt = ICR1;
	TCNT1 = 0;	
}

int main(void)
{
	// 포트 C를 7-세그먼트 Common 단자로 사용하기 위해 출력으로 설정
	DDRA = 0xff;
	DDRC = 0x0f;
	PORTA = 0xff;
	PORTC = 0x0f;
	DDRB= 0x10; // PB4(OCR0)핀 출력 설정
	TCCR0 = 0x1E ; //CTC모드 256 분주, 토글이므로 50% 듀티비
	TCNT0 = 0;
	OCR0 =150; // 임의로 정하는 값이다
	TIMSK = 0x20; // 타이머 1 입력 캡쳐 인터럽트 인에이블
	// 타이머 1에서 계수하는 기준 펄스는 CLK/256 펄스로 한다.
	// 또한 PD4 핀의 상승에지에서 인터럽트를 발생시킨다
	TCCR1B = 0x44;
	
	sei();
	
	while(1)
	{
		Segment(m_cnt);
	}
}