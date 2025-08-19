/*
 * ColorLed1.c
 *
 * Created: 2025-08-19 오후 1:20:07
 *  Author: COMPUTER
 */ 
#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

unsigned RGB_Table[5][3] = {
    // Red Green Blue
	{ 163, 191, 64 },	// Green Yellow
	{ 255,  69,  0 },	// Orange Red
	{ 34 , 139, 34 },	// Forest Green
	{ 135, 206, 235},	// Sky Blue
	{ 128,   0, 128}	// Purple
};

int main(void)
{
	unsigned char i = 0;;
	DDRB = 0xe0;		// White
	ASSR = 0;
	// Phase Correct PWM (8 bit) ==> 모드 1
	// 주기 = (8분주 x 256 x 2 ) / 14.7456 Mhz = 277 [us]
	// Phase Correct PWM 모드에서는
	// 주기가 2배로 되므로 X 2를 해준다
	TCCR1A = 0xa9;
	TCCR1B = 0x02;
	TCCR1C = 0x00;
	while(1)
	{
		for(i = 0; i<5; i++){
			OCR1AL = RGB_Table[i][0];	// PB5핀
			OCR1BL = RGB_Table[i][1];	// PB6핀
			OCR1CL = RGB_Table[i][2];	// PB7핀
			_delay_ms(1000);
		}
	}
}