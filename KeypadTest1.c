/*
 * KeypadTest1.c
 *
 * Created: 2025-08-21 오후 3:30:28
 *  Author: COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd/lcd.h"

#define ROWS	4		// 행(입력)
#define COLS	3		// 열(출력)

void keypad_Init()
{
	DDRD = 0xf0;		// 상위 4비트 출력, 하위 4비트 입력
}

char keypad_getkey(){
	PORTD = 0x10;
	_delay_us(5);
	if((PIND & 0x01) == 0x01) return '1';
	if((PIND & 0x02) == 0x02) return '4';
	if((PIND & 0x04) == 0x04) return '7';
	if((PIND & 0x08) == 0x08) return '*';
	
	PORTD = 0x20;
	_delay_us(5);
	if((PIND & 0x01) == 0x01) return '2';
	if((PIND & 0x02) == 0x02) return '5';
	if((PIND & 0x04) == 0x04) return '8';
	if((PIND & 0x08) == 0x08) return '0';
		
	PORTD = 0x40;
	_delay_us(5);
	if((PIND & 0x01) == 0x01) return '3';
	if((PIND & 0x02) == 0x02) return '6';
	if((PIND & 0x04) == 0x04) return '9';
	if((PIND & 0x08) == 0x08) return '#';
	
	return 0;
}

int main(void)
{
	
	Byte str[] = "Keypad Test";
	char key = 0;
	Port_Init();
	LCD_Init();
	keypad_Init();
	
	LCD_pos(0, 0);
	LCD_STR(str);
	
	while(1)
	{
		 char newkey = keypad_getkey();
		 if(newkey != 0) key = newkey;
		 _delay_ms(10);
		 LCD_pos(1, 0);
		 LCD_CHAR(key);
	}
	return 0;
}
