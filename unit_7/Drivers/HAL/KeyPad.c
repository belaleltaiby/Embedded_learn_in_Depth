/*
 * KeyPad.c
 *
 *  Created on: Jan 18, 2023
 *      Author: Belal
 */


#include "stm32_f103c6_drivers_GPIO.h"
#include "stm32_f103x6.h"
#include "KeyPad.h"

int KeyPad_R[] = {R0,R1,R2,R3};
int KeyPad_C[] = {C0,C1,C2,C3};

void KeyPad_init()
{
	PCFG->GPIO_PinNumber    = R0;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = R1;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = R2;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = R3;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = C0;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = C1;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = C2;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	PCFG->GPIO_PinNumber    = C3;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, PCFG);

	MCAL_GPIO_WritePort(KeyPad_Port, 0xff);

}


char KeyPad_getChar()
{
	int i,j;
	for(i=0; i<4; i++)
	{
		MCAL_GPIO_WritePin(KeyPad_Port, C0, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeyPad_Port, C1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeyPad_Port, C2, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KeyPad_Port, C3, GPIO_PIN_SET);

		MCAL_GPIO_WritePin(KeyPad_Port, KeyPad_C[i], GPIO_PIN_RESET);

		for(j=0;j<4;j++)
		{
			if(MCAL_GPIO_ReadPin(GPIOB, KeyPad_R[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(GPIOB, KeyPad_R[j]) == 0);
				switch(i)
				{
				case (0):
											if (j == 0)
												return '7';
											else if (j == 1)
												return '4';
											else if (j == 2)
												return '1';
											else if (j == 3)
												return '?';
				break;
				case (1):
											if (j == 0)
												return '8';
											else if (j == 1)
												return '5';
											else if (j == 2)
												return '2';
											else if (j == 3)
												return '0';
				break;
				case (2):
											if (j == 0)
												return '9';
											else if (j == 1)
												return '6';
											else if (j == 2)
												return '3';
											else if (j == 3)
												return '=';
				break;
				case (3):
											if (j == 0)
												return '/';
											else if (j == 1)
												return '*';
											else if (j == 2)
												return '-';
											else if (j == 3)
												return '+';
				break;

				}
			}
		}
	}
	return 'A';
}
