/*
 * ex4_StoreInfoStudent_lec6.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Belal
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Sstudent
{
	char name[20];
	int roll_number;
	float marks;
};

int main()
{
	int i;
	struct Sstudent arr[10];
	for(i=0;i<10;i++)
	{
		printf("for roll number %d\n",i+1);
		arr[i].roll_number =i+1;
		printf("Enter name: ");
		fflush(stdin); fflush(stdout);
		gets(arr[i].name);

		printf("Enter marks: ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&arr[i].marks);
		printf("\n");
	}

	printf("Displaying information\n");
	for(i=0;i<10;i++)
	{
		printf("information for roll number %d\n",i+1);
		printf("name: %s\n",arr[i].name);
		printf("Marks: %f\n",arr[i].marks);
		printf("\n");
	}
}
