/*
 * 0820.c
 *
 * Created: 2025-08-20 오전 9:23:00
 * Author : COMPUTER
 14번모드
 LED 밝기조절 : 1번버튼 듀티비 20% 2번버튼 40% 3번버튼 60% 4번버튼 80% 5번버튼 100%
 100hz= 14.4k(1+Top) Top = 143 탑값 20% = 28.6 40% = 57.2
OCnx
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	DDRB = 0x20;		// LED 출력 (PB5)

	DDRD = 0xc0;
	PORTD = 0x3f;

	// 타이머1 Fast PWM, mode 14, 비반전 모드, 분주 8
	TCCR1A = 0x82;
	TCCR1B = 0x1a;

	ICR1 = 143;  // TOP 값 설정

	OCR1A = 0;  // 초기 듀티 0%

	sei(); 

	while(1) {
		if ((PIND & (1 << PD0))) {  
			OCR1A = 28; // 20% 밝기
			_delay_ms(50);  // 디바운스용 딜레이
		}
		else if ((PIND & (1 << PD1))) {  // 2번 버튼 눌림
			OCR1A = 57; // 40% 밝기
			_delay_ms(50);
		}
		else if ((PIND & (1 << PD2))) {  // 3번 버튼 눌림
			OCR1A = 86; // 60% 밝기
			_delay_ms(50);
		}
		else if ((PIND & (1 << PD3))) {  // 4번 버튼 눌림
			OCR1A = 114; // 80% 밝기
			_delay_ms(50);
		}
		else if ((PIND & (1 << PD4))) {  // 5번 버튼 눌림
			OCR1A = 143; // 100% 밝기
			_delay_ms(50);
		}
		else {
			OCR1A = 0;  // 버튼 안 눌림 -> LED 끄기
		}
	}
}

