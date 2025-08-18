/*
 * Timer0.c
 *
 * Created: 2025-08-14 오후 4:03:05
 * Author : COMPUTER
 Normal mode : 1sec 만들기
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>

int cnt = 0;
unsigned char LED_Data = 0x00;

ISR(TIMER0_OVF_vect){
	cli();
	TCNT0 = 0xf2;
	cnt++;
	if(cnt >= 1000) {
		cnt = 0;
		LED_Data++;
	}
	sei();
}
int main(void)
{
	DDRB = 0xff;
	TCCR0 |= (1 << CS02) | (1 << CS01) | (1 << CS00);		// 1024분주비
	TCNT0 = 0xF2;			// 255 + 1 - 0x0E
	TIMSK |= 1 << TOIE0;
	TIFR = 0;
	sei();
	
    while (1)
    {
		PORTB = LED_Data;
    }
	return 0;
}

