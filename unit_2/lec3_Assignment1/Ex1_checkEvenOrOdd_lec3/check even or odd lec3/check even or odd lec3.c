/*
 * check even or odd lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num;
	printf("enter the number\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("the num is %d \n",num);
	if(num %2 ==0) printf("the num is even\n");
	if(num %2 != 0) printf("the um is odd");


	return 0;
}
