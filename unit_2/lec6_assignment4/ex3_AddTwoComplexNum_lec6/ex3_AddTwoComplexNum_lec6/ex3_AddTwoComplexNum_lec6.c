/*
 * ex3_AddTwoComplexNum_lec6.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Belal
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct complexNum{
	float real;
	float imag;
};

int sumComplex(struct complexNum CNum1,struct complexNum CNum2)
{
	struct complexNum sum;
	sum.real=CNum1.real+CNum2.real;
	sum.imag=CNum1.imag+CNum2.imag;
	printf("sum = %f + %f !\n",sum.real,sum.imag);
	return 0;
}

int main()
{
	struct complexNum num1,num2;

	printf("for the first number\n");
	printf("Enter real and imaginary perspectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num1.real,&num1.imag);

	fflush(stdin); fflush(stdout);

	printf("for the second number\n");
	printf("Enter real and imaginary perspectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num2.real,&num2.imag);

	sumComplex(num1,num2);


}
