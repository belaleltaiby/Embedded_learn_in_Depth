/*
 * KeyPad.h
 *
 *  Created on: Jan 18, 2023
 *      Author: Belal
 */
/*
#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_

#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"

#define KEYPAD_PORT GPIOB


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8




void Keypad_init();
char Keypad_getkey();

#endif /* INCLUDES_KEYPAD_H_ */




#ifndef INCLUDES_KEYPAD_H_
#define INCLUDES_KEYPAD_H_

#include "stm32_f103x6.h"
#include "stm32_f103c6_drivers_GPIO.h"

#define KeyPad_Port    GPIOB

#define R0   GPIO_PIN_0
#define R1   GPIO_PIN_1
#define R2   GPIO_PIN_3
#define R3   GPIO_PIN_4
#define C0   GPIO_PIN_5
#define C1   GPIO_PIN_6
#define C2   GPIO_PIN_7
#define C3   GPIO_PIN_8

GPIO_PinConfig_t * PCFG;

void KeyPad_init();
char KeyPad_getChar();
#endif /* INCLUDES_KEYPAD_H_ */


