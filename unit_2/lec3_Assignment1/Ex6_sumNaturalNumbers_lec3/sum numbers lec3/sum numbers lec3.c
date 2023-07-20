/*
 * sum numbers lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// user enter num and output is 1+2+3+..n
int main()
{
	int num;
	printf("enter num\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	int sum = 0;
	for(int i= 1; i<=num ;i++)
	{
		sum+=i;

		if (i != num)
			printf("%d + ",i);
		else
			printf("%d",i);
	}
	printf(" = %d",sum);
	return 0;
}
