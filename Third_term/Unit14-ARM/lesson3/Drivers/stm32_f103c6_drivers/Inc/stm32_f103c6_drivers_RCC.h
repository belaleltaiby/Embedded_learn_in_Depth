/*
 * stm32_f103c6_drivers_EXTI.h
 *
 *  Created on: Jan 6, 2023
 *      Author: Belal
 */

#ifndef INC_STM32_F103C6_DRIVERS_RCC_H_
#define INC_STM32_F103C6_DRIVERS_RCC_H_



//includes
#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"

#define HSI_freq    8
#define HSE_freq    1600
#define PLL_freq    1800


uint32_t Mcal_Get_SYSCLK_frq();
uint32_t Mcal_Get_HCLK_frq();
uint32_t Mcal_Get_PCLK1_frq();
uint32_t Mcal_Get_PCLK2_frq();


#endif /* INC_STM32_F103C6_DRIVERS_EXTI_H_ */
