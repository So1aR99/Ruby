#include <stdio.h>
#include<avr/io.h>              //인터럽트 헤더 파일
#include<avr/interrupt.h>       //인터럽트 헤더 파일
#include<util/delay.h>          //딜레이 헤더 파일
#define LCD_WDATA PORTC         //LCD데이터 포트 정의
#define LCD_WINST PORTC
#define LCD_CTRL PORTB          //LCD 제어 포트 정의
#define LCD_EN 2                //LCD 제어(PING0~2) 정의
#define LCD_RW 1
#define LCD_RS 0
#define Byte unsigned char // Byte 선언
#define On 1
#define Off 0

void PortInit(void)
{
	DDRC = 0xFF;		// 출력
	DDRB = 0x0F;
}

void LCD_Data(Byte ch)
{
	LCD_CTRL |=  (1 << LCD_RS);     //RS=1, R/W=0 으로 데이터 쓰기 싸이클
	LCD_CTRL &= ~(1 << LCD_RW);
	LCD_CTRL |=  (1 << LCD_EN);     //LCD 사용
	_delay_us(50);
	LCD_WDATA = ch;                 //데이터 출력
	_delay_us(50);
	LCD_CTRL &= ~(1 << LCD_EN);     //LCD 사용안함
}

//   0    1     2
void LCD_Comm(Byte ch)     //PG0-EN , PG1-RW, PG2-RS , PG4-TOSC1핀(사용안함)
{
	LCD_CTRL &= ~(1 << LCD_RS);     //LCD_CTRL = LCD제어 포트(4핀인데 실질적인 사용3핀)
	LCD_CTRL &= ~(1 << LCD_RW);     // RS=0, RW=0 으로 정의함.
	LCD_CTRL |=  (1 << LCD_EN);     //LCD 사용허가
	_delay_us(50);
	LCD_WINST = ch;                 //명령어 쓰기
	_delay_us(50);
	LCD_CTRL &= ~(1 << LCD_EN);		// LCD 사용안함
}
void LCD_CHAR(Byte c)     //한문자 출력 함수
{
	LCD_Data(c); //CGRAM 문자코드값 0x31 ~ 0x5F : 0xDF코드표와 일치함
	_delay_ms(1);
}

void LCD_STR(Byte *str)     // 1칸씩 출력하는 반복처리 함수로 전달
{
	while(*str != 0)
	{
		LCD_CHAR(*str);
		str++;
	}
}

void LCD_pos(unsigned char col, unsigned char row) //LCD 포지션 설정
{
	LCD_Comm(0x80 | (row+col*0x40)); // row*0~8 / col*0, DDRAM주소설정
}

void LCD_Clear(void) // 화면 클리어
{
	LCD_Comm(0x01);
	_delay_ms(2); //1.6ms이상 실행시간으로 딜레이필요
}

void LCD_Init(void) //LCD 초기화
{
	LCD_Comm(0x38); //8비트 데이터 사용, 5X7도트 , LCD2줄 사용(6)
	_delay_ms(2);
	LCD_Comm(0x38); //8비트 데이터 사용, 5X7도트 , LCD2줄 사용(6)
	_delay_ms(2);
	LCD_Comm(0x38); //8비트 데이터 사용, 5X7도트 , LCD2줄 사용(6)
	_delay_ms(2);
	LCD_Comm(0x0E); //Display ON/OFF
	_delay_ms(2);
	LCD_Comm(0x06); //주소 +1, 커서를 우측으로 이동 (3)
	_delay_ms(2);
	LCD_Clear();
}

int main()
{
	/*
	Byte str1[] = "Atmega_128";
	Byte str2[] = "daedmail";
	
	PortInit();
	LCD_Init();

	LCD_pos(0,0);
	LCD_STR(str1);

	LCD_pos(1,0);
	LCD_STR(str2);
	*/
	
	Byte gugu[16];

	PortInit();
	LCD_Init();
	while(1)
	{
		for(int dan=2; dan<10; dan++){
			for(int i=1; i<10; i++){
				sprintf((char*)gugu, "%d * %d = %2d", dan, i, dan*i);
				LCD_pos(0,0);
				LCD_STR(gugu);
				_delay_ms(500);
			}
		}
	}
	
}