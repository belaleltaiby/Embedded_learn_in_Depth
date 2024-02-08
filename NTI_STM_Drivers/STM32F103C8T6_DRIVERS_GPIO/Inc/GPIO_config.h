/*
 * GPIO_config.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Belal
 */

#ifndef INC_GPIO_CONFIG_H_
#define INC_GPIO_CONFIG_H_
#include "RCC_registers.h"
//-----------------------------
//Includes
#include <stdlib.h>
#include <stdint.h>

#define SRAM_BASE                                       0x20000000u
#define FLASH_BASE                                      0x08000000u
#define SYSTEM_MEMORY_BASE                              0x1FFFF000u

#define PERIPHERALS_BASE                                0x40000000u
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE             0xE0000000u


//Base addresses for BUS Peripherals///////

//Base addresses for AHB Peripherals


//Base addresses for APB2 Peripherals
#define GPIOA_BASE                                       0x40010800u
#define GPIOB_BASE                                       0x40010C00u
#define GPIOC_BASE                                       0x40011000u
#define GPIOD_BASE                                       0x40011400u
#define GPIOE_BASE                                       0x40011800u
#define GPIOF_BASE                                       0x40011C00u
#define GPIOG_BASE                                       0x40012000u

#define AFIO_BASE                                       0x40010000u

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers:
//-*-*-*-*-*-*-*-*-*-*-*
//--------------GPIO registers

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef_t;

//-----------AFIO registers
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t	  reserved;
	volatile uint32_t MAPR2;
}AFIO_Typedef_t;





//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*




//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()       (MRCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()       (MRCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()       (MRCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()       (MRCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()       (MRCC->APB2ENR |= (1<<6))

#define AFIO_CLK_EN()             (MRCC->APB2ENR |= (1<<0))

#endif /* INC_GPIO_CONFIG_H_ */
