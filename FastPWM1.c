/*
 * FastPWM1.c
 *
 * Created: 2025-08-18 오후 4:17:40
 *  Author: COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int Duty = 0;
	DDRB = 0x80; // PB7을 출력으로 설정한다.
	ASSR = 0; // 내부 클럭을 사용한다
	/* Fast PWM, OC0 =>비 반전 Mode
	1024 분주 ==> 14.4 KHz */
	TCCR2 = 0x6d;
	TIMSK = 0x00; // 인터럽트를 사용하지 않는다
	TCNT2 = 0x00;
	OCR2 = 0; //초기 Duty 비를 0 으로 설정
	TIFR = 0;
	// PWM 듀티비가 0% ∼ 100% 까지 변하도록 한다.
	while(1) {
		_delay_ms(100);
		Duty++;
		if(Duty > 255) Duty = 0;
		OCR2 = Duty;
	}
	
	return 0;
}