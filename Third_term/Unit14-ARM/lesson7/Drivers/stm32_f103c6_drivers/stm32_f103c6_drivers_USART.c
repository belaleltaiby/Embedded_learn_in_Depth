 /*
 * stm32_f103c6_drivers_EXTI.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Belal
 */


#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_USART.h"
#include "stm32_f103c6_drivers_GPIO.h"

/*
Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission*/
//-----------------------------INCLUDES----------------------//
#include "stm32_f103c6_drivers_USART.h"

//---------------------Global variables--------------------//
USART_Typedef * Gp_USARTx = NULL;
UART_config_t* Gp_UART_config =NULL;

//-----------------------------MACROS----------------------//





/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */

/**================================================================
 * @Fn				-MCAL_UART_Init
 * @brief 			- Initializes UART (Supported feature ASYNCH. Only)
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param [in] 		- UART_Config: All UART Configuration EXTI_PinConfig_t
 * @retval 			-none
 * Note				-Support for Now Asynch mode & Clock 8 MHZ S
 */
void Mcal_UART_init(USART_Typedef * USARTx,UART_config_t* UART_config )
{
	Gp_UART_config = UART_config;
	int Pclk;

	//enable clock for UART
	if(USARTx == USART1){
		RCC_USART1_CLK_EN() ;
	}else if(USARTx == USART2){
		RCC_USART2_CLK_EN();
	}else if (USARTx == USART3){
		RCC_USART3_CLK_EN();
	}

	//Enable the USART by writing the UE bit in USART_CR1 register to 1...Bit 13 UE: USART enable
	USARTx->USART_CR1 |= 1<<13;

	//Bit 3 TE: Transmitter enable  or Bit 2 RE: Receiver enable   ...based on user configuration
	USARTx->USART_CR1 |= UART_config->mode;

	//Bit 9 PS: Parity selection  ...0 even
	USARTx->USART_CR1 |= UART_config->parity;

	//CR1:Bit 12 M: Word length
	USARTx->USART_CR1 |= UART_config->Payload_lenght;

	//CR2: Bits 13:12 STOP: STOP bits
	USARTx->USART_CR2 |= UART_config->stopBits;

	//CR3: Bit 9 CTSE: CTS enable .......Bit 8 RTSE: RTS enable
	USARTx->USART_CR3 |= UART_config->flowCtrl;

	//BaudeRate
	if(USARTx == USART1)
	{
		Pclk= Mcal_Get_PCLK2_frq();
	}else
	{
		Pclk= Mcal_Get_PCLK1_frq();
	}
	USARTx->USART_BRR   =  UART_BRR_Register(Pclk, UART_config->Baudrate);

	//enable or disable interrupt  ........CR1
	if(UART_config->IRQ_Enable !=(UART_IRQ_none))
	{
		USARTx->USART_CR1  |= UART_config->IRQ_Enable;
		//enable NVIC
		if(USARTx == USART1)
			NVIC_USART1_IRQ_Enable;

		else if(USARTx == USART2)
			NVIC_USART2_IRQ_Enable;

		else if(USARTx == USART3)
			NVIC_USART3_IRQ_Enable;

	}
}
/**================================================================
 * @Fn				-MCAL_UART_GPIO_Set_Pins
 * @brief 			- intialize GPIO Pins
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			-none
 * Note				-Should enable the corresponding ALT  & GPIO  in RCC clock Also called after MCAL_UART_Init()
 */

void Mcal_UART_GPIO_set(USART_Typedef * USARTx)
{
	GPIO_PinConfig_t Pincfg;
	if(USARTx ==USART1)
	{
		//Tx PA9

		Pincfg.GPIO_PinNumber = GPIO_PIN_9;
		Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &Pincfg);

		//Rx PA10

		Pincfg.GPIO_PinNumber = GPIO_PIN_10;
		Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &Pincfg);

		//CTS PA11
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_11;
			Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pincfg);
		}
		//RTS PA12
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_RTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_12;
			Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pincfg);
		}

	}

	if(USARTx ==USART2)
	{
		//Tx PA2

		Pincfg.GPIO_PinNumber = GPIO_PIN_2;
		Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &Pincfg);

		//Rx PA3

		Pincfg.GPIO_PinNumber = GPIO_PIN_3;
		Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &Pincfg);

		//CTS PA0
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_0;
			Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pincfg);
		}
		//RTS PA1
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_RTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_1;
			Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pincfg);
		}
	}

	if(USARTx == USART3)
	{
		//Tx PB10

		Pincfg.GPIO_PinNumber = GPIO_PIN_10;
		Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pincfg);

		//Rx PB11

		Pincfg.GPIO_PinNumber = GPIO_PIN_11;
		Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
		Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pincfg);

		//CTS PB13
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_13;
			Pincfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &Pincfg);
		}
		//RTS PB14
		if((Gp_UART_config->flowCtrl == Hw_flowCtrl_RTS) ||(Gp_UART_config->flowCtrl == Hw_flowCtrl_CTS_RTS))
		{
			Pincfg.GPIO_PinNumber = GPIO_PIN_14;
			Pincfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			Pincfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &Pincfg);
		}

	}
}




