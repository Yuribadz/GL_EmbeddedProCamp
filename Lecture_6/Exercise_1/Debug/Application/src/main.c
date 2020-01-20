#include "main.h"

/**
* @brief Sturcture variable holds configuration of board UART4 settings and used to initialize 
*        onboard interface
*/
USART_InitTypeDef uartS;

/**
* @brief Sturcture variable holds configuration of board GPIOC settings and used to initialize 
*        onboard interface
*/
GPIO_InitTypeDef gpioS;

/**
* @brief Sturcture variable holds configuration of board interrupt controller
* settings and used to initialize onboard interface
*/
NVIC_InitTypeDef nvicS;

// Can main have arguments?? Where they should come from, bootloader?
int main()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_5);
	// Pin 10
	gpioS.GPIO_OType = GPIO_OType_PP;
	gpioS.GPIO_PuPd = GPIO_PuPd_UP;
	gpioS.GPIO_Pin = GPIO_Pin_10;
	// STM says should be kept low to keep low noise from circuit,
	// but I do not fully understand why there are noises in first place
	// and how do I know there are noises
	gpioS.GPIO_Speed = GPIO_Speed_2MHz;
	gpioS.GPIO_Mode = GPIO_Mode_AF;
	// Pin 11
	GPIO_Init(GPIOC, &gpioS);
	gpioS.GPIO_OType = GPIO_OType_PP;
	gpioS.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpioS.GPIO_Pin = GPIO_Pin_11;
	gpioS.GPIO_Speed = GPIO_Speed_2MHz;
	gpioS.GPIO_Mode = GPIO_Mode_AF;
	
	// interrutp controller init
	nvicS.NVIC_IRQChannel = UART4_IRQn;
	
	nvicS.NVIC_IRQChannelPreemptionPriority = 0;
	
	nvicS.NVIC_IRQChannelSubPriority = 0;
	
	nvicS.NVIC_IRQChannelCmd = ENABLE;
	// init
	NVIC_Init(&nvicS);
	// uart
	USART_StructInit(&uartS); 
	USART_Init(UART4, &uartS);
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);	
	USART_Cmd(UART4, ENABLE);
	SystemInit();
	
	while (1){}
	return 0;
}
