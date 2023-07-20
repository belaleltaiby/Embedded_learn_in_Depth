/*
 * check positive or neg lec3.c
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
	printf("enter a number\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	if(num > 0)
	{
		printf("num is positive\n");
	}else if (num< 0)
	{
		printf("num is negative\n");
	}else
	{
		printf("num equal zero\n");
	}

	return 0;
}
