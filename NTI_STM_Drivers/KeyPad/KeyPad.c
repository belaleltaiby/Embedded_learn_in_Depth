/*
 * KeyPad.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Belal
 */


/*
 * KEYPAD.c
 *
 * Created: 10/23/2023 10:36:44 AM
 *  Author: Belal
 */
#include "KeyPad.h"
#include "GPIO_Interface.h"

GPIO_Typedef_t* ROW_PORT[] = {GPIOA, GPIOA, GPIOA, GPIOA}; // Adjust based on your wiring
uint16_t ROW_PIN[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15}; // Adjust based on your wiring

GPIO_Typedef_t* COL_PORT[] = {GPIOA, GPIOA, GPIOA, GPIOA}; // Adjust based on your wiring
uint16_t COL_PIN[] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11}; // Adjust based on your wiring




void Keypad_Init(void)
{
    // Configure ROW pins as inputs with pull-up
    for (int i = 0; i < 4; i++) {
    	GPIO_PinConfig_t GPIO_InitStruct = {0};
        //__HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitStruct.GPIO_PinNumber = ROW_PIN[i];
        GPIO_InitStruct.GPIO_MODE = GPIO_MODE_INPUT_PU;
        //GPIO_InitStruct.Pull = GPIO_PULLUP;
        MCAL_GPIO_Init(ROW_PORT[i], &GPIO_InitStruct);
    }

    // Configure COL pins as outputs
    for (int i = 0; i < 4; i++) {
    	GPIO_PinConfig_t GPIO_InitStruct = {0};
        //__HAL_RCC_GPIOA_CLK_ENABLE();
        GPIO_InitStruct.GPIO_PinNumber = COL_PIN[i];
        GPIO_InitStruct.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
        MCAL_GPIO_Init(COL_PORT[i], &GPIO_InitStruct);
    }
}

char Keypad_GetKey(char* buff)
{
    const char keypad[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };

    for (int i = 0; i < 4; i++) {
        // Activate each column
        MCAL_GPIO_WritePin(COL_PORT[i], COL_PIN[i], GPIO_PIN_RESET);

        // Check rows
        for (int j = 0; j < 4; j++) {
            if (MCAL_GPIO_ReadPin(ROW_PORT[j], ROW_PIN[j]) == GPIO_PIN_RESET) {
                // Key pressed
                // Debounce or add delay if needed
                while (MCAL_GPIO_ReadPin(ROW_PORT[j], ROW_PIN[j]) == GPIO_PIN_RESET);
                buff = & keypad[j][i];
                return keypad[j][i];
            }
        }

        // Deactivate the column
        MCAL_GPIO_WritePin(COL_PORT[i], COL_PIN[i], GPIO_PIN_SET);
    }

    return '\0'; // No key pressed
}



int get_num(unsigned char ch)         //convert unsigned char into int
{
	int num = 0;
	switch(ch)
	{
		case '0':
		num = 0;
		break;
		case '1':
		num = 1;
		break;
		case '2':
		num = 2;
		break;
		case '3':
		num = 3;
		break;
		case '4':
		num = 4;
		break;
		case '5':
		num = 5;
		break;
		case '6':
		num = 6;
		break;
		case '7':
		num = 7;
		break;
		case '8':
		num = 8;
		break;
		case '9':
		num = 9;
		break;
		default:

		break;       //it means wrong input
	}
	return num;
}

