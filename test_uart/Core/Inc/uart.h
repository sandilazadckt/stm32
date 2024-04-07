/*
 * uart.h
 *
 *  Created on: Apr 7, 2024
 *      Author: Sandil Azad
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include"stm32f103xe.h"

void uart_init(void);
void put_char(uint8_t byte);


#endif /* INC_UART_H_ */
