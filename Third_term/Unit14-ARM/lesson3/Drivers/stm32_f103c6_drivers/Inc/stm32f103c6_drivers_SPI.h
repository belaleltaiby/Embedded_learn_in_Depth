/*
 * stm32f103c6_drivers_SPI.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Belal
 */

#ifndef INC_STM32F103C6_DRIVERS_SPI_H_
#define INC_STM32F103C6_DRIVERS_SPI_H_
#include "stm32_f103x6.h"


//config structure
typedef struct{
	uint16_t  GPIO_PinNumber ;          //specifies the gpio pin to be configured
	                                      //this parameter must be a value of @ref GPIO_PIN
	uint8_t   GPIO_MODE ;                 //@ref GPIO_MODE_define
	uint8_t   GPIO_OUTPUT_SPEED ;               //@ref GPIO_SPEED_define

}SPI_PinConfig_t;



#endif /* INC_STM32F103C6_DRIVERS_SPI_H_ */
