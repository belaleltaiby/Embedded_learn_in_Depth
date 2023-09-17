/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32_f103c6_drivers_GPIO.h"
#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_EXTI.h"


  //lesson 4
int IRQ_Flag;
int IPSR_out;
enum CPU_AccessLevel{privileged, unprivileged};
void Switch_CPU_AccessLevel(enum CPU_AccessLevel level)
{
	switch(level){
		case privileged:         //clear bit0 in CONTROL register
			__asm("MRS r3,CONTROL \n\t"
				  "LSR r3,r3,#0x1 \n\t"
				  "LSL r3,r3,#0x1  \n\t"
				  "MSR CONTROL, r3");
			break;

		case unprivileged:           //set bit0 in CONTROL register
			__asm("MRS r3,CONTROL \n\t"
				  "ORR r3,r3,#0x1 \n\t"
				  "MSR CONTROL,r3");
			break;
	}


}
void HardFault_Handler()
{
	Switch_CPU_AccessLevel(privileged);
}
void EXTI9_callBack(void)
{
	Switch_CPU_AccessLevel(privileged);
	__asm("MRS r4,IPSR"
	        	  );
	__asm("MOV %0,r4"
	        : "=r" (IPSR_out));
	IRQ_Flag = 1;
}

int main()
{
	int CR_out;
	//enable clocks
	RCC_GPIOB_CLK_EN();
	AFIO_CLK_EN();

	Switch_CPU_AccessLevel(unprivileged);

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.trigger_Case = EXTI_trigger_rising ;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_callBack;
	EXTI_CFG.IQR_ENB = EXTI_IRQ_enable;
    Mcal_EXTI_GPIO_init(&EXTI_CFG);

    __asm("nop \n\t nop ");
    __asm("MRS r5,CONTROL"
    	  );
    __asm("MOV %0,r5"
        : "=r" (CR_out));

    Switch_CPU_AccessLevel(unprivileged);

    IRQ_Flag =1;
	while(1)
	{
		if(IRQ_Flag)
		{
			//LCD_clear_screen();
			IRQ_Flag=0;
		}
	}

	return 0;
}


/*
//lesson2
unsigned int IRQ_Flag = 0;

void EXTI9_callBack(void)
{
	IRQ_Flag = 1;
}

int main()
{
	//enable clocks
	RCC_GPIOB_CLK_EN();
	AFIO_CLK_EN();


	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.trigger_Case = EXTI_trigger_rising ;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_callBack;
	EXTI_CFG.IQR_ENB = EXTI_IRQ_enable;
    Mcal_EXTI_GPIO_init(&EXTI_CFG);

    IRQ_Flag =1;
	while(1)
	{
		if(IRQ_Flag)
		{
			//LCD_clear_screen();
			IRQ_Flag=0;
		}
	}

	return 0;
}*/


/*
//  lab6 lesson 3

unsigned int IRQ_Flag = 0;
int IPSR_out;
void EXTI9_callBack(void)
{
	__asm("MRS r4,IPSR"
	        	  );
	__asm("MOV %0,r4"
	        : "=r" (IPSR_out));
	IRQ_Flag = 1;
}

int main()
{
	int CR_out;
	//enable clocks
	RCC_GPIOB_CLK_EN();
	AFIO_CLK_EN();


	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9;
	EXTI_CFG.trigger_Case = EXTI_trigger_rising ;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_callBack;
	EXTI_CFG.IQR_ENB = EXTI_IRQ_enable;
    Mcal_EXTI_GPIO_init(&EXTI_CFG);

    __asm("nop \n\t nop ");
    __asm("MRS r3,CONTROL"
    	  );
    __asm("MOV %0,r3"
        : "=r" (CR_out));


    IRQ_Flag =1;
	while(1)
	{
		if(IRQ_Flag)
		{
			//LCD_clear_screen();
			IRQ_Flag=0;
		}
	}

	return 0;
}*/





