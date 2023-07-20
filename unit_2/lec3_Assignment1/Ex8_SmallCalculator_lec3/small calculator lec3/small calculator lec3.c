/*
 * small calculator lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float num1,num2;
	char operator;
	printf("enter an operator\n");
	fflush(stdin); 	fflush(stdout);
	scanf("%c",&operator);

	printf("enter num1\n");
	fflush(stdin); 	fflush(stdout);
	scanf("%f",&num1);

	printf("enter num2\n");
	fflush(stdin); 	fflush(stdout);
	scanf("%f",&num2);

	switch (operator)
	{
		case '-':
			printf("%f - %f = %f",num1,num2,num1-num2);
			break;

		case '/':
			printf("%f / %f = %f",num1,num2,num1/num2);
			break;

		case '+':
			printf("%f + %f = %f",num1,num2,num1+num2);
			break;

		case '*':
			printf("%f * %f = %f",num1,num2,num1*num2);
			break;
	}


	return 0;
}
