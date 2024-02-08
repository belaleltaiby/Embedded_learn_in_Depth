/*
 * RCC_registers.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Belal
 */

#ifndef INC_RCC_REGISTERS_H_
#define INC_RCC_REGISTERS_H_

typedef struct
{
	volatile int CR;
	volatile int CFGR;
	volatile int CIR;
	volatile int APB2RSTR;
	volatile int APB1RSTR;
	volatile int AHBENR;
	volatile int APB2ENR;
	volatile int APB1ENR;
	volatile int BDCR;
	volatile int CSR;

}RCC;

#define MRCC	((volatile RCC * )0x40021000)


#endif /* INC_RCC_REGISTERS_H_ */
