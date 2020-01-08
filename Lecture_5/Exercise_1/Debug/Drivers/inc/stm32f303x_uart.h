#ifndef __STM32F303X_UART_H
#define __STM32F303X_UART_H

#include "stm32f30x.h"

void init(USART_TypeDef* USARTx);
void deinit(USART_TypeDef* USARTx);
void start(USART_TypeDef* USARTx);
void close(USART_TypeDef* USARTx);
uint16_t read(USART_TypeDef* USARTx);
void write(USART_TypeDef* USARTx, uint16_t data);

#endif /* __STM32F303X_UART_H */
