/*
 * Cds.c
 *
 * Created: 2025-08-20 오후 2:27:51
 *  Author: COMPUTER
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "lcd/lcd.h"

unsigned int adc_data = 0;

unsigned int read_adc(void)
{
	ADCSRA |= 0x40; // ADC 변환 시작
	while( 1 ) {
		if((ADCSRA & 0x10) != 0 ) break;
	}
	return ADC ; //ADC 값 리턴
}

void PortInit(void)
{
    DDRC = 0xFF;      // LCD 데이터 출력 (PORTC)
    DDRB |= 0x0F;     // LCD 제어용 PB0~PB3 출력 유지
    DDRB |= 0x20;     // LED 출력 PB5
}

int main(void)
{
    PortInit();

    DDRF = 0x00;         // ADC 입력 PF3
    ADMUX = 0x43;        // AVcc 기준, ADC3 (PF3)
    ADCSRA = 0x87;       // ADC 활성, 분주128

    TCCR1A = 0x82;       // 비반전 PWM, WGM11
    TCCR1B = 0x1A;       // WGM13, WGM12, prescaler 8

    ICR1 = 143;          // TOP 설정
    OCR1A = 0;           // PWM 듀티 초기화

    sei();
    _delay_us(10);

    Byte str1[] = "Atmega_128";
    char str2[16];

    LCD_Init();

    LCD_pos(0, 0);
    LCD_STR(str1);

    while (1)
    {
        adc_data = read_adc();

        sprintf(str2, "CDS : %4d", adc_data);
        LCD_pos(1, 0);
        LCD_STR(str2);
        _delay_ms(500);

        if (adc_data < 100) {
            OCR1A = 28;
        }
        else if (adc_data < 200) {
            OCR1A = 57;
        }
        else if (adc_data < 300) {
            OCR1A = 86;
        }
        else if (adc_data < 400) {
            OCR1A = 114;
        }
        else if (adc_data < 800) {
            OCR1A = 143;
        }
        else {
            OCR1A = 0;
        }
        _delay_ms(100);
    }
    return 0;
}
