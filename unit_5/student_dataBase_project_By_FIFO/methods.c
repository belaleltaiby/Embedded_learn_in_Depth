/*
 * methods.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Belal
 */

#include "methods.h"

FIFO_STATUS FIFO_init(FIFO_BUFFER_t* FIFO_buff,student_t* buffer, uint32_t lenght)
{
	FIFO_buff->base = buffer ;
	FIFO_buff->tail = buffer ;
	FIFO_buff->head = buffer ;
	FIFO_buff->count = 0;
	FIFO_buff->lenght = lenght ;

	if(FIFO_buff->base && FIFO_buff->lenght)
		return FIFO_NO_ERROR;
	else
		return FIFO_NULL;
}

FIFO_STATUS FIFO_is_buff_full(FIFO_BUFFER_t* FIFO_buff)
{
	if(!FIFO_buff->base || !FIFO_buff->head || !FIFO_buff->tail )
			return FIFO_NULL;

	if(FIFO_buff->count >= buff_lenght)
	{
		printf("buffer is full");
		return FIFO_FULL ;
	}

	return FIFO_NO_ERROR ;
}

FIFO_STATUS add_student_manually(FIFO_BUFFER_t* FIFO_buff,student_t* student)
{
	int numOfCid,i ,temp;
	student_t *PT_curr_student = FIFO_buff->tail ;
	if(FIFO_is_buff_full(FIFO_buff) == FIFO_NO_ERROR)
	{

		Dprintf("Enter Student Roll Number\n");
		scanf("%d",temp);
		for(i=0;i<FIFO_buff->count;i++)
		{
			if(temp == PT_curr_student->roll )
			{
				Dprintf("This student already exists\n");
				break;
			}
			else{

				PT_curr_student++ ;
			}
		}





		Dprintf("Enter Student First Name\n");
			gets(student->Fname);
			Dprintf("Enter Student Last Name\n");
			gets(student->Lname);

			Dprintf("Enter the number of subjects you want to enroll in\n");
					scanf("%d",numOfCid);
					for(i=0 ; i<numOfCid ; i++)
					{
						Dprintf("Enter Subject CID\n");
						scanf("%d",student->Cid);
					}


		//increase buff counter
		FIFO_buff->count++ ;

		//circular FIFO FIFO_buff->head++;
		if(FIFO_buff->head == FIFO_buff->base + buff_lenght*sizeof(student_t))
		{
			FIFO_buff->head = FIFO_buff->base ;
		}
		else
			FIFO_buff->head++ ;
		return FIFO_NO_ERROR;

	}
	else
		{
			printf("FIFO enqueue failed\n");
			return FIFO_is_buff_full(FIFO_buff);
		}
}






/*
FIFO_BUFFER_STATUS del_s(FIFO_BUFFER_t* FIFO_buff,element_type* item)
{
	if(!FIFO_buff->base || !FIFO_buff->base || !FIFO_buff->base )
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
*/

void FIFO_print_student(FIFO_BUFFER_t* FIFO_buff)
{
	if(FIFO_buff->count == 0)
	{
		printf("buffer is empty\n");
		//return FIFO_EMPTY;
	}
	struct stud_info* temp;
	int i;
	temp = FIFO_buff->tail;
	printf("_____________FIFO print____________\n");
	for(i=0; i < FIFO_buff->count ;i++){
		printf("\t %d \n",*temp->Cid);
		printf("\t %s \n",*temp->Fname);
		printf("\t %s \n",*temp->Lname);
		//printf("\t %d \n",*temp->roll);
		//printf("\t %f \n",*temp->GPA);
		temp++;
	}
	printf("____________________\n");
}
