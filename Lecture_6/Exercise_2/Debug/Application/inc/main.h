#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f30x.h"
#include "stm32f30x_it.h"

/**
* @brief Function to initialize dma to read or write on different channels, 13 for write, 14 for reading data
* @param DMAx_Channely dma channel structure holder
*/
void initialize_dma_support(DMA_Channel_TypeDef *DMAx_Channely);
/**
* @brief Write data to spi interface using DMA channel 13
*/
void spiDmaWrite(void);
/**
* @brief Read data to spi interface using DMA channel 14
*/
void spiDmaRead(void);

/************************ GPIO configuration definitions ************************/

/************************ UART configuration definitions ************************/

#endif
