/*
 * SYSTICK.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Belal
 */

#include "SYSTICK.h"

systickcbf_t APPcbf ;

void SYSTICK_Init (void)
{
	/* CLK source and interrupt enable */
	SYSTICK->STK_CTRL |= 1<<2;
	SYSTICK->STK_CTRL |= 1<<1;
}
void SYSTICK_Start (void)
{
	/* enable counter */
	SYSTICK->STK_CTRL |= 1<<0;
}
void SYSTICK_Stop (void)
{
	/* disable counter */
	SYSTICK->STK_CTRL &=~ (1<<0);
}
void SYSTICK_SetCallback (systickcbf_t cbf)
{
	/* callback function */
	APPcbf = cbf;
}
void SYSTICK_SetTime (int timeus,int clk)     //hz  (,8Mh)
{
	/* add value to STK LOAD */
	SYSTICK->STK_LOAD = timeus * clk;
}
void SysTick_Handler(void)
{
	APPcbf();
}
