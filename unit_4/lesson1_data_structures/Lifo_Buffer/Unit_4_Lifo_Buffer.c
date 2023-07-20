/*
 * Unit_4_Lifo_Buffer.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Belal
 */

#include "Unit_4_Lifo_Buffer.h"
#include "stdio.h"


BUFFER_STATUS LIFO_INIT(LIFO_BUFFER_T* buffer,unsigned char* buff,unsigned int length){
	buffer->BASE = buff;
	buffer->HEAD = buff;
	buffer->count = 0;
	buffer->lenght = buffer_lenght;

	return LIFO_NO_ERROR;
}

BUFFER_STATUS LIFO_IS_FULL(LIFO_BUFFER_T* buffer)
{
	if(!buffer->BASE || !buffer->HEAD || !buffer )
			return LIFO_NULL;

	if(buffer->count >= buffer_lenght){
		return LIFO_FULL ;
	}else return LIFO_NOT_FULL;
}

BUFFER_STATUS LIFO_PUSH(LIFO_BUFFER_T* buffer, unsigned char item){

	if(!buffer->BASE || !buffer->HEAD || !buffer ){
				return LIFO_NULL;
	}
	if(buffer->count >= buffer_lenght){
			return LIFO_FULL ;
		}
	if(buffer->BASE == buffer->HEAD){
		return LIFO_EMPTY ;
	}

	*(buffer->HEAD) = item;
	buffer->HEAD++ ;
	buffer->count++ ;

	return LIFO_NO_ERROR;
}

BUFFER_STATUS LIFO_POP(LIFO_BUFFER_T* buffer,unsigned char* item){
	if(!buffer->BASE || !buffer->HEAD || !buffer ){
				return LIFO_NULL;
	}
	if(buffer->count >= buffer_lenght){
			return LIFO_FULL ;
	}
	if(buffer->BASE == buffer->HEAD){
		return LIFO_EMPTY ;
	}

	buffer->HEAD--;
	*item = *(buffer->HEAD);
	buffer->count--;

	return LIFO_NO_ERROR;
}

