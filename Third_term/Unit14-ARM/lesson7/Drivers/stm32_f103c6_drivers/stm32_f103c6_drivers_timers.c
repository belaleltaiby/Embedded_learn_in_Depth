/*
 * stm32_f103c6_drivers_timers.c
 *
 *  Created on: Feb 6, 2023
 *      Author: Belal
 */

/*


#include "stm32_f103c6_drivers_timers.h"

void Timer_init(TIM2t5_TypeDef_t* TIMERx , uint32_t max_count, uint32_t counter_initVal , uint32_t prescaler )
{
	TIMERx->TIMx_ARR  = max_count;
	TIMERx->TIMx_CCR1 = counter_initVal;
	TIMERx->TIMx_PSC  = prescaler;

	TIMERx->TIMx_CR1 |= 1 << 7;
	TIMERx->TIMx_CR1 |= 1 << 4;
	TIMERx->TIMx_CR1 |= 1 << 1;
	TIMERx->TIMx_CR1 |= 1 << 0;

	TIMERx->TIMx_EGR  |= 1 << 0;
	TIMERx->TIMx_EGR  |= 1 << 1;

	TIMERx->TIMx_CCMR1 &= ~ 1<<0;
	TIMERx->TIMx_CCMR1 |=  1<<1;
	TIMERx->TIMx_CCMR1 |=  1<<2;
	TIMERx->TIMx_CCMR1 |=  1<<3;
	TIMERx->TIMx_CCMR1 |=  6<<4;




}


void Timer_PWM(Timer_Typedef_t* TimCFG)
{

	//TIMERx->TIMx_CCMR1 |=  1<<3;
	TIMERx->TIMx_CR1   |= 1 << 7;
	TIMERx->TIMx_EGR   |= 1 << 0;
}


*/
