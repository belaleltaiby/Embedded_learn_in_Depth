/*
 * stm32f103c6_drivers_SPI.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Belal
 */

#ifndef INC_STM32F103C6_DRIVERS_SPI_H_
#define INC_STM32F103C6_DRIVERS_SPI_H_


#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"
#include "stm32_f103c6_drivers_EXTI.h"



enum Polling_mechanism{
	PollingEnable,
	PollingDisable
};

struct S_IRQ_SRC{
	uint8_t  TXE:1; //Transmit buffer is empty
	uint8_t  RXE:1; //Receive buffer is empty
	uint8_t  ERRI:1; //ERROR Interrupt
	uint8_t  reserved:5;
};

typedef struct {
	volatile uint16_t  Device_Mode;				//Specifies the SPI operating mode @ref SPI_Device_Mode

	volatile uint16_t  Communication_Mode;		//Specifies the SPI bidirectional state @ref SPI_Communication_Mode

	volatile uint16_t  Frame_Format;				//Specifies LSB or MSB @ref SPI_frame_format

	volatile uint16_t  Data_Size;				//Specifies size 16 or 8 @ref SPI_DataSize

	volatile uint16_t  CLK_Polarity;				// @ref SPI_CLKPolarity

	volatile uint16_t  CLK_Phase;				// @ref SPI_CLKPhase

	volatile uint16_t  NSS;						//Specifies whether the NSS signal is managed by
												//hardware(NSS Pin) or the software using the SSI bit enable
												//@ref SPI_NSS

	volatile uint16_t  SPI_BAUDRATEPrescaler;	//Specifies the Baud Rate prescaler value which will be used to
	//configure the transmit and receive SCK clock.
	// This parameter must be set based on @ref SPI_BAUDRATEPrescaler
	//@note the communication clock is derived from the master clock
	// the slave clock doesn't need to be set
	//take care you have to configure RCC to enter the correct clock to APB2>>>>SPI1

	uint16_t           IRQ_Enable ;	        	//@ref SPI_IRQ_Enable

	void (* P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);				// Set the C Function which will be called once the IRQ Happen

}SPI_config_t;






//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_Device_Mode
#define SPI_Device_Mode_SLAVE						(0x00000000u)	//CR1>>bit2
#define SPI_Device_Mode_MASTER						(0x1U<<2)		//CR1>>bit2

//@ref SPI_Communication_Mode
#define SPI_Communication_Mode_2LINES                                 (0x00000000U) // CR1 :Full dublex
#define SPI_Communication_Mode_2LINES_RXONLY                           (0x1U <<10) //bit 10 RXONLY Half dublex
#define SPI_Communication_Mode_1LINES_recieve_only                    (0x1U << 15) //bit15 bidirectional data mode enable
#define SPI_Communication_Mode_1LINES_transmit_only                   ( (0x1U << 15) | (0x1U << 14)) // bit14 bidirectional output mode


//@ref SPI_DataSize
#define SPI_DataSize_8bit							(0x00000000u)	//CR1>>bit11
#define SPI_DataSize_16bit							(0x1U << 11)	//CR1>>bit11

//@ref SPI_frame_format
#define SPI_Frame_Format_MSB_Transmitted_First		(0x00000000u)	//CR1>>bit7
#define SPI_Frame_Format_LSB_Transmitted_First		(0x1U << 7)	//CR1>>bit7

//@ref SPI_CLKPolarity
#define SPI_CLKPolarity_LOW_When_Idle				(0x00000000u)//CR1>>bit1
#define SPI_CLKPolarity_HIGH_When_Idle				(0x1U << 1)//CR1>>bit1


//@ref SPI_CLKPhase
#define SPI_CLKPhase_1EDGE_First_Data_Sampling		(0x00000000u)//CR1>>bit0
#define SPI_CLKPhase_2EDGE_First_Data_Sampling		(0x1U << 0)//CR1>>bit0


//@ref SPI_NSS
//HW
#define SPI_NSS_Hard_Slave							(0x00000000u)        //CR1 : bit9
#define SPI_NSS_Hard_Master_SS_Output_Enable		(0x1U << 2)//CR2>>bit0
#define SPI_NSS_Hard_Master_SS_Output_Disable		(0x00000000u)

//NSS is driven by Software (Master or Slave)
#define SPI_NSS_Soft_NSSInternalSoft_SET			( (0x1U << 9) | (0x1U << 8))
#define SPI_NSS_Soft_NSSInternalSoft_RESET			(0x1U << 9)

//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256
//@ref SPI_BAUDRATEPrescaler
#define SPI_BAUDRATEPrescaler_2					(0x00000000u)
#define SPI_BAUDRATEPrescaler_4					(0b001 << 3)
#define SPI_BAUDRATEPrescaler_8					(0b010  << 3)
#define SPI_BAUDRATEPrescaler_16				(0b011  << 3)
#define SPI_BAUDRATEPrescaler_32				(0b100  << 3)
#define SPI_BAUDRATEPrescaler_64				(0b101  << 3)
#define SPI_BAUDRATEPrescaler_128				(0b110  << 3)
#define SPI_BAUDRATEPrescaler_256				(0b111  << 3)

//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_NONE                                             (uint32_t)(0)
#define SPI_IRQ_Enable_TXEIE                                             (uint32_t)(1<<7) //CR2 Bit7 TXEIE
#define SPI_IRQ_Enable_RXNEIE                                             (uint32_t)(1<<6) //CR2 Bit6 RXNEIE
#define SPI_IRQ_Enable_ERRIE                                             (uint32_t)(1<<5) //CR2 Bit7 ERRIE



/*
 * ====================================================================================================
 *                          APIs Supported by "MCAL SPI DRIVER"
 * ====================================================================================================
 */
void MCAL_SPI_INIT(SPI_Typedef_t * SPIx , SPI_config_t* SPI_confg) ;
void MCAL_SPI_DeINIT(SPI_Typedef_t * SPIx , SPI_config_t* SPI_confg) ;
void MCAL_SPI_GPIO_Set_Pins (SPI_Typedef_t * SPIx) ;
void MCAL_SPI_SendData(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn) ;
void MCAL_SPI_ReceiveData(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn) ;
void MCAL_SPI_TX_RX(SPI_Typedef_t * SPIx , uint16_t* pTxBuffer , enum Polling_mechanism PollingEn) ;







#endif /* INC_STM32F103C6_DRIVERS_SPI_H_ */
