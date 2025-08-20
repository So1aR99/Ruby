/*
 * lcdmain.c
 *
 * Created: 2025-08-20 오후 1:21:48
 *  Author: COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd/lcd.h"

unsigned int adc_data= 0;


unsigned int read_adc(void)
{
	ADCSRA |= 0x40; // ADC 변환 시작
	while( 1 ) {
		if((ADCSRA & 0x10) != 0 ) break;
	}
	return ADC ; //ADC 값 리턴
}

int main(void)
{

	
	DDRF= 0x00; // PF0를 입력핀으로 설정
	ADMUX =0x00; // 채널 0 선택
	ADCSRA = 0x83;
	_delay_us(10);
	
	Byte str1[] = "Atmega_128";
	char str2[16];  
	
	PortInit();
	LCD_Init();

	LCD_pos(0,0);
	LCD_STR(str1);


	
	while (1)
	{
		adc_data = read_adc();
		
		sprintf(str2, "ADC : %4d", adc_data);
		
		LCD_pos(1,0);   
		LCD_STR(str2);
		_delay_ms(200);
	}
}