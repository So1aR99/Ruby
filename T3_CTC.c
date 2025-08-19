/*
 * T3_CTC.c
 *
 * Created: 2025-08-19 오전 11:07:10
 *  Author: COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char Font[18] = {
	0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
	0X7C, 0X07, 0X7F, 0X67, 0X77, 0X7C,
	0X39, 0X5E, 0X79, 0X71, 0X08, 0X80};

void Segment(int) ; // Segment 함수 선언
int t_cnt = 0;

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

ISR(TIMER3_COMPA_vect)
{
	t_cnt++;
}

int main(void)
{
	// 포트 G를 7-세그먼트 Common 단자로 사용하기 위해 출력으로 설정
	DDRA = 0xff;
	DDRC = 0xff;
	PORTA = 0xff;
	PORTC = 0xff;
	ASSR = 0; // 내부 클럭을 사용한다
	TIMSK = 0x00;
	ETIMSK = 0x10; // 타이머/카운터 3의 출력비교 A 인터럽트 발생허용
	TCCR3A = 0;
	TCCR3B = 0x0d; // [표 10-2] 모드 4 (WGMn2 = 1), CLK /1024 
	OCR3AH = 0x1c;
	OCR3AL = 0x20;
	TIFR = 0;
	ETIFR = 0;
	
	sei();
	
	while(1)
	{
		Segment(t_cnt);	
	}
}
