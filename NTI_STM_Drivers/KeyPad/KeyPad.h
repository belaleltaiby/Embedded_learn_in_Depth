/*
 * KeyPad.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Belal
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"
#include "Bit_math.h"



char Keypad_GetKey(char* buff);
void Keypad_Init(void);
int get_num(unsigned char ch) ;
#endif /* KEYPAD_H_ */
