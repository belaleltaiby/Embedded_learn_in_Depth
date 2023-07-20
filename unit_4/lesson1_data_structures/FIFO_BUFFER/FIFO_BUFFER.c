/*
 * FIFO_BUFFER.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Belal
 */
#include "FIFO_BUFFER.h"

FIFO_BUFFER_STATUS FIFO_init(FIFO_BUFFER_t* FIFO_buff,element_type* buffer, uint32_t buff1_lenght)
{
	FIFO_buff->base = buffer ;
	FIFO_buff->tail = buffer ;
	FIFO_buff->head = buffer  ;
	FIFO_buff->count = 0 ;
	FIFO_buff->lenght = buff1_lenght;
	if(FIFO_buff->base && FIFO_buff->lenght)
		return FIFO_NO_ERROR;
	else
		return FIFO_NULL;
}


FIFO_BUFFER_STATUS FIFO_is_buff_full(FIFO_BUFFER_t* FIFO_buff)
{
	if(!FIFO_buff->base || !FIFO_buff->head || !FIFO_buff->tail )
			return FIFO_NULL;


	if(FIFO_buff->count >=  buff_lenght){
		printf("FIFO is full\n");
		return FIFO_FULL;
	}

	return FIFO_NO_ERROR;
}
FIFO_BUFFER_STATUS FIFO_enqueue(FIFO_BUFFER_t* FIFO_buff,element_type* item){

	if( FIFO_is_buff_full(FIFO_buff) == FIFO_NO_ERROR )
	{
		*(FIFO_buff->head) = *item;
		FIFO_buff->count++;

		//circular FIFO FIFO_buff->head++;
		if(FIFO_buff->head == FIFO_buff->base + (FIFO_buff->lenght * sizeof(element_type)))
		{
			FIFO_buff->head = FIFO_buff->base;
		}
		else
			FIFO_buff->head++;
		return FIFO_NO_ERROR;
	}
	else
	{
		printf("FIFO enqueue failed\n");
		return FIFO_is_buff_full(FIFO_buff);
	}
}

FIFO_BUFFER_STATUS FIFO_dequeue(FIFO_BUFFER_t* FIFO_buff,element_type* item)
{
	if(!FIFO_buff->base || !FIFO_buff->head || !FIFO_buff->tail )
		return FIFO_NULL;

	if(FIFO_buff->count == 0)
	{
		printf("buffer is empty\n");
		return FIFO_EMPTY;
	}

	*item = *(FIFO_buff->tail);
	FIFO_buff->count--;
	//circular FIFO_buff->tail++;
	if(FIFO_buff->tail == FIFO_buff->base + (FIFO_buff->lenght * sizeof(element_type)))
	{
		FIFO_buff->tail = FIFO_buff->base;
	}
	else
		FIFO_buff->tail++;
	return FIFO_NO_ERROR;

}




void FIFO_print(FIFO_BUFFER_t* FIFO_buff){

	if(FIFO_buff->count == 0)
	{
		printf("buffer is empty\n");
		//return FIFO_EMPTY;
	}
	element_type* temp;
	int i;
	temp = FIFO_buff->tail;
	printf("_____________FIFO print____________\n");
	for(i=0; i < FIFO_buff->count ;i++){
		printf("\t %x \n",*temp);
		temp++;
	}
	printf("____________________\n");
}

