/*
 * SYSTICK.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Belal
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include "STD_TYPES.h"
#include "Bit_math.h"

#define Systick_Base              0xE000E010u

typedef struct{
	volatile int STK_CTRL;
	volatile int STK_LOAD;
	volatile int STK_VAL;
	volatile int STK_CALIB;
}SYSTICK_t;

#define SYSTICK                 ((SYSTICK_t *)Systick_Base)


#define SYSTICK_ENABLE   0x00000001
#define SYSTICK_DISABLE  0xFFFFFFFE

#define OK       0
#define NOT_OK   1

#define SYSTICK_CLK_AHB  	   0x00000004
#define SYSTICK_CLK_AHB_DIV_8  0x00000000


#define SYSTICK_TICK_INT_ENABLE  0x00000002
#define SYSTICK_TICK_INT_DISABLE 0x00000000

//APIs
typedef void (*systickcbf_t) (void);
void SYSTICK_Init (void);
void SYSTICK_Start (void);
void SYSTICK_Stop (void);
void SYSTICK_SetCallback (systickcbf_t cbf);
void SYSTICK_SetTime (int timeus,int clk);
void SYSTICK_SetPrescale (int prescale);


#endif /* INC_SYSTICK_H_ */
