/*
 * NVIC.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Belal
 */

#ifndef NVIC_INC_NVIC_H_
#define NVIC_INC_NVIC_H_
#include "STD_TYPES.h"


#define  NVIC_Base                                            0xE000E100u
#define  NVIC_ISER0                                      *(volatile int* )(NVIC_Base +0x000)
#define  NVIC_ISER1                                      *(volatile int* )(NVIC_Base +0x004)
#define  NVIC_ISER2                                      *(volatile int* )(NVIC_Base +0x08)
#define  NVIC_ICER0                                      *(volatile int* )(NVIC_Base +0x080)
#define  NVIC_ICER1                                      *(volatile int* )(NVIC_Base +0x084)
#define  NVIC_ICER2                                      *(volatile int* )(NVIC_Base +0x088)

#define  NVIC_IPR0                                      *(volatile int* )(NVIC_Base +0x300)
#define  NVIC_IPR1                                      *(volatile int* )(NVIC_Base +0x304)
#define  NVIC_IPR2                                      *(volatile int* )(NVIC_Base +0x308)
#define  NVIC_IPR3                                      *(volatile int* )(NVIC_Base +0x30C)
#define  NVIC_IPR4                                      *(volatile int* )(NVIC_Base +0x310)
#define  NVIC_IPR5                                      *(volatile int* )(NVIC_Base +0x314)
#define  NVIC_IPR6                                      *(volatile int* )(NVIC_Base +0x318)
#define  NVIC_IPR7                                      *(volatile int* )(NVIC_Base +0x31C)
#define  NVIC_IPR8                                      *(volatile int* )(NVIC_Base +0x320)
#define  NVIC_IPR9                                      *(volatile int* )(NVIC_Base +0x324)

#define  NVIC_ISPR0                                     *(volatile int* )(NVIC_Base +0x100)
#define  NVIC_ISPR1                                      *(volatile int* )(NVIC_Base +0x104)
#define  NVIC_ISPR2                                      *(volatile int* )(NVIC_Base +0x108)

#define  NVIC_ICPR0                                     *(volatile int* )(NVIC_Base +0x180)
#define  NVIC_ICPR1                                      *(volatile int* )(NVIC_Base +0x184)
#define  NVIC_ICPR2                                      *(volatile int* )(NVIC_Base +0x188)

#define  NVIC_IABR0                                     *(volatile int* )(NVIC_Base +0x200)
#define  NVIC_IABR1                                      *(volatile int* )(NVIC_Base +0x204)
#define  NVIC_IABR2                                      *(volatile int* )(NVIC_Base +0x208)


//////////////priority grouping//////////
//@ref_priority_Grouping
#define _16PrioGroub_Sub_NONE                     (0b011 <<8)
#define _8PrioGroub_Sub_2                         (0b100 <<8)
#define _4PrioGroub_Sub_4                         5
#define _2PrioGroub_Sub_8                         (0b110 <<8)
#define _NONE_PrioGroub_Sub_16                    (0b111 <<8)



///////////////SCB peripheral/////////////////
#define  SCB_Base                                            0xE000ED00u
#define  NVIC_SCB_AIRCR                                    *(volatile int* )(SCB_Base +0x0C)
#define  NVIC_SCB_SHCSR                                    *(volatile int* )(SCB_Base +0x24)
/////////////////////////////////////////

//@red    EXTI_IRQ
#define WWDG_IRQ               0
#define EXTI0_IRQ              6
#define EXTI1_IRQ              7
#define EXTI2_IRQ              8
#define EXTI3_IRQ              9
#define EXTI4_IRQ              10
#define EXTI5_IRQ              23
#define EXTI6_IRQ              23
#define EXTI7_IRQ              23
#define EXTI8_IRQ              23
#define EXTI9_IRQ              23
#define EXTI10_IRQ              40
#define EXTI11_IRQ              40
#define EXTI12_IRQ              40
#define EXTI13_IRQ              40
#define EXTI14_IRQ              40
#define EXTI15_IRQ              40
#define USART1_IRQ              37
#define USART2_IRQ              38
#define USART3_IRQ              39
#define SPI1_IRQ                35
#define SPI2_IRQ                36
#define SPI3_IRQ                51
#define ADC1_IRQ                 18
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

//WWdg
#define NVIC_WWDG_IRQ_Enable            	(NVIC_ISER0 |= 1<<WWDG_IRQ)

//ADC1,2
#define NVIC_ADC1_2_RQ_Enable            	(NVIC_ISER0 |= 1<<ADC1_IRQ)



//-*-*-*-*-*-*-*-*-*-*-*-
// Pending IRQ NVIC  Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_WWDG_Pending               (NVIC_ISPR0 |= 1<<WWDG_IRQ)
#define NVIC_ADC1_Pending               (NVIC_ISPR0 |= 1<<ADC1_IRQ)
#define NVIC_USART1_Pending              (NVIC_ISPR1 |= 1<<(USART1_IRQ - 32))


//APIs

void NVIC_void_Init();
void NVIC_EnableIRQ(uint8 IRQn);
void NVIC_DisableIRQ(uint8 IRQn);
void NVIC_SetPendingIRQ (uint8 IRQn);
void NVIC_ClearPendingIRQ (uint8 IRQn);
void NVIC_GetPendingIRQ (uint8 IRQn, uint8 *Val);
void NVIC_GetActive (uint8 IRQn, uint8 *Val);
void NVIC_SetPriorityGrouping(uint8 priority_grouping);
void NVIC_SetPriority (int IRQn, uint8 priority);
void NVIC_GetPriority (uint8 IRQn, uint8 *priority);

#endif /* NVIC_INC_NVIC_H_ */
