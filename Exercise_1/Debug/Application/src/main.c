#include "main.h"

int main()
{
	SystemInit();
        RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIO->MODER |= (Pin_TX_Mode | Pin_RX_Mode);
	GPIO->OTYPER |= Pin_TX_OUT_TYPE; 
	GPIO->OSPEEDR |= (Pin_TX_Spd | Pin_RX_Spd);
	GPIO->PUPDR |= Pin_TX_PULLUPD;
	GPIO->AFR[1] |= (Pin_TX_AF | Pin_RX_AF);
	init(USARTn);
	start(USARTn);
	while (1)
	{		
		if (USARTn->ISR & USART_ISR_RXNE)
		{
			write(USARTn, read(USARTn));
		}	
	}
	return 0;
}
