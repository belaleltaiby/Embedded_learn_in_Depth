/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: Belal
 */


/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Belal
 */

#include "methods.h"

int main(){
	FIFO_BUFFER_t uart_fifo;
	struct stud_info buff[buff_lenght];
	int  i;
	struct stud_info temp[10];

	if(FIFO_init(&uart_fifo,buff, buff_lenght) == FIFO_NO_ERROR)
	{
		printf("FIFO init -----Done\n");
	}

	for(i=0 ; i<9 ; i++){
		//printf("FIFO Enqueue (%x)  \n",i);
		add_student_manually(&uart_fifo, &temp[i]);
			//printf("FIFO enqueue (%x)-----Done \n",i);
		//else
			//printf("FIFO enqueue (%x)-----failed \n",i);
	}

	FIFO_print_student(&uart_fifo);  // Print the Whole queue

/*
	FIFO_dequeue(&uart_fifo, &temp);
	printf("FIFO dequeue data=(%x)  \n",temp);

	FIFO_dequeue(&uart_fifo, &temp);
		printf("FIFO dequeue data=(%x)  \n",temp);

	for(i=0; i<2 ;i++){
		printf("FIFO Enqueue (%x)  \n",i);
		if(FIFO_enqueue(&uart_fifo, &i) == FIFO_NO_ERROR){
			printf("FIFO enqueue (%x)-----Done \n",i);
			FIFO_print(&uart_fifo);  // Print the Whole queue
		}else
			printf("FIFO enqueue (%x)-----failed \n",i);
	}
	FIFO_print(&uart_fifo);
	*/ // Print the Whole queue after changing
}
