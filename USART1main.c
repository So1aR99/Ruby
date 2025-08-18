/*
 * USAT1.c
 *
 * Created: 2025-08-14 오전 9:30:44
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

void putch(unsigned char data){			// 전송
	//while((UCSR0A & 0x20) == 0);
	while(!(UCSR0A & 0x20));
	UDR0 = data;
	//UCSR0A |= 0x20;
}

void putstr(unsigned char* str){
	while(*str){
		putch(*str++);
	}	
}

int main(void)
{
	unsigned char text[] = "Hello World!!\r\n";
	
	DDRE = 0xfe;
	UCSR0A = 0x00;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);		// 0x18
	//UCSR0C = 0x06;
	UCSR0C |= (1 << UCSZ01)  | (1 << UCSZ00);
	UBRR0H = 0x00;
	UBRR0L = 7;
	
    //while (text[i] != '\0') 
    //{
	//	putch(text[i++]);
    //}
	while(1){
		putstr(text);
		_delay_ms(1000);;
	}
	return 0;
}

