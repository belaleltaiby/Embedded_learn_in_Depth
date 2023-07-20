/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Belal
 */


#include "Unit_4_Lifo_Buffer.h"
#include "stdio.h"


int main(){

	unsigned char temp,i;
	unsigned char buffer_LIFO[buffer_lenght];
	LIFO_BUFFER_T uart_lifo;
	LIFO_INIT(&uart_lifo, buffer_LIFO, buffer_lenght);


	for(i=0; i<5 ; i++){
		LIFO_PUSH(&uart_lifo , i);
	}

	printf("%s\n",buffer_LIFO);

	for(i=0; i<5 ; i++){
		LIFO_POP(&uart_lifo , &temp);
	}
	printf("%s\n",buffer_LIFO);

	return 0;
}
