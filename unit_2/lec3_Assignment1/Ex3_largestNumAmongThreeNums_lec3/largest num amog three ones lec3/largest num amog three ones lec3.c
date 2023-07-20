/*
 * largest num amog three ones lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num1,num2,num3;
	printf("enter three numbers\n");
	fflush(stdin); fflush(stdout);
	scanf("%d%d%d",&num1,&num2,&num3);
	fflush(stdin); fflush(stdout);
	if(num1>num2 && num1> num3) printf("num1 is the largest \n");
	if(num2>num1 && num2> num3) printf("num2 is the largest \n");
	if(num3>num2 && num3> num1) printf("num3 is the largest \n");

	return 0;
}
