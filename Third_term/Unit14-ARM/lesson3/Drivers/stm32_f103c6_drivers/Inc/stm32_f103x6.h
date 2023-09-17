/*
 * stm32_f103x6.h
 *
 *  Created on: Dec 23, 2022
 *      Author: Belal
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
#include <stdlib.h>
#include <stdint.h>
//Base addresses for Memories

#define SRAM_BASE                                       0x20000000u
#define FLASH_BASE                                      0x08000000u
#define SYSTEM_MEMORY_BASE                              0x1FFFF000u

#define PERIPHERALS_BASE                                0x40000000u
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE             0xE0000000u


//Base addresses for BUS Peripherals///////

//Base addresses for AHB Peripherals
#define RCC_BASE		0x40021000UL

//Base addresses for APB2 Peripherals
#define GPIOA_BASE                                       0x40010800u
#define GPIOB_BASE                                       0x40010C00u
#define GPIOC_BASE                                       0x40011000u
#define GPIOD_BASE                                       0x40011400u
#define GPIOE_BASE                                       0x40011800u
#define GPIOF_BASE                                       0x40011C00u
#define GPIOG_BASE                                       0x40012000u

#define AFIO_BASE                                       0x40010000u
#define EXTI_BASE                                       0x40010400u
#define USART1_BASE                                     0x40013800u


#define  NVIC_Base                                            0xE000E100u
#define  NVIC_ISER0                                      *(volatile uint32_t* )(NVIC_Base +0x000)
#define  NVIC_ISER1                                      *(volatile uint32_t* )(NVIC_Base +0x004)
#define  NVIC_ISER2                                      *(volatile uint32_t* )(NVIC_Base +0x08)
#define  NVIC_ICER0                                      *(volatile uint32_t* )(NVIC_Base +0x080)
#define  NVIC_ICER1                                      *(volatile uint32_t* )(NVIC_Base +0x084)
#define  NVIC_ICER2                                      *(volatile uint32_t* )(NVIC_Base +0x088)
//timers base address
#define TIM1_BASE                                       0x40012C00u
#define TIM2_BASE                                       0x40000000u
#define TIM3_BASE                                       0x40000400u
#define TIM4_BASE                                       0x40000800u
#define TIM5_BASE                                       0x40000C00u
#define TIM6_BASE                                       0x40001000u
#define TIM7_BASE                                       0x40001400u
#define TIM8_BASE                                       0x40013400u
#define TIM9_BASE                                       0x40014C00u

#define TIM10_BASE                                       0x40015000u
#define TIM11_BASE                                       0x40015400u
#define TIM12_BASE                                       0x40001800u
#define TIM13_BASE                                       0x40001C00u       0x4000 2000
#define TIM14_BASE                                       0x40002000u

#define SPI2_BASE                                        0x40003800u
#define SPI3_BASE                                        0x40003C00u

//Base addresses for APB1 Peripherals
//USART1   IN APB2

#define USART2_BASE                                  0x40004400u
#define USART3_BASE									 0x40004400u
#define UART4_BASE									 0x40004C00u
#define UART5_BASE									 0x40005000u

#define SPI1_BASE                                        0x40013000u
/*
DAC

PWR
BKP
CAN1
CAN2
I2C2
I2C1

IWDG
WWDG
RTC
 */

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO registers

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

//AFIO registers
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t	  reserved;
	volatile uint32_t MAPR2;
}AFIO_Typedef_t;


//RCC registers
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
}RCC_Typedef_t;

//EXTI registers
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_Typedef_t;


//Timer1 and timer8
typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	volatile uint32_t TIMx_RCR;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t TIMx_BDTR;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;
}TIMER1_8_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register TIMERS 2-->5:
//-*-*-*-*-*-*-*-*-*-*-*

typedef	struct{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	//volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	uint32_t 		  RESERVED0;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	//uint32_t 		  RESERVED0;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;

}TIM2t5_TypeDef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;

}USART_Typedef_t;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register : SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register TIMERS 6 and 7:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	uint32_t 		  reserved;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	//uint32_t         reserved;
	//uint32_t         reserved;
	//uint32_t         reserved;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
}TIMER6_7_Typedef_t;



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA                 ((GPIO_Typedef_t*)GPIOA_BASE)
#define GPIOB                 ((GPIO_Typedef_t *)GPIOB_BASE)
#define GPIOC                 ((GPIO_Typedef_t *)GPIOC_BASE)
#define GPIOD                 ((GPIO_Typedef_t *)GPIOD_BASE)
#define GPIOE                 ((GPIO_Typedef_t *)GPIOE_BASE)


