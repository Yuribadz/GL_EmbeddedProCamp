#include "stm32f303x_uart.h"
#include "main.h"

void init(USART_TypeDef* USARTx)
{
	close(USARTx);
	USARTx->BRR |= USART_Rate;
	USARTx->CR1 |= USART_Word;
}

void deinit(USART_TypeDef* USARTx)
{
	close(USARTx);
	USARTx->BRR &= ~(USART_Rate);
	USARTx->CR1 &= ~(USART_Word);
	
}

void start(USART_TypeDef* USARTx)
{
	USARTx->CR1 |= USART_CR1_UE;
	USARTx->CR1 |= USART_CR1_RE;
	USARTx->CR1 |= USART_CR1_TE;
}

void close(USART_TypeDef* USARTx)
{
	USARTx->CR1 &= ~USART_CR1_UE;
	USARTx->CR1 &= ~USART_CR1_RE;
	USARTx->CR1 &= ~USART_CR1_TE;
}

void write(USART_TypeDef* USARTx, uint16_t data)
{
	USARTx->TDR = (data&(USART_TDR_TDR));
}

uint16_t read(USART_TypeDef* USARTx)
{	
	return (USARTx->RDR & (USART_RDR_RDR));
}
