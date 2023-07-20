/*
 * ex1_prime nums between 2 intervals_lec5.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprime(int num)
{
	int prime =1;
	for(int j=2;j<=num/2;j++)
	{
		if(num%j==0){
			//printf("not prime");
			prime=0;
			break;}
	}

	return prime;
}

int main()
{
	int num1,num2,i;
		printf("Enter Two Numbers(intervals)\n");
		fflush(stdin);fflush(stdout);
		scanf("%d %d\n",&num1,&num2);

		printf("prime numbers : ");
		fflush(stdin);fflush(stdout);
		for(i=num1+1;i<num2;i++)
		{
			if(Isprime(i))
				printf("%d  ",i);
		}
		return 0;
}
