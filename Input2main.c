/*
 * Input2.c
 *
 * Created: 2025-08-12 오후 4:25:43
 * Author : COMPUTER
 */
//1번버튼 누르면 1씩 증가 0번버튼 누르면 초기화

#include <avr/io.h>
#include <util/delay.h>

unsigned char Font[10] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66,
	0x6D, 0x7D, 0x07, 0x7F, 0x6F };

int main(void)
{
	DDRE = 0xff;		// 출력포트로 사용, 1출력
	DDRD = 0x00;		// 입력포트로 사용, 0입력
	DDRG = 0x01;
	

	unsigned char count = 0;
	PORTE = Font[count];
	    
    while (1) 
    {
		if(PIND == 0x01){
			count++;
			PORTE = Font[count];
			_delay_ms(200);
		}
		if(PIND == 0x80){
			PORTE = Font[0];
			count = 0;
		}
    }
}

