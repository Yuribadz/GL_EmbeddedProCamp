#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f30x.h"
#include "stm32f303x_uart.h"

/**
  * @brief  GPIO Port definition
*/
#define GPIO GPIOC
/**
  * @brief  Define TX pin to AF mod
*/
#define Pin_TX_Mode GPIO_MODER_MODER10_1
/**
  * @brief  Define TX pin AF mode
*/
#define Pin_RX_Mode GPIO_MODER_MODER11_1
/**
  * @brief  Define TX output
*/
#define Pin_TX_OUT_TYPE 0x00
/**
  * @brief  define Tx pull
*/
#define Pin_TX_PULLUPD ((uint32_t)0x00100000)
/**
  * @brief  Define tx pin speed to high speed
*/
#define Pin_TX_Spd GPIO_OSPEEDER_OSPEEDR10
/**
  * @brief  Define rx pin speed to highspeed
*/
#define Pin_RX_Spd GPIO_OSPEEDER_OSPEEDR11
/**
  * @brief  Define tx alternate function
*/
#define Pin_TX_AF (uint32_t)0x0500
/**
  * @brief  Define rx alternate function
*/
#define Pin_RX_AF ((uint32_t)0x05000)
/**
  * @brief  Define UART 
*/
#define USARTn UART4
/**
  * @brief  Define transmission rate to 9600
*/
#define USART_Rate 0xea6	
/**
  * @brief  Define uart word to 8 bits 
*/
#define USART_Word ((uint32_t)0x00000000)

#endif
