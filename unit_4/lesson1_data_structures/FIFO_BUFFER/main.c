/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Belal
 */
#include "FIFO_BUFFER.h"

int main(){
	FIFO_BUFFER_t uart_fifo;
	element_type buff[buff_lenght];
	element_type i,temp;

	if(FIFO_init(&uart_fifo,buff, buff_lenght) == FIFO_NO_ERROR)
	{
		printf("FIFO init -----Done\n");
	}

	for(i=0 ; i<9 ; i++){
		printf("FIFO Enqueue (%x)  \n",i);
		if(FIFO_enqueue(&uart_fifo, &i) == FIFO_NO_ERROR)
			printf("FIFO enqueue (%x)-----Done \n",i);
		else
			printf("FIFO enqueue (%x)-----failed \n",i);
	}

	FIFO_print(&uart_fifo);  // Print the Whole queue

	FIFO_dequeue(&uart_fifo, &temp);
	printf("FIFO dequeue data=(%x)  \n",temp);
	FIFO_print(&uart_fifo);

	FIFO_dequeue(&uart_fifo, &temp);
	printf("FIFO dequeue data=(%x)  \n",temp);
	FIFO_print(&uart_fifo);

	//to make it circular
	/*for(i=0; i<2 ;i++){
		printf("FIFO dequeue (%x)  \n",i);
		if(FIFO_enqueue(&uart_fifo, &i) == FIFO_NO_ERROR){
			printf("FIFO dequeue (%x)-----Done \n",i);
			FIFO_print(&uart_fifo);  // Print the Whole queue
		}else
			printf("FIFO dequeue (%x)-----failed \n",i);
	}*/
	FIFO_print(&uart_fifo);  // Print the Whole queue after changing
}
