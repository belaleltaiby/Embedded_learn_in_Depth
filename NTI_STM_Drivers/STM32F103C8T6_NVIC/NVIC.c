/*
 * NVIC.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Belal
 */

#include "NVIC_Inc/NVIC.h"
#include "Bit_math.h"
#include "STD_TYPES.h"


static uint32 NVIC_IPR[20];

static int Get_IPRx_Position(uint8 IRQ_num)
{

	return ((((IRQ_num%4)-1)*8)+4);
}

static int Get_IPR_reg_num(int IRQ_num)
{
	return (IRQ_num/4);
}
void NVIC_void_Init()
{
	//Bits 31:16 VECTKEYSTAT[15:0]/ VECTKEY[15:0] Register key  in SCB_AIRCR
	//On writes, write 0x5FA to VECTKEY, otherwise the write is ignored
	NVIC_SCB_AIRCR |= (0x5FA << 16) ;

}


void NVIC_EnableIRQ(uint8 IRQn)
{
	if(IRQn < 32)
	{
		NVIC_ISER0 |= 1<<IRQn;
	}
	else if ((IRQn > 31) && (IRQn < 64) )
	{
		NVIC_ISER1 |= 1<<(IRQn - 32);
	}
	else
	{
		NVIC_ISER2 |= 1<<(IRQn - 64);
	}
}


void NVIC_DisableIRQ(uint8 IRQn)
{
	if(IRQn < 32)
	{
		NVIC_ICER0 |= 1<<IRQn;
	}
	else if ((IRQn > 31) && IRQn < 64 )
	{
		NVIC_ICER1 |= 1<<(IRQn - 32);
	}
	else
	{
		NVIC_ICER2 |= 1<<(IRQn - 64);
	}
}

void  NVIC_SetPendingIRQ (uint8 IRQn)
{
	if(IRQn < 32)
	{
		NVIC_ISPR0 |= 1<<IRQn;
	}
	else if ((IRQn > 31) && IRQn < 64 )
	{
		NVIC_ISPR1 |= 1<<(IRQn - 32);
	}
	else
	{
		NVIC_ISPR2 |= (IRQn - 64);
	}
}

void  NVIC_ClearPendingIRQ (uint8 IRQn)
{
	if(IRQn < 32)
	{
		NVIC_ICPR0 |= 1<<IRQn;
	}
	else if ((IRQn > 31) && IRQn < 64 )
	{
		NVIC_ICPR1 |= 1<<(IRQn - 32);
	}
	else{
		NVIC_ICPR2 |= (IRQn - 64);
	}
}

void NVIC_GetPendingIRQ (uint8 IRQn, uint8 *Val)
{
	if(IRQn < 32)
	{
		*Val = getbit(NVIC_ISPR0,IRQn);
	}
	else if ((IRQn > 31) && IRQn < 64 )
	{
		*Val = getbit(NVIC_ISPR1,IRQn);
	}
	else
	{
		*Val = getbit(NVIC_ISPR2,IRQn);
	}
}

void  NVIC_GetActive (uint8 IRQn, uint8 *Val)
{
	if(IRQn < 32)
	{
		*Val = getbit(NVIC_IABR0,IRQn);
	}
	else if ((IRQn > 31) && IRQn < 64 )
	{
		*Val = getbit(NVIC_IABR1,IRQn);
	}
	else
	{
		*Val = getbit(NVIC_IABR2,IRQn);
	}
}

void NVIC_SetPriorityGrouping(uint8 priority_grouping)   //@ref_priority_Grouping
{
	NVIC_SCB_AIRCR |= priority_grouping <<8 ;
}

void NVIC_SetPriority (int IRQn, uint8 priority)  //priority is 0bxxxx
{
	if(IRQn == 18){NVIC_IPR4 |=(priority <<12);}
	else if(IRQn == 0){NVIC_IPR0 |=(priority << 4);}
	else if(IRQn == 37){NVIC_IPR9 |=(priority << 12);}


	//NVIC_IPR[IRQn/4] |= (priority << Get_IPRx_Position(IRQn));  /////Not working////
}

void NVIC_GetPriority (uint8 IRQn, uint8 *priority)
{
	*priority = ((NVIC_IPR[Get_IPR_reg_num(IRQn)] >>  Get_IPRx_Position(IRQn)) & 0x0F) ;
}




///////////////////////

void NVIC_voidEnableAllPeripherals(void)
{
	__asm("MOV R0, #0 \n\t"
		  "MSR PRIMASK, R0 \n\t");
}

void NVIC_voidDisableAllPeripherals(void)
{
	__asm("MOV R0, #1 \n\t"
		  "MSR PRIMASK, R0 \n\t");
}


void NVIC_voidDisableAllFaults(void)
{
	NVIC_SCB_SHCSR &= ~(0b111111 << 13);
}


void NVIC_voidEnableAllFaults(void)
{
	NVIC_SCB_SHCSR |= 0b111111 << 13;
}

void DNVIC_voidSetBASEPRI(int priority)
{
	__asm("MOV R0, #0x0 \n\t"
		  "MSR BASEPRI, R0 \n\t");
}




