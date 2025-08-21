/*
 * KeypadTest2.c
 *
 * Created: 2025-08-21 오후 3:43:03
 *  Author: COMPUTER
 4개 비밀번호 맞으면 led불키기
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd/lcd.h"

#define ROWS	4		// 행(입력)
#define COLS	3		// 열(출력)

char password[] = {'0', '1', '0', '5'};
char input_pass[4];
int save = 0;
Byte str1[] = "  Access!!";
Byte str2[] = "  Wrong!!!";
	
void keypad_Init()
{
	DDRD = 0xf0;		// 상위 4비트 출력, 하위 4비트 입력
}

void LCD_key(char key, int *i)					// 출력할 값 입력받고, 변수 i의 주소를 받아서 i의 값을 넣음
{	
	if(*i < 4)											// 포인터 변수를 사용해야 값 변경이 가능
	LCD_pos(1, *i);
	LCD_CHAR(key);
	(*i)++;										// i의 값이 1 증가
	_delay_ms(500);
	
	if(save < 4) {
		input_pass[save] = key;
		save++;
	}
	if(save == 4){
		if(password[0] == input_pass[0] &&
		password[1] == input_pass[1] &&
		password[2] == input_pass[2] &&
		password[3] == input_pass[3]) {
			PORTA = 0x01;
			LCD_pos(1, 0);
			LCD_STR("                ");
			LCD_pos(1, 0);
			LCD_STR(str1);
			_delay_ms(1000);
			LCD_pos(1, 0);
			LCD_STR("                ");
			LCD_pos(1, 0);
			save = 0;
			input_pass[4] = 0;
			_delay_ms(1000);
			PORTA = 0x00;
			
		}
		else if((password[0] != input_pass[0] ||
		password[1] != input_pass[1] ||
		password[2] != input_pass[2] ||
		password[3] != input_pass[3])) {
			LCD_pos(1, 0);
			LCD_STR("                ");
			LCD_pos(1, 0);
			LCD_STR(str2);
			_delay_ms(500);
			LCD_pos(1, 0);
			LCD_STR("                ");
			LCD_pos(1, 0);
			for(int a = 0; a<10; a++){
				PORTA = 0x01;
				_delay_ms(100);
				PORTA = 0x00;
				_delay_ms(100);
			}
			save = 0;
			input_pass[4] = 0;
			_delay_ms(1000);
			PORTA = 0x00;
			
		}
	}
}
		
int main(void)
{
	DDRA = 0x01;
	
	int i = 0;
	
	Byte str[] = "PassWord";
	
	
	Port_Init();
	LCD_Init();
	keypad_Init();
	
	LCD_pos(0, 0);
	LCD_STR(str);
	
	while(1)
	{
		PORTD = 0x10;		// 1열 검사
		_delay_us(5);
		if((PIND & 0x01) == 0x01) LCD_key('1', &i);			// i의 주소를 넘겨주어야 값 변경해서 사용가능
		if((PIND & 0x02) == 0x02) LCD_key('4', &i);
		if((PIND & 0x04) == 0x04) LCD_key('7', &i);
		if((PIND & 0x08) == 0x08) LCD_key('*', &i);
		
		PORTD = 0x20;		// 2열 검사
		_delay_us(5);
		if((PIND & 0x01) == 0x01) LCD_key('2', &i);
		if((PIND & 0x02) == 0x02) LCD_key('5', &i);
		if((PIND & 0x04) == 0x04) LCD_key('8', &i);
		if((PIND & 0x08) == 0x08) LCD_key('0', &i);
		
		PORTD = 0x40;		// 3열 검사
		_delay_us(5);
		if((PIND & 0x01) == 0x01) LCD_key('3', &i);
		if((PIND & 0x02) == 0x02) LCD_key('6', &i);
		if((PIND & 0x04) == 0x04) LCD_key('9', &i);
		if((PIND & 0x08) == 0x08) LCD_key('#', &i);
	}
}