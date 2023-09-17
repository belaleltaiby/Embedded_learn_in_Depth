/*
 * stm32_f103c6_drivers_EXTI.c
 *
 *  Created on: Jan 6, 2023
 *      Author: Belal
 */


#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_EXTI.h"
#include "stm32_f103c6_drivers_GPIO.h"
//////////////Generic functions:///////////////////////
 void (*GP_IRQ_CallBack[15])(void );

 //////////////Generic functions:///////////////////////
////************
void Enable_NVIC(uint16_t IRQ_num)
 {
	 switch(IRQ_num)
	 {
	 case 0 :
		 NVIC_EXTI0_IRQ_Enable;
		 break;
	 case 1 :
	 		 NVIC_EXTI1_IRQ_Enable;
	 		 break;
	 case 2 :
	 		 NVIC_EXTI2_IRQ_Enable;
	 		 break;
	 case 3 :
	 		 NVIC_EXTI3_IRQ_Enable;
	 		 break;
	 case 4 :
			 NVIC_EXTI3_IRQ_Enable;
			 break;
	 case 5 :
	 case 6 :
	 case 7 :
	 case 8 :
	 case 9 :
		    NVIC_EXTI10_5_IRQ_Enable ;
		    break;
	 case 10 :
	 case 11 :
	 case 12 :
	 case 13 :
	 case 14 :
		    NVIC_EXTI15_10_IRQ_Enable ;
		    break;
	 }
 }

void Disable_NVIC(uint16_t IRQ_num)
 {
	 switch(IRQ_num)
	 {
	 case 0 :
		 NVIC_EXTI0_IRQ_Disable;
		 break;
	 case 1 :
	 		 NVIC_EXTI1_IRQ_Disable;
	 		 break;
	 case 2 :
	 		 NVIC_EXTI2_IRQ_Disable;
	 		 break;
	 case 3 :
	 		 NVIC_EXTI3_IRQ_Disable;
	 		 break;
	 case 4 :
			 NVIC_EXTI3_IRQ_Disable;
			 break;
	 case 5 :
	 case 6 :
	 case 7 :
	 case 8 :
	 case 9 :
		     NVIC_EXTI9_5_IRQ_Disable ;
		     break;
	 case 10 :
	 case 11 :
	 case 12 :
	 case 13 :
	 case 14 :
		 	 NVIC_EXTI15_10_IRQ_Disable ;
		     break;
	 }
 }



#define AFIO_GPIO_Mapping(x)  (         (x==GPIOA)?0:\
										(x==GPIOB)?1:\
										(x==GPIOC)?2:\
										(x==GPIOD)?3:0 )


////**********

             //////////////Generic functions:///////////////////////
