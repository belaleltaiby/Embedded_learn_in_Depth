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

#include "KeyPad.h"
#include "LCD.h"

unsigned int IRQ_Flag = 0;

void wait_ms(int time)
{
	unsigned int i,j;
	for(i=0; i<time; i++)
	{
		for(j=0; j<255; j++);
	}
}




void clock_init()
{

	//enable clock GPIOA
	RCC_GPIOA_CLK_EN();

	//enable clock GPIOB
	RCC_GPIOB_CLK_EN();

}
/*

void GPIO_init()
{
	GPIO_PinConfig_t PinConf;

	//PA1 input HZ
	PinConf.GPIO_PinNumber = GPIO_PIN_1 ;
	PinConf.GPIO_MODE      = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConf);

	//PB1 output push pull
	//Output mode, max speed 10 MHz.   CNF:00
	PinConf.GPIO_PinNumber    = GPIO_PIN_1 ;
	PinConf.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PinConf.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConf);

	//PA13 input HZ
	PinConf.GPIO_PinNumber = GPIO_PIN_13 ;
	PinConf.GPIO_MODE      = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConf);


	//PB13 output push pull
	// Output mode, max speed 10 MHz.  CNF:00
	PinConf.GPIO_PinNumber    = GPIO_PIN_13 ;
	PinConf.GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PinConf.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConf);
}



int main(void)
{
	 clock_init();
	 GPIO_init();

	 while(1)
	 {
		 if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)      //single press
		 {
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);

			 while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);
		 }



		 if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) //multi press
		 		 {
		 			 MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		 		 }
		 wait_ms(5);

	 }
}
 */


void EXTI9_callBack(void)
{
	LCD_clear_screen();
	IRQ_Flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 happens -|--");
	wait_ms(1000);
}

int main()
{
	//enable clocks
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	AFIO_GPIOE_CLK_EN();

	LCD_INIT();
	//LCD_clear_screen();

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
}




/*
void main()
{
	 clock_init();
	 LCD_INIT();
	 KeyPad_init();

	 char pressed_k;
	 while(1){

		 pressed_k = KeyPad_getChar();
		 //LCD_WRITE_CHAR(pressed_k);
		 switch(pressed_k)
		 {
		 case 'A':
			 break;
		 default :
			 LCD_WRITE_CHAR(pressed_k);
			 break;
		 }


	 }

}

*/


