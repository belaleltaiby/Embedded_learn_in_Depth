/*
 * methods.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Belal
 */

#ifndef METHODS_H_
#define METHODS_H_
#include "stdio.h"
#define Dprintf(...)  {fflush(stdout);\
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin); \
}

//define the element type you want
#define buff_lenght   55               //max number of students

typedef struct stud_info
{
	char Fname[50];
	char Lname[50];
	int roll;
	float GPA;
	int Cid[10];
}student_t;

//create the fifo_buffer
typedef struct {
	unsigned int lenght;
	unsigned int count;
	struct stud_info* base;
	struct stud_info* tail;
	struct stud_info* head;
}FIFO_BUFFER_t;


typedef enum{
	FIFO_NULL,
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_ERROR
}FIFO_STATUS;

/*
void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();
*/

//declare API
void add_student_manually(FIFO_BUFFER_t* FIFO_buff,student_t* student);
void FIFO_is_buff_full(FIFO_BUFFER_t* FIFO_buff);
void FIFO_init(FIFO_BUFFER_t* FIFO_buff,student_t* buffer, uint32_t lenght);

#endif /* METHODS_H_ */
