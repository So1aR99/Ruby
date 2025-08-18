/*
 * FastPWM.c
 *
 * Created: 2025-08-18 오후 3:19:07
 *  Author: COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char Font[18] = {
	0x3F, 0X06, 0X5B, 0X4F,
	0X66, 0X6D, 0X7C, 0X07,
	0X7F, 0X67, 0X77, 0X7C,
	0X39, 0X5E, 0X79, 0X71,
	0X08, 0X80};

void RSegment(int);
void LSegment(int); // Segment 함수 선언

int tr_cnt = 0,mr_cnt=0;
int tl_cnt =0 ,ml_cnt = 0;

void RSegment ( int N )
{
	int i;
	unsigned char N10, N1;
	N10 = N / 10; // 세그먼트에서 사용하는 십의 자리 추출
	N1 = N % 10; // 세그먼트에서 사용하는 일의 자리 추출
	for( i = 0; i < 5; i++ ) {
		PORTC = 0x0b; // 왼쪽 세 번째 세그먼트 ON
		PORTA = Font[N10]; // 십의 자리 숫자를 출력해 준다
		_delay_ms(1);
		PORTC = 0x07; // 왼쪽 네 번째 세그먼트 ON
		PORTA = Font[N1]; // 일의 자리 숫자를 출력해 준다
		_delay_ms(1);
	}
}

void LSegment ( int N )
{
	int i;
	unsigned char N10, N1;
	N10 = N /10; // 세그먼트에서 사용하는 십의 자리 추출
	N1 = N % 10; // 세그먼트에서 사용하는 일의 자리 추출
	for( i = 0; i < 5; i++ ) {
		PORTC = 0x0e; // 왼쪽 세 번째 세그먼트 ON
		PORTA = Font[N10]; // 십의 자리 숫자를 출력해 준다
		_delay_ms(1);
		PORTC = 0x0d; // 왼쪽 네 번째 세그먼트 ON
		PORTA = Font[N1]; // 일의 자리 숫자를 출력해 준다
		_delay_ms(1);
	}
}

ISR(TIMER0_OVF_vect)
{
	tr_cnt++;
	if(tr_cnt >= 56){
		tr_cnt = 0;
		mr_cnt++;
		if(mr_cnt > 99) mr_cnt = 0;
	}
}

ISR(TIMER0_COMP_vect)
{
	tl_cnt++;
	if(tl_cnt >= 28){
		tl_cnt = 0;
		ml_cnt++;
		if(ml_cnt > 99) ml_cnt = 0;
	}
}

int main(void)
{
	DDRA = 0xff;
	DDRC = 0xff;
	PORTA = 0xff;
	PORTC = 0x0f;
	
	DDRB = 0x10;		// PB4를 출력으로 설정
	ASSR = 0;
	
	/*
	Fast PWM, OC0 => 비 반전 Mode
	1024 분주 ==> 14.4 KHz : 0.0000694444 [sec] */
	TCCR0 = 0x6f;
	TIMSK = 0x03;		// 오버플로, 출력비교 인터럽트 2개 다 사용함
	TCNT0 = 0x00;
	OCR0 = 102;			// 0.0000694444 [sec] * 102 가 PWM ON 타임 102 * 69.44 us = 7.08ms
	TIFR = 0;
	
	sei();
	
	while(1){
		LSegment(ml_cnt);
		RSegment(mr_cnt);
	}
	return 0;
}