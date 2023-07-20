/*
 * Unit_4_Lifo_Buffer.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Belal
 */

#ifndef UNIT_4_LIFO_BUFFER_H_
#define UNIT_4_LIFO_BUFFER_H_

#define buffer_lenght 5

typedef struct{
	unsigned int lenght;
	unsigned char* HEAD;
	unsigned char* BASE;
	unsigned int count;
}LIFO_BUFFER_T;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_NULL,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NOT_FULL

}BUFFER_STATUS;

BUFFER_STATUS LIFO_PUSH(LIFO_BUFFER_T* buffer, unsigned char item);
BUFFER_STATUS LIFO_POP(LIFO_BUFFER_T* buffer, unsigned char* item);
BUFFER_STATUS LIFO_INIT(LIFO_BUFFER_T* buffer,unsigned char* buff,unsigned int length);
BUFFER_STATUS LIFO_IS_FULL(LIFO_BUFFER_T* buffer);

#endif /* UNIT_4_LIFO_BUFFER_H_ */
