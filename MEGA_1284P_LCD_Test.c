/*
 * main.c
 *
 * Created: 7/8/2024 4:09:06 PM
 *  Author: agarciasampedroperez
 */ 

//////MEGA_1284P Board/////////
/////Testing LCD with I2C protocol///////////

#define F_CPU 11059200UL //system clock 11.0592 MHZ
#define USART_1_BAUD 57600 //baud rate for USART
#define UBRR_CALC ((float)(F_CPU / (16 * (float)USART_1_BAUD)) - 1) //Equation in Pg 178 for calculating (setting Baud Rate) UBRR Value

#include <xc.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <string.h>
#include <util/delay.h>

void USART1_Init(void); //initialize USART1
void USART1_Data(const char *str); //addresses String data by the individual character addresses
void USART1_TX_Data(char Data); //transmits char data type to serial (Transmit Function)

char TEST[] = "Testing This crap \n";

int main(void)
{
	USART1_Init();
	
    while(1)
    {
       USART1_Data(TEST);
	   _delay_ms(500); 
    }
}

void USART1_Init() //initialize USART1 to see from USB; TXD1 (PD3)
{
	PRR0 = (0 << PRUSART1); //Disabling Power Reduction on USART1
	
	UBRR1 = UBRR_CALC; //setting Baud Rate for USART
	
	DDRD = (1 << DDD3); //setting USART TX pin as output; not nessary but sets the pin if I need it;
	UCSR1B = (1 << TXEN1); //enables USART TX
	
	/*
	In order for USART1 to transmit it requires the following (because it talks to the USB via board controller):
		- No parity
		- One stop bit (USBS1: Stop Bit Select; initializes at 0 for 1 stop bit)
		- Eight data bits (character size) (UCSZ12 initializes at 0)
		- One start bit
	*/
	UCSR1C = (1 << UCSZ11) | (1 << UCSZ10); //setting Character Size to 8-bits
	UCSR1C |= (0 << UCPOL1); //setting bit to 0 because USART1 initializes in asynchronous mode
	
	// Clear USART Transmit complete flag, normal USART transmission speed
	//UCSR1A |= (1 << TXC1) | (0 << U2X1); //never really screwed with this, since these bits initializes at 0
}

void USART1_Data (const char *str) //addresses string by its characters' addresses
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		USART1_TX_Data(str[i]); //sends char data to Transmit function
	}
}

void USART1_TX_Data (char Data) //transmit data type char to USB (Transmit Function)
{
	while (!(UCSR1A & (1 << UDRE1))) //wait for empty transmit buffer...
	{
		;
	}
	UDR1 = Data; //Puts data into the buffer, sends the data through TX pins/USB
}
