#include "main.h"

/*
* @brief GPIO interface settings struct
*/
GPIO_InitTypeDef gpioS;
/*
* @brief SPI settings struct
*/
SPI_InitTypeDef spiS;
/*
* @brief DMA settings struct
*/
DMA_InitTypeDef dmaS;
/*
* @brief interrupt controller settings struct
*/
NVIC_InitTypeDef nvicS;

/*
* @brief number pointer to memory location where we will write data on channel 13
*/
uint16_t IN = 0xAA;

/*
* @brief Number pointer to memory location where we will read data  after transfer on channel 14
*/
uint16_t OUT = 0x00;

void initialize_dma_support(DMA_Channel_TypeDef *DMAx_Channely)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	if (DMA1_Channel3 == DMAx_Channely)
	{
		DMA_DeInit(DMA1_Channel3);
		dmaS.DMA_M2M = DMA_M2M_Disable;
                		dmaS.DMA_MemoryInc = DMA_MemoryInc_Disable;
		dmaS.DMA_Mode = DMA_Mode_Normal;
                dmaS.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
		dmaS.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		dmaS.DMA_Priority = DMA_Priority_Medium;
		dmaS.DMA_BufferSize = DMA_PeripheralDataSize_HalfWord;
		dmaS.DMA_PeripheralDataSize = DMA_MemoryDataSize_HalfWord;
		dmaS.DMA_DIR = DMA_DIR_PeripheralDST;
		dmaS.DMA_PeripheralBaseAddr = (uint32_t)(&(SPI1->DR));
		dmaS.DMA_MemoryBaseAddr = (uint32_t)(&IN);
		DMA_Init(DMA1_Channel3, &dmaS);
		SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);
		
	}	
	if (DMA1_Channel4 == DMAx_Channely)
	{
		DMA_DeInit(DMA1_Channel4);
		dmaS.DMA_M2M = DMA_M2M_Disable;
		dmaS.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		dmaS.DMA_MemoryInc = DMA_MemoryInc_Disable;
                dmaS.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
		dmaS.DMA_Mode = DMA_Mode_Normal;
		dmaS.DMA_Priority = DMA_Priority_Medium;
		dmaS.DMA_BufferSize = DMA_PeripheralDataSize_HalfWord;
		dmaS.DMA_PeripheralDataSize = DMA_MemoryDataSize_HalfWord;
		dmaS.DMA_DIR = DMA_DIR_PeripheralSRC;
		dmaS.DMA_PeripheralBaseAddr = (uint32_t)(&(SPI2->DR));
		dmaS.DMA_MemoryBaseAddr = (uint32_t)(&OUT);
		DMA_Init(DMA1_Channel4, &dmaS);
		SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Rx, ENABLE);	
	}
}

void spiDmaWrite(void)
{
	initialize_dma_support(DMA1_Channel3);
	DMA_Cmd(DMA1_Channel3, ENABLE);
	while (DMA_GetFlagStatus(DMA1_FLAG_TC3) == RESET)
        {
                // exit on successful data transfer
        }
	DMA_Cmd(DMA1_Channel3, DISABLE);
	while(SPI_I2S_GetFlagStatus(SPI1, (SPI_I2S_FLAG_BSY & SPI_I2S_FLAG_TXE)) == 1)
        {
                // loop is exited when transfer complete, constantly check status of spi flag
        }
}

void spiDmaRead(void)
{
	if (SET == SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE))
	{
		initialize_dma_support(DMA1_Channel4);
		DMA_Cmd(DMA1_Channel4, ENABLE);
		DMA_Cmd(DMA1_Channel4, DISABLE); 
		IN = 0xBB;
	}
}

int main()
{
	SystemInit();
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOBEN, ENABLE);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_5);
	gpioS.GPIO_Pin = (GPIO_Pin_3 | 
        GPIO_Pin_13 | GPIO_Pin_4 | GPIO_Pin_14 |
	GPIO_Pin_5 | GPIO_Pin_15 );
	gpioS.GPIO_Mode = GPIO_Mode_AF;
        gpioS.GPIO_PuPd = GPIO_PuPd_UP;
	gpioS.GPIO_OType = GPIO_OType_PP;
	gpioS.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpioS);
	gpioS.GPIO_Pin = (GPIO_Pin_2);
        gpioS.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpioS.GPIO_Mode = GPIO_Mode_OUT;
	gpioS.GPIO_OType = GPIO_OType_OD;
	GPIO_Init(GPIOB, &gpioS);
	gpioS.GPIO_Pin = (GPIO_Pin_12);
	gpioS.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpioS.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOB, &gpioS);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_SPI2EN, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SPI1EN, ENABLE);
	spiS.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	spiS.SPI_CPHA = SPI_CPHA_2Edge;
	spiS.SPI_CPOL = SPI_CPOL_High;
	spiS.SPI_DataSize = SPI_DataSize_16b;
        spiS.SPI_Mode = SPI_Mode_Master;
	spiS.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spiS.SPI_FirstBit = SPI_FirstBit_MSB;
	spiS.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &spiS);
	spiS.SPI_Mode = SPI_Mode_Slave;
	SPI_Init(SPI2, &spiS);
	SPI_Cmd(SPI1, ENABLE);
        SPI_Cmd(SPI2, ENABLE);
	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
	SPI_NSSInternalSoftwareConfig(SPI2, SPI_NSSInternalSoft_Reset);

	while (1)
	{	
		spiDmaWrite();
		spiDmaRead();	
	}
	return 0;
}
