/*
 * USART2.c
 *
 * Created: 2025-08-14 오전 10:34:07
 * Author : COMPUTER
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>

void Init_USART()
{
	UCSR0A = 0x00;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = 0;
	UBRR0L = 7;
}

void USART0_tx(unsigned char data)			// 송신
{
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char USART0_rx()						// 수신
{
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0; 
}

void USART0_str(unsigned char* str)
{
	while(*str){
		USART0_tx(*str++);
	}
}


int main(void)
{	
	//unsigned char str[] = "Hello World!!\r\n";
	Init_USART();
	DDRA = 0xff;
	PORTA = 0x00;	


	while(1){
	//	USART0_str(str);
	//	_delay_ms(1000);
		unsigned char data = USART0_rx();
		USART0_tx(data);
		PORTA = data - 48;
	}
}
/*
	Init_USART();
    while (1) 
    {
		unsigned char data = USART_rx();
		USART_tx(data);
    }

	unsigned char data;
	for(int i = 0; i < 5; i++){
		USART_tx('=');
		_delay_ms(1000);
		}
		while(1){
			data = USART_rx();

			USART_tx(data + 1);
		}

}
*/
