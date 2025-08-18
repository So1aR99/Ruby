/*
 * Fnd3.c
 *
 * Created: 2025-08-12 오후 1:22:04
 * Author : COMPUTER
 1~9999까지 출력
 */


 

#include <avr/io.h>
#include <util/delay.h>

unsigned char Font[18] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
	0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71 };
	
	void display_digit(unsigned int digit, unsigned char pos)
	{
		// digit: 0~9, pos: 0~3 (자리 위치)
		PORTB = Font[digit];  // 세그먼트 출력
		PORTG = ~(1 << pos);  // 해당 자리만 켬 (common 핀 낮음 활성일 경우)
		_delay_ms(2);         // 짧은 지연 (멀티플렉싱)
		PORTG = 0xFF;         // 모두 끔 (잔상 방지)
	}

	int main(void)
	{
		DDRB = 0xFF;  // PORTB 출력 설정 (세그먼트)
		DDRG = 0xFF;  // PORTG 출력 설정 (자리 선택)

		unsigned int num = 1;

		while(1)
		{
			// 1부터 9999까지 증가, 9999 넘으면 다시 1로
			if (num > 9999) num = 1;

			// 숫자 각 자리 분리
			unsigned int thousands = num / 1000;
			unsigned int hundreds = (num / 100) % 10;
			unsigned int tens = (num / 10) % 10;
			unsigned int ones = num % 10;

			// 4자리 각각 디스플레이
			// 1자리씩 빠르게 점멸시켜 멀티플렉싱 효과
			for (int i = 0; i < 100; i++) // 이 루프로 멀티플렉싱 지속
			{
				if(thousands != 0)
				display_digit(thousands, 3);
				else
				PORTG = 0xFF; // 0 자리이면 표시 안 함 (빈 자리)

				display_digit(hundreds, 2);
				display_digit(tens, 1);
				display_digit(ones, 0);
			}

			num++;
		}
	}
	
/*
int main(void)
{
	DDRB = 0xff;
	DDRG = 0xff;
    while (1) 
    {
		for(int i=0; i<10; i++){
			PORTG = 0x07;
			PORTB = Font[i];
			_delay_ms(100);
		}
		for(int j=0; j<10; j++){
			PORTG = 0x0B;
			PORTB = Font[1];
			_delay_ms(1);
			PORTG = 0x07;
			PORTB = Font[j];
			_delay_ms(100);
		}	
	}
		
}

