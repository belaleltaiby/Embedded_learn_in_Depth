/*
 * ex1_StructStudent_lec6.c
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
	struct Sstudent S;
	printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	gets(S.name);

	printf("\nEnter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&S.roll_number);

	printf("\nEnter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&S.marks);

	printf("Displaying information\n");
	printf("name: %s\n",S.name);
	printf("Roll: %d\n",S.roll_number);
	printf("Marks: %f\n",S.marks);

	return 0;

}
