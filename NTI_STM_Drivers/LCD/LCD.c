/*
 * LCD.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Belal
 */


#include "GPIO_Interface.h"
#include "Bit_Math.h"
#include "LCD.h"


void LCD_SendCommand(uint8 command);
static void LCD_SendData(uint8 character);

void LCD_Init(void)
{
	/* Add your code here */



	GPIO_PinConfig_t* pinconfA3;
	pinconfA3->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfA3->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfA3->GPIO_PinNumber = GPIO_PIN_3;
	MCAL_GPIO_Init(GPIOA, pinconfA3);

	GPIO_PinConfig_t* pinconfA2;
	pinconfA2->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfA2->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfA2->GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOA, pinconfA2);

	GPIO_PinConfig_t* pinconfB0;
	pinconfB0->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfB0->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfB0->GPIO_PinNumber = GPIO_PIN_0;
	MCAL_GPIO_Init(GPIOB, pinconfB0);

	GPIO_PinConfig_t* pinconfB1;
	pinconfB1->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfB1->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfB1->GPIO_PinNumber = GPIO_PIN_1;
	MCAL_GPIO_Init(GPIOB, pinconfB1);

	GPIO_PinConfig_t* pinconfB2;
	pinconfB2->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfB2->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfB2->GPIO_PinNumber = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOB, pinconfB2);

	GPIO_PinConfig_t* pinconfB4;
	pinconfB4->GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinconfB4->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	pinconfB4->GPIO_PinNumber = GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOB, pinconfB4);

	//SETPINDIrection(portB,PIN3,INPUT);
	for(int i=0;i<10000;i++){}
	LCD_SendCommand(0x02);
	for(int i=0;i<10000;i++){}
	LCD_SendCommand(0x28);
	for(int i=0;i<10000;i++){}
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x06);
	LCD_SendCommand(0x01);

	for(int i=0;i<10000;i++){}


	/* Initialization sequence */

	/* Initial LCD commands */
	/* Select data length = 8 bits, 2 lines LCD and small font */

	/* Turn display , cursor and blinking OFF */

	/* Clear LCD */

	/* Increment cursor and turn off display shift */

	/* Turn display ON */


	/* End of your code !*/
}
void LCD_SendChar(uint8 ch)
{
	/* Add your code here */
	/* Change position and send character */
	LCD_SendData(ch);
	/* End of your code !*/

}

void LCD_SendString(char * str)
{
	uint8 i;
	/* Add your code here */
	for (i=0;str[i];i++)
	{
		LCD_SendData(str[i]);
	}
	/* Clear screen and send character by character to the LCD */

	/* End of your code !*/
}

void LCD_SendCommand(uint8 command)
{
	/* Add your code here */
	//setpinvalue(RS,LOW);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, LOW);

	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, getbit(command,4));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, getbit(command,5));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, getbit(command,6));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, getbit(command,7));


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, HIGH);
	for(int i=0;i<10000;i++){}
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, LOW);
	for(int i=0;i<10000;i++){}

	//sent the lower nibble
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, getbit(command,0));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, getbit(command,1));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, getbit(command,2));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, getbit(command,3));


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, HIGH);
	for(int i=0;i<10000;i++){}
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, LOW);
	for(int i=0;i<10000;i++){}
	/* End of your code !*/

}

static void LCD_SendData(uint8 character)
{
	/* Add your code here */

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, HIGH);     //RS High

	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, getbit(character,4));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, getbit(character,5));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, getbit(character,6));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, getbit(character,7));


	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, HIGH);
	for(int i=0;i<10000;i++){}
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, LOW);
	for(int i=0;i<10000;i++){}

	//lower nibble
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, getbit(character,0));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, getbit(character,1));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, getbit(character,2));
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, getbit(character,3));

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, HIGH);
	for(int i=0;i<10000;i++){}
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, LOW);
	for(int i=0;i<10000;i++){}
	/* End of your code !*/
}


void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
}


void LCD_writeNumber(int num)
{
	int n=0;
	uint8 flag=0,rem=0;
	if(num<0){
		LCD_SendChar('-');
		num=num*(-1);
	}
	if(num==0){
		LCD_SendChar('0');
	}
	else{
		while(num){
			rem=num%10;
			if(n==0 && rem==0){
				flag++;
			}
			n=(n*10)+rem;
			num=num/10;
		}
		while(n){
			rem=n%10;
			LCD_SendChar('0'+rem);
			n=n/10;
		}
		while(flag){
			LCD_SendChar('0');
			flag--;
		}
	}
}




void LCD_GoTo(uint8 line, uint8 column)
{
	uint8 address = 0;
	//Calculate address in DDRAM
	switch(line){
	case 0:
		address = (column);
		break;
	case 1:
		address = (column+0x40);
		break;
	case 2:
		address = (column+0x14);
		break;
	case 3:
		address = (column+0x54);
		break;
	}
	LCD_SendCommand(address|(0x80));
	/* Send address to LCD */

	/* End of your code !*/

}

void LCD_CustomChar(uint8 address,uint8*pattern)
{
	uint8 i;
	LCD_SendCommand(0x40+(address*8));
	for(i=0;i<8;i++){
		LCD_SendData(pattern[i]);
	}
	LCD_SendCommand(0x80);
}
