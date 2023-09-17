/*
 * stm32_f103c6_drivers_timers.h
 *
 *  Created on: Feb 6, 2023
 *      Author: Belal
 */
/*
#ifndef INC_STM32_F103C6_DRIVERS_TIMERS_H_
#define INC_STM32_F103C6_DRIVERS_TIMERS_H_

#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"
#include "stm32_f103c6_drivers_EXTI.h"

typedef enum{
	PWM_mode1,
	PWM_mode2
}PWM_mode_num_typedef_t;

typedef struct
{
	//uint32_t                freq;          //determined by TIMx_ARR register
	//uint32_t                duty_cycle;    //determined by TIMx_CCRx register
	//PWM_mode_num_typedef_t  mode_num;       //by writing 110 (PWM mode 1) or ‘111 (PWM mode 2) in the OCxM bits in the
	                                       //   TIMx_CCMRx register.
	//The user must enable the corresponding preload register by setting
	//the OCxPE bit in the TIMx_CCMRx register

	//and eventually the auto-reload preload register
	//by setting the ARPE bit in the TIMx_CR1 register

	//the user has to initialize all the registers by setting the
	//UG bit in the TIMx_EGR register

	//Upcounting is active when the DIR bit in the TIMx_CR1 register is low.
	Timer_Typedef_t * TIM_CFG;

}PWM_mode_typedef_t;


typedef struct
{
	TIM2t5_TypeDef_t* Timx;        //access registers
	uint32_t MAX_count;
	uint32_t count_init;
	uint32_t PRESCALER;
}Timer_Typedef_t;




PWM_mode_typedef_t* Config;





/*
 * ===============================================
 * APIs Supported by "MCAL Timers DRIVER"
 * ===============================================
 */


void Timer_Delay(uint32_t xms);

void Timir_init(Timer_Typedef_t* TimCFG , uint32_t max_count, uint32_t counter_initVal , uint32_t prescaler );

void Timer_PWM(Timer_Typedef_t* TimCFG);



#endif /* INC_STM32_F103C6_DRIVERS_TIMERS_H_ */


*/
