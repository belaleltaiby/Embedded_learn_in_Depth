/*
 * GPIO_Interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Belal
 */

#ifndef INC_GPIO_INTERFACE_H_
#define INC_GPIO_INTERFACE_H_

//@ref GPIO_PIN_state
#define GPIO_PIN_SET    	1
#define GPIO_PIN_RESET     0

//includes
#include "GPIO_config.h"
#include "STD_TYPES.h"


//config structure
typedef struct{
	uint16_t  GPIO_PinNumber ;          //specifies the gpio pin to be configured
	                                      //this parameter must be a value of @ref GPIO_PIN
	uint8_t   GPIO_MODE ;                 //@ref GPIO_MODE_define
	uint8_t   GPIO_OUTPUT_SPEED ;               //@ref GPIO_SPEED_define

}GPIO_PinConfig_t;

//Macros Configuration References

//@ref GPIO_PIN_define
#define GPIO_PIN_0                   ((uint16_t) 0x0001)
#define GPIO_PIN_1                   ((uint16_t) 0x0002)
#define GPIO_PIN_2                   ((uint16_t) 0x0004)
#define GPIO_PIN_3                   ((uint16_t) 0x0008)
#define GPIO_PIN_4                   ((uint16_t) 0x0010)
#define GPIO_PIN_5                   ((uint16_t) 0x0020)
#define GPIO_PIN_6                   ((uint16_t) 0x0040)
#define GPIO_PIN_7                   ((uint16_t) 0x0080)
#define GPIO_PIN_8                   ((uint16_t) 0x0100)
#define GPIO_PIN_9                   ((uint16_t) 0x0200)
#define GPIO_PIN_10                  ((uint16_t) 0x0400)
#define GPIO_PIN_11                  ((uint16_t) 0x0800)
#define GPIO_PIN_12                  ((uint16_t) 0x1000)
#define GPIO_PIN_13                  ((uint16_t) 0x2000)
#define GPIO_PIN_14                  ((uint16_t) 0x4000)
#define GPIO_PIN_15                  ((uint16_t) 0x8000)
#define GPIO_PIN_ALL                 ((uint16_t) 0xFFFF)

#define GPIO_PIN_mask                0x0000FFFFu



//@ref GPIO_MODE_define
/*
In input mode (MODE[1:0]=00):
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up /
3:  pull-down
In output mode (MODE[1:0] > 00):
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input
 */
#define GPIO_MODE_Analog                       0x00000000
#define GPIO_MODE_INPUT_FLO                    0x00000001
#define GPIO_MODE_INPUT_PU                     0x00000002
#define GPIO_MODE_INPUT_PD                     0x00000003
#define GPIO_MODE_OUTPUT_PP                    0x00000004
#define GPIO_MODE_OUTPUT_OD                    0x00000005
#define GPIO_MODE_OUTPUT_AF_PP                 0x00000006
#define GPIO_MODE_OUTPUT_AF_OD                 0x00000007
#define GPIO_MODE_INPUT_AF                     0x00000008




//@ref GPIO_SPEED_define
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2 MHz.
3: Output mode, max speed 50 MHz.
 */
#define GPIO_SPEED_10M         0x00000001u
#define GPIO_SPEED_2M          0x00000002u
#define GPIO_SPEED_50M         0x00000003u



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA                 ((GPIO_Typedef_t*)GPIOA_BASE)
#define GPIOB                 ((GPIO_Typedef_t *)GPIOB_BASE)
//#define GPIOC                 ((GPIO_Typedef_t *)GPIOC_BASE)
#define GPIOD                 ((GPIO_Typedef_t *)GPIOD_BASE)
#define GPIOE                 ((GPIO_Typedef_t *)GPIOE_BASE)

#define AFIO                  ((AFIO_Typedef_t *)AFIO_BASE)

/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx, GPIO_PinConfig_t * PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx);

//Read APIS
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx);


//write APIS
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx, uint8_t value);
void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber, uint8_t value);


void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber);

//void MCAL_GPIO_LockPin(GPIO_Typedef_t *GPIOx, uint8_t PinNumber);



#endif /* INC_GPIO_INTERFACE_H_ */
