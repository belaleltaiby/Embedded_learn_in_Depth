/*
 * stm32_f103c6_drivers_EXTI.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Belal
 */


#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_RCC.h"
#include "stm32_f103c6_drivers_GPIO.h"


uint32_t AHP_pre[]={0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};
uint32_t APB1_pre[]={0,0,0,0,1,2,3,4};


uint32_t Mcal_Get_SYSCLK_frq()
{
//	Bits 3:2 SWS: System clock switch status
//	Set and cleared by hardware to indicate which clock source is used as system clock.
//	00: HSI oscillator used as system clock
//	01: HSE oscillator used as system clock
//	10: PLL used as system clock
//	11: not applicable

	switch(( (RCC->CFGR)>>2) & 0b11 )
	{
	case(0):
			return HSI_freq;
		    break;
	case(1):
			return HSE_freq;   //to do later
		    break;
	case(2):
			return PLL_freq;   //to do later
			break;
	}
}

uint32_t Mcal_Get_HCLK_frq()
{
//	Bits 7:4 HPRE: AHB prescaler
//	Set and cleared by software to control the division factor of the AHB clock.
//	0xxx: SYSCLK not divided
//	1000: SYSCLK divided by 2
//	1001: SYSCLK divided by 4
//	1010: SYSCLK divided by 8
//	1011: SYSCLK divided by 16
//	1100: SYSCLK divided by 64
//	1101: SYSCLK divided by 128
//	1110: SYSCLK divided by 256
//	1111: SYSCLK divided by 512

	return (Mcal_Get_SYSCLK_frq() >> AHP_pre[((RCC->CFGR)>>4) &0b1111]);
}


uint32_t Mcal_Get_PCLK1_frq()
{
//	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//	Set and cleared by software to control the division factor of the APB low-speed clock
//	(PCLK1).
//	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//	0xx: HCLK not divided
//	100: HCLK divided by 2
//	101: HCLK divided by 4
//	110: HCLK divided by 8
//	111: HCLK divided by 16

	return (Mcal_Get_HCLK_frq() >> APB1_pre[((RCC->CFGR)>>8) & 0b111]);
}


uint32_t Mcal_Get_PCLK2_frq()
{
//	Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
//	Set and cleared by software to control the division factor of the APB high-speed clock
//	(PCLK2).
//	0xx: HCLK not divided
//	100: HCLK divided by 2
//	101: HCLK divided by 4
//	110: HCLK divided by 8
//	111: HCLK divided by 16


	return (Mcal_Get_HCLK_frq() >> APB1_pre[((RCC->CFGR)>>11) & 0b111]);

}