#define Tim1                  ((TIMER1_8_Typedef_t*)TIM1_BASE)
#define Tim2                  ((TIM2t5_TypeDef_t*)TIM2_BASE)
#define Tim3                  ((TIM2t5_TypeDef_t*)TIM3_BASE)
#define Tim4                  ((TIM2t5_TypeDef_t*)TIM4_BASE)
#define Tim5                  ((TIM2t5_TypeDef_t*)TIM5_BASE)
/*#define Tim2                  ((TIMER1_8_Typedef_t*)TIM2_BASE)
#define Tim3                  ((TIMER1_8_Typedef_t*)TIM3_BASE)
#define Tim4                  ((TIMER1_8_Typedef_t*)TIM4_BASE)
 */

#define AFIO                  ((AFIO_Typedef_t *)AFIO_BASE)

#define EXTI                  ((EXTI_Typedef_t *)EXTI_BASE)

#define RCC                  ((RCC_Typedef_t *)RCC_BASE)


#define USART1                 ((USART_Typedef_t *)USART1_BASE)
#define USART2                 ((USART_Typedef_t *)USART2_BASE)
#define USART3                 ((USART_Typedef_t *)USART3_BASE)
#define UART4                  ((USART_Typedef_t *)UART4_BASE)
#define UART5                  ((USART_Typedef_t *)UART5_BASE)


#define SPI1					((SPI_Typedef_t *)SPI1_BASE)
#define SPI2					((SPI_Typedef_t *)SPI2_BASE)
#define SPI3					((SPI_Typedef_t *)SPI3_BASE)
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()       (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()       (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()       (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()       (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()       (RCC->APB2ENR |= (1<<6))

#define AFIO_CLK_EN()             (RCC->APB2ENR |= (1<<0))

#define RCC_USART1_CLK_EN()       (RCC->APB2ENR |= (1<<14))
#define RCC_USART2_CLK_EN()       (RCC->APB1ENR |= (1<<17))
#define RCC_USART3_CLK_EN()       (RCC->APB1ENR |= (1<<18))

#define RCC_SPI1_CLK_EN()       (RCC->APB2ENR |= (1<<12))
#define RCC_SPI2_CLK_EN()       (RCC->APB1ENR |= (1<<14))
#define RCC_SPI3_CLK_EN()       (RCC->APB1ENR |= (1<<15))

//-*-*-*-*-*-*-*-*-*-*-*-
// enable/disable IRQ NVIC  Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_EXTI0_IRQ_Enable            	(NVIC_ISER0 |= 1<<6)
#define NVIC_EXTI1_IRQ_Enable            	(NVIC_ISER0 |= 1<<7)
#define NVIC_EXTI2_IRQ_Enable            	(NVIC_ISER0 |= 1<<8)
#define NVIC_EXTI3_IRQ_Enable            	(NVIC_ISER0 |= 1<<9)
#define NVIC_EXTI4_IRQ_Enable            	(NVIC_ISER0 |= 1<<10)
#define NVIC_EXTI10_5_IRQ_Enable         	(NVIC_ISER0 |= 1<<23)
#define NVIC_EXTI15_10_IRQ_Enable            (NVIC_ISER1 |= 1<<8)

#define NVIC_EXTI0_IRQ_Disable            	(NVIC_ICER0 |= 1<<6)
#define NVIC_EXTI1_IRQ_Disable            	(NVIC_ICER0 |= 1<<7)
#define NVIC_EXTI2_IRQ_Disable            	(NVIC_ICER0 |= 1<<8)
#define NVIC_EXTI3_IRQ_Disable            	(NVIC_ICER0 |= 1<<9)
#define NVIC_EXTI4_IRQ_Disable            	(NVIC_ICER0 |= 1<<10)
#define NVIC_EXTI9_5_IRQ_Disable         	(NVIC_ICER0 |= 1<<23)
#define NVIC_EXTI15_10_IRQ_Disable           (NVIC_ICER1 |= 1<<8)


//USART
#define NVIC_USART1_IRQ_Enable            	(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_USART2_IRQ_Enable            	(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_USART3_IRQ_Enable            	(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))


#define NVIC_USART1_IRQ_Disable           (NVIC_ICER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_USART2_IRQ_Disable           (NVIC_ICER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_USART3_IRQ_Disable           (NVIC_ICER1 |= 1<<(USART3_IRQ - 32))


//SPI
#define NVIC_SPI1_IRQ_Enable            	(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_SPI2_IRQ_Enable            	(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))
#define NVIC_SPI3_IRQ_Enable            	(NVIC_ISER1 |= 1<<(SPI3_IRQ - 32))


#define NVIC_SPI1_IRQ_Disable           (NVIC_ICER1 |= 1<<(SPI1_IRQ - 32))   //35-32
#define NVIC_SPI2_IRQ_Disable           (NVIC_ICER1 |= 1<<(SPI2_IRQ - 32))     //36-32
#define NVIC_SPI3_IRQ_Disable           (NVIC_ICER1 |= 1<<(SPI3_IRQ - 32))   //51-32
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32_F103X6_H_ */
