/*
 * Input.c
 *
 * Created: 2025-08-12 오후 2:09:41
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

unsigned char Font[18] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
	0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71 };

int main(void)
{
    DDRE = 0xff;		// 출력포트로 사용, 1출력
	DDRD = 0x00;		// 입력포트로 사용, 0입력
	DDRG = 0x01;
	
	unsigned char save = 0x00;
	
    while (1) 
    {
		//PORTE = PIND;		// 포트D에 들어오는 입력값을 포트E의 출력, 풀다운저항: 평상시 0 누르면 1, 풀업저항: 평상시 1 누르면 0
		
		unsigned char now = PIND;
		
		if(now != save){
		if(now == 0x00){
			PORTE = Font[0];
		}
		else if( now == 0x01){
			PORTE = Font[1];
		}
		else if( now == 0x02){
			PORTE = Font[2];
		}
		else if( now == 0x04){
			PORTE = Font[3];
		}
		else if( now == 0x08){
			PORTE = Font[4];
		}
		else if( now == 0x10){
			PORTE = Font[5];
		}
		else if( now == 0x20){
			PORTE = Font[6];
		}
		else if( now == 0x40){
			PORTE = Font[7];
		}
		else if ( now == 0x80){
			PORTE = Font[8];
		}
		else {
			PORTE = 0x00;
		}
	}
	}
}

