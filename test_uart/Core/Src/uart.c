/*
 * uart.c
 *
 *  Created on: Apr 7, 2024
 *      Author: Sandil Azad
 *
 *      PB10 USART3_TX  pin number 47
 *      PB11 USART3_RX  pin number 48
 *
 *      CLOCK ENABLE PORT B REGISTER APB2  GPIOB
 *      CLOCK ENABLE                 APB1  USART3
 *
 *
 */


#include "uart.h"

void uart_init(void){

	RCC->APB2ENR |= (1 << 3);          //CLOCK ENABLE  GPIOB
	RCC->APB1ENR |= (1 << 18);         //CLOCK ENABLE  USART3

	GPIOB->CRH   &=~((0xF<<8));        // CLEAR PB 10
	GPIOB->CRH   &=~((0xF<<12));       // CLEAR PB 11


	GPIOB->CRH   |=((3<<8)|(2<<10));   // OUTPUT PB 10
	GPIOB->CRH   |=((0<<12));          // INPUT PB 11

    USART3->BRR     |=  0x0683;

    USART3->CR1     |= USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE | USART_CR1_UE;


}


void put_char(uint8_t byte)
{
    if(byte == '\n')
    {
        put_char('\r');
    }
    USART3->DR = ((int)(byte) & 0xff);
    while (!(USART3->SR & USART_SR_TXE));
}
