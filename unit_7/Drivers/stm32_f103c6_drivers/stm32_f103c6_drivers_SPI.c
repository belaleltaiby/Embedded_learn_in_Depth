/*
 * stm32_f103c6_drivers_SPI.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Belal
 */

#include "stm32_f103x6.h"
#include "stm32f103c6_drivers_SPI.h"
#include "stm32_f103c6_drivers_RCC.h"

/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
SPI_Typedef_t * Global_SPI_Config [2] = {NULL,NULL};

/*
 * ========================================================
 * 				Generic macros
 * ========================================================
 */
#define SPI1_Index 		0
#define SPI2_Index		1
#define SPI_SR_TXE		(uint8_t)(1<<1)
#define SPI_SR_RXNE		(uint8_t)(1<<0)

void MCAL_SPI_INIT(SPI_Typedef_t * SPIx , SPI_config_t* SPI_confg)
{
	//safety for registers
	uint16_t tempReg_CR1 = 0;
	uint16_t tempReg_CR2 = 0;
	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = SPI_confg;
		RCC_SPI1_CLK_EN() ;
	}
	else
	{
		Global_SPI_Config[SPI2_Index] = SPI_confg;
		RCC_SPI2_CLK_EN() ;
	}

	//Bit 6 SPE: SPI enable
	tempReg_CR1 |= 1<<6 ;
	//master or slave   Bit 2 MSTR: Master selection
	tempReg_CR1 |= SPI_confg->Device_Mode;
	//communication mode
	tempReg_CR1 |= SPI_confg->Communication_Mode;
	//fram format
	tempReg_CR1 |= SPI_confg->Frame_Format;
	//payload lenght
	tempReg_CR1 |= SPI_confg->Data_Size;
	//clock Phase
	tempReg_CR1 |= SPI_confg->CLK_Phase;
	//clock polarity
	tempReg_CR1 |= SPI_confg->CLK_Polarity;
	//---------------------NSS---------------------//

	if(SPI_confg->NSS == SPI_NSS_Hard_Master_SS_Output_Enable)
	{
		tempReg_CR2 |= SPI_NSS_Hard_Master_SS_Output_Enable;
	}
	else if (SPI_confg->NSS == SPI_NSS_Hard_Master_SS_Output_Disable)
	{
		tempReg_CR2 |= SPI_NSS_Hard_Master_SS_Output_Disable;
	}
	else
		tempReg_CR1 |= SPI_confg->NSS;
	//==============================PreScaler=========================
	tempReg_CR1 |= SPI_confg->SPI_BAUDRATEPrescaler;

	if(SPI_confg->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		tempReg_CR1 |= SPI_confg->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_SPI1_IRQ_Enable;
		}
		else
		{
			NVIC_SPI2_IRQ_Enable;
		}
	}

	SPIx->SPI_CR1 = tempReg_CR1;
	SPIx->SPI_CR2 = tempReg_CR2;

}
void MCAL_SPI_DeINIT(SPI_Typedef_t * SPIx , SPI_config_t* SPI_confg)
{
	if(SPIx == SPI1)
		{
		RCC_SPI1_CLK_Disable();
		NVIC_SPI1_IRQ_Disable;
		}
		else
		{
			RCC_SPI2_CLK_Disable() ;
			NVIC_SPI2_IRQ_Disable;
		}

}

void MCAL_SPI_SendData(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn)
{
	if( PollingEn == PollingEnable)
	{
		while(!(SPIx->SPI_SR & SPI_SR_TXE));

		SPIx->SPI_DR = *pTxBuffer;

	}
}

void MCAL_SPI_GPIO_Set_Pins (SPI_Typedef_t * SPIx) ;
void MCAL_SPI_ReceiveData(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn)
{
	if( PollingEn == PollingEnable)
			while(!(SPIx->SPI_SR & SPI_SR_RXNE));

			*pTxBuffer = SPIx->SPI_DR ;

}
void MCAL_SPI_TX_RX(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn)
{
	if( PollingEn == PollingEnable)
		{
			while(!(SPIx->SPI_SR & SPI_SR_TXE));

			SPIx->SPI_DR = *pTxBuffer;
		}

	if( PollingEn == PollingEnable)
				while(!(SPIx->SPI_SR & SPI_SR_RXNE));

				*pTxBuffer = SPIx->SPI_DR ;
}
