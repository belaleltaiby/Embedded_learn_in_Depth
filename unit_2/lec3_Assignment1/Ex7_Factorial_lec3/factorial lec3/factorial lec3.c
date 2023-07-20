/*
 * factorial lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int N;
	printf("enter a num\n");
	fflush(stdin); 	fflush(stdout);
	scanf("%d",&N);
	int fac=1;
	for (int i=1; i<=N; i++)
	{
		fac= fac * i;
	}
	printf("factorial of %d = %d",N,fac);
	return 0;
}
