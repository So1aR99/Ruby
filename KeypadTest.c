/*
 * KeypadText.c
 *
 * Created: 2025-08-21 오전 10:26:57
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

void LCD_key(char key, int *i)					// 출력할 값 입력받고, 변수 i의 주소를 받아서 i의 값을 넣음
{												// 포인터 변수를 사용해야 값 변경이 가능
	LCD_pos(1, *i);								 
	LCD_CHAR(key);
	(*i)++;										// i의 값이 1 증가
	_delay_ms(500);
	
	if(*i == 15)
	{
		LCD_pos(1, 0);
		LCD_STR("                ");			// 두번째줄 공백으로 초기화하고
		*i = 0;								
		LCD_pos(1, 0);							// 처음으로 커서 출력위치 옮김
	}
}

int main(void)
{	
	int i = 0;
	
	Byte str[] = "Keypad Test";
	
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
	/*
	while(1)
	{	
		PORTD = 0x10;				// 1열에 입력
		_delay_us(5);
		if((PIND & 0x01) == 0x01){	// 입력된 값이 ROWS1이면
			LCD_pos(1, i);			// LCD 2행 i번째에
			LCD_CHAR('1');			// 1출력
			i++;					// i값 증가
			_delay_ms(500);
		}
		if((PIND & 0x02) == 0x02){	// 입력된 값이 ROWS2이면
			LCD_pos(1, i);
			LCD_CHAR('4');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x04) == 0x04){	// 입력된 값이 ROWS3이면
			LCD_pos(1, i);
			LCD_CHAR('7');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x08) == 0x08){	// 입력된 값이 ROWS4이면
			LCD_pos(1, i);
			LCD_CHAR('*');
			i++;
			_delay_ms(500);
		}
		
		PORTD = 0x20;				// 2열에 입력
		_delay_us(5);
		if((PIND & 0x01) == 0x01){
			LCD_pos(1, i);
			LCD_CHAR('2');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x02) == 0x02){
			LCD_pos(1, i);
			LCD_CHAR('5');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x04) == 0x04){
			LCD_pos(1, i);
			LCD_CHAR('8');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x08) == 0x08){
			LCD_pos(1, i);
			LCD_CHAR('0');
			i++;
			_delay_ms(500);
		}
		
		PORTD = 0x40;				// 3열에 입력
		_delay_us(5);
		if((PIND & 0x01) == 0x01){
			LCD_pos(1, i);
			LCD_CHAR('3');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x02) == 0x02){
			LCD_pos(1, i);
			LCD_CHAR('6');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x04) == 0x04){
			LCD_pos(1, i);
			LCD_CHAR('9');
			i++;
			_delay_ms(500);
		}
		if((PIND & 0x08) == 0x08){
			LCD_pos(1, i);
			LCD_CHAR('#');
			i++;
			_delay_ms(500);
		}
		if(i==15){
			LCD_pos(1, 0);
			LCD_STR("                ");		// 두번째줄 공백으로 초기화하고
			i = 0;								// i값 0으로 초기화
			LCD_pos(1, 0);						// 처음으로 커서 출력위치 옮김
		}
	}*/
}