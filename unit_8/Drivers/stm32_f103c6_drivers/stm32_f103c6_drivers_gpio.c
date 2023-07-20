/*
 * stm32_f103c6_drivers_gpio.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Belal
 */



/**================================================================
 * @Fn                    -MCAL_GPIO_Init
 * @brief                 -initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]            -GPIOx: where x can be A -> E  depending on device used to select the GPIO peripheral
 * @param [in]            -PinConfig pointer to GPIO_PinConfig_t structure that contains the configration information for the specified PIN
 * @retval                -NONE
 * Note                   -
 */
#include <stm32_f103c6_drivers_GPIO.h>
#include "stm32_f103x6.h"



uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}



void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	volatile uint32_t * configRegister = NULL;
	uint8_t PIN_CONFIG =0;
	configRegister = ((PinConfig->GPIO_PinNumber) < GPIO_PIN_8)? (&GPIOx->CRL) : (&GPIOx->CRH) ;

	//clear CNF8[1:0] MODE[1:0]
	* configRegister &= ~(0xF << (Get_CRLH_Position(PinConfig->GPIO_PinNumber)));

	//if the pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) ||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD))
	{
		//set CNF8[1:0] MODE[]
		PIN_CONFIG = ( ((PinConfig->GPIO_MODE - 4) << 2)| ((PinConfig->GPIO_OUTPUT_SPEED)  & 0x0F)) ;
		//(*configRegister) |= (PinConfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	}
	//if pin in input
	//00 MODE[1:0]: Input mode (reset state)
	//we set CANF[1:0]
	else
	{
		if( (PinConfig->GPIO_MODE == GPIO_MODE_Analog) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) )
		{
			PIN_CONFIG = (((PinConfig->GPIO_MODE) <<2 ) | (0x0 & 0x0F)) ;
			//*(configRegister) |= (PinConfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
		else if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF))  //consider pin is  input flowting
		{
			PIN_CONFIG = ( ((GPIO_MODE_INPUT_FLO) <<2 ) | (0x0 & 0x0F)) ;
			//*(configRegister) |= (PinConfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		}
		else   //pin is PU   PD input
		{
			PIN_CONFIG = (((GPIO_MODE_INPUT_PU) << 2) |(0x0 & 0x0f));
			if(PinConfig->GPIO_MODE ==GPIO_MODE_INPUT_PU )
			{
				//PxODR =1 input pull up ,tale 20
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;
			}else
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber) ;      //pin is input pull down
			}
		}
	}
	//write on CRL or CRH
	(*configRegister) |= ( (PIN_CONFIG) << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

}



/**================================================================
 * @Fn                     -MCAL_GPIO_DeInit
 * @brief                  -deinitializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]             -GPIOx: where x can be A -> E  depending on device used to select the GPIO peripheral
 * @retval                 -NONE
 * Note-
 */
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx)
{
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= 1<<2 ;
		RCC->APB2RSTR &= ~ (1<<2) ;
	}

	if(GPIOx == GPIOB){
		RCC->APB2RSTR |= 1<<3 ;
		RCC->APB2RSTR &= ~ (1<<3) ;
	}

	if(GPIOx == GPIOC){
		RCC->APB2RSTR |= 1<<4 ;
		RCC->APB2RSTR &= ~ (1<<4) ;
	}

	if(GPIOx == GPIOD){
		RCC->APB2RSTR |= 1<<5 ;
		RCC->APB2RSTR &= ~ (1<<5) ;
	}

	if(GPIOx == GPIOE){
		RCC->APB2RSTR |= 1<<6 ;
		RCC->APB2RSTR &= ~ (1<<6) ;
	}
}


//Read APIS

/**================================================================
 * @Fn               -
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber)
{
	uint8_t bitStatus ;
	if( (GPIOx->IDR & PinNumber) !=  (uint32_t) 0 ){
		bitStatus = 1;
	}else{
		bitStatus = 0 ;
	}

	return bitStatus;
}




/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx)
{
	uint16_t portValue;
	portValue =(uint16_t) (GPIOx->IDR);
	return portValue;
}


//write APIS


/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx, uint8_t value)
{
	GPIOx->ODR = (uint16_t)value;
}



/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */
void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber, uint8_t value)
{
	if(value != 0)
	{
		//GPIOx->ODR |= PinNumber;
		//or
		// BSy: Port x Set bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->BSRR =(uint32_t)PinNumber;
	}
	else{
		//0 BRy: Port x Reset bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR =(uint32_t)PinNumber;
	}
}



/**================================================================
 * @Fn                     -
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */
void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}





/**================================================================
 * @Fn-
 * @brief -
 * @param [in] -
 * @param [out] -
 * @retval -
 * Note-
 */


//void MCAL_GPIO_LockPin(GPIO_Typedef_t *GPIOx, uint8_t PinNumber){}
