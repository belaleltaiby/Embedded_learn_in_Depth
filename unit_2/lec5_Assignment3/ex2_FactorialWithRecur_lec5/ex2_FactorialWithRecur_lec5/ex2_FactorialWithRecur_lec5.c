/*
 * ex2_FactorialWithRecur_lec5.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fac =1;
int Factorial(int num)
{
	fac = fac * num;
	if (num != 1){
		Factorial(--num);
	}
	return fac;
}

int main()
{
	int number;
	printf("Enter The Number : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);

	printf("The factorial of %d is %d\n",number,Factorial(number));
	return 0;
}