//-*-*-*-*-*-*-*-*-*-*-*-
void update_EXTI(EXTI_PinConfig_t * EXTI_pinconfig)
{
	GPIO_PinConfig_t PINCONFIG;

	//1- configure GPIO pin to be  floating input

	PINCONFIG.GPIO_PinNumber = EXTI_pinconfig->EXTI_PIN.GPIO_PIN;
	PINCONFIG.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_pinconfig->EXTI_PIN.GPIO_Port, &PINCONFIG);

	//2- UPDATE AFIO to route between EXTI line with PORT A,B,C,D

	uint8_t AFIO_EXTICR_index = EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber/4 ;

	uint8_t AFIO_EXTICR_Position = (EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber % 4)  *  4;
	//clear the 4 bits
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xf << AFIO_EXTICR_Position) ;

	AFIO->EXTICR[AFIO_EXTICR_index] |= ( ( AFIO_GPIO_Mapping(EXTI_pinconfig->EXTI_PIN.GPIO_Port) & 0xF) << AFIO_EXTICR_Position );

	//3-update EXTI registers   falling or rising trigger

	EXTI->RTSR &=~(1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &=~(1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_pinconfig->trigger_Case ==EXTI_trigger_rising)
	{
		EXTI->RTSR |= (1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	}else if(EXTI_pinconfig->trigger_Case ==EXTI_trigger_falling)
	{
		EXTI->FTSR |= (1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	}else
	{
		EXTI->RTSR |= (1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	}

	//4- Update IRQ Handling CAllBack
	GP_IRQ_CallBack[EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber] = EXTI_pinconfig->P_IRQ_CallBack ;



	//5-enable /disable IRQ  from EXTI and NVIC
	if(EXTI_pinconfig->IQR_ENB == EXTI_IRQ_enable)
	{
		EXTI->IMR |=(1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	}else
	{
		EXTI->IMR &=~(1<<EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_pinconfig->EXTI_PIN.EXTI_InputLineNumber);
	}


}
//-*-*-*-*-*-*-*-*-*-*-*




/**================================================================
 * @Fn                    -Mcal_EXTI_GPIO_DeInit
 * @brief                 -reset EXTI registers and NVIC corresponding IRQ mask
 * @retval                -NONE
 * Note                   -
 */
void Mcal_EXTI_GPIO_DeInit(void)
{
	//1- reset EXTI registers
	EXTI->IMR =  0x00000000 ;
	EXTI->EMR =  0x00000000 ;
	EXTI->RTSR = 0x00000000 ;
	EXTI->FTSR = 0x00000000 ;
	EXTI->SWIER= 0x00000000 ;

	//This bit is
	//cleared by writing a ‘1’ into the bit.
	EXTI->PR = 0xffffffff ;

	//2- reset NVIC IRQ mask
	NVIC_EXTI0_IRQ_Disable ;
	NVIC_EXTI1_IRQ_Disable ;
	NVIC_EXTI2_IRQ_Disable ;
	NVIC_EXTI3_IRQ_Disable ;
	NVIC_EXTI4_IRQ_Disable ;
	NVIC_EXTI9_5_IRQ_Disable ;
	NVIC_EXTI15_10_IRQ_Disable ;
}




/**================================================================
 * @Fn                    -update_EXTI
 * @brief                 -initializes EXTI from specific GPIO PIN and specify the mask/trigger condition and IRQ CallBack
 * @param [in]            -EXTI_pinconfig: set by @ref EXTI_define  and EXTI IRQ define
 * @retval                -NONE
 * Note                   -mandatory to enable RCC clock for AFIO and the corresponding GPIO(A,B,C,D)
 */

void Mcal_EXTI_GPIO_update(EXTI_PinConfig_t * EXTI_pinconfig)
{
	update_EXTI(EXTI_pinconfig);
}




/**================================================================
 * @Fn                    -update_EXTI
 * @brief                 -initializes EXTI from specific GPIO PIN and specify the mask/trigger condition and IRQ CallBack
 * @param [in]            -EXTI_pinconfig: set by @ref EXTI_define  and EXTI IRQ define
 * @retval                -NONE
 * Note                   -mandatory to enable RCC clock for AFIO and the corresponding GPIO(A,B,C,D)
 */
void Mcal_EXTI_GPIO_init(EXTI_PinConfig_t * EXTI_pinconfig)
{
	update_EXTI(EXTI_pinconfig);
}


//******************    ISR Functions       ***//////////////

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= (1<<0);
	GP_IRQ_CallBack[0]();
}
void EXTI1_IRQHandler(void)
{
	EXTI->PR |= (1<<1);
	GP_IRQ_CallBack[1]();
}
void EXTI2_IRQHandler(void)
{
	EXTI->PR |= (1<<2);
	GP_IRQ_CallBack[2]();
}
void EXTI3_IRQHandler(void)
{
	EXTI->PR |= (1<<3);
	GP_IRQ_CallBack[3]();
}
void EXTI4_IRQHandler(void)
{
	EXTI->PR |= (1<<4);
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1<<5) { EXTI->PR |= (1<<5);  GP_IRQ_CallBack[5](); };
	if(EXTI->PR & 1<<6) { EXTI->PR |= (1<<6);  GP_IRQ_CallBack[6](); };
	if(EXTI->PR & 1<<7) { EXTI->PR |= (1<<7);  GP_IRQ_CallBack[7](); };
	if(EXTI->PR & 1<<8) { EXTI->PR |= (1<<8);  GP_IRQ_CallBack[8](); };
	if(EXTI->PR & 1<<9) { EXTI->PR |= (1<<9);  GP_IRQ_CallBack[9](); };
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10) { EXTI->PR |= (1<<10);  GP_IRQ_CallBack[10](); };
	if(EXTI->PR & 1<<11) { EXTI->PR |= (1<<11);  GP_IRQ_CallBack[11](); };
	if(EXTI->PR & 1<<12) { EXTI->PR |= (1<<12);  GP_IRQ_CallBack[12](); };
	if(EXTI->PR & 1<<13) { EXTI->PR |= (1<<13);  GP_IRQ_CallBack[13](); };
	if(EXTI->PR & 1<<14) { EXTI->PR |= (1<<14);  GP_IRQ_CallBack[14](); };
	if(EXTI->PR & 1<<15) { EXTI->PR |= (1<<15);  GP_IRQ_CallBack[15](); };
}