/*================================================================
 * @Fn				-MCAL_UART_DEInit
 * @brief 			- DEInitializes UART (Supported feature ASYNCH. Only)
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			-none
 * Note				-Reset the Model By RCC
 */

void Mcal_UART_Deinit(USART_Typedef * USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_reset()  ;
		NVIC_USART1_IRQ_Disable;;
	}else if(USARTx ==USART2)
	{
		RCC_USART2_CLK_reset();
		NVIC_USART2_IRQ_Disable;

	}else if(USARTx == USART3)
	{
		RCC_USART3_CLK_reset()  ;
		NVIC_USART3_IRQ_Disable;
		}
}


/*********************************************************************
 * @fn      		  - Mcal_UART_Tx
 *
 * @brief             -Send Buffer on UART
 *
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param[in]         -pTxBuffer Buffer
 * @param[in]         -PollingEn   Enable pooling or dsable it
 *
 * @return            -

 * @Note              - Should initialize UART First
 * 		//			When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
			//			the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
			//			because it is replaced by the parity.
			//			When receiving with the parity enabled, the value read in the MSB bit is the received parity
			//			bit

 */
void Mcal_UART_Tx(USART_Typedef * USARTx,uint16_t* data,enum polling_mechanism pollingEn)
{
	uint16_t *Pdata;
	//wait untill TXE is set  //1: Data is transferred to the shift register)
	if(pollingEn == enable)
		while(!(USARTx ->USART_SR &(1<<7)));

	if(Gp_UART_config->Payload_lenght == UART_Payload_lenght_9 ){
		USARTx->USART_DR = *data &(0x01ff);
	}else{
		USARTx->USART_DR = *data &(0xff);
	}
}


void Mcal_UART_Rx(USART_Typedef * USARTx,uint16_t* pRxBuffer,enum polling_mechanism pollingEn)
{
	//Loop over until "Len" number of bytes are transferred
	//wait until RXNE flag is set in the SR
	if (pollingEn == enable)
	{
		while( ! (USARTx->USART_SR & 1<<5 ));
	}


	//Check the USART_WordLength item for 9BIT or 8BIT in a frame
	if (Gp_UART_config->Payload_lenght == UART_Payload_lenght_9)
	{
		if (Gp_UART_config->parity ==parity_none)
		{
			//no parity So all 9bit are considered data
			*((uint16_t*) pRxBuffer) = USARTx->USART_DR ;

		}else
		{
			//Parity is used, so, 8bits will be of user data and 1 bit is parity
			*((uint16_t*) pRxBuffer) = ( USARTx->USART_DR  & (uint8_t)0xFF );

		}

	}else
	{
		//This is 8bit data
		if (Gp_UART_config->parity ==parity_none)
		{
			//no parity So all 8bit are considered data
			*((uint16_t*) pRxBuffer) = ( USARTx->USART_DR  & (uint8_t)0xFF ) ;

		}else
		{
			//Parity is used, so,7 bits will be of user data and 1 bit is parity
			*((uint16_t*) pRxBuffer) = ( USARTx->USART_DR  & (uint8_t)0X7F );

		}
	}
}



void MCAL_UART_WAIT_TC (USART_Typedef *USARTx)
{
	// wait till TC flag is set in the SR
	while( ! (USARTx->USART_SR & 1<<6 ));
}







//ISR
void USART1_IRQHandler (void)
{

	Gp_UART_config->P_IRQ_callback() ;

}

void USART2_IRQHandler (void)
{
	Gp_UART_config->P_IRQ_callback()  ;

}
void USART3_IRQHandler (void)
{
	Gp_UART_config->P_IRQ_callback()  ;


}







