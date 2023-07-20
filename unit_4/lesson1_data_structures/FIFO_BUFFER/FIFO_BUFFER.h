/*
 * FIFO_BUFFER.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Belal
 */

#ifndef FIFO_BUFFER_H_
#define FIFO_BUFFER_H_

#include "stdio.h"
#include "stdint.h"

//define the element type you want
#define element_type uint8_t
#define buff_lenght 7

//create the fifo_buffer
typedef struct {
	unsigned int lenght;
	unsigned int count;
	element_type* base;
	element_type* tail;
	element_type* head;
}FIFO_BUFFER_t;

//create FIFO_BUFFER STATUS
typedef enum{
	FIFO_NULL,
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_ERROR
}FIFO_BUFFER_STATUS;

//FIFO APIS

FIFO_BUFFER_STATUS FIFO_enqueue(FIFO_BUFFER_t* FIFO_buff,element_type* item);
FIFO_BUFFER_STATUS FIFO_dequeue(FIFO_BUFFER_t* FIFO_buff,element_type* item);
FIFO_BUFFER_STATUS FIFO_is_buff_full(FIFO_BUFFER_t* FIFO_buff);
FIFO_BUFFER_STATUS FIFO_init(FIFO_BUFFER_t* FIFO_buff,element_type* buffer, uint32_t lenght);
void FIFO_print(FIFO_BUFFER_t* FIFO_buff);


#endif /* FIFO_BUFFER_H_ */
