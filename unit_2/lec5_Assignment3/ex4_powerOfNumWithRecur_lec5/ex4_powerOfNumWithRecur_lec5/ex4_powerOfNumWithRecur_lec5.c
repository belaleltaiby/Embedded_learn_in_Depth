/*
 * ex4_powerOfNumWithRecur_lec5.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Belal
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int base,exp;
	printf("enter base and power number\n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&base,&exp);
	printf("%d^%d = %d\n",base,exp,power(base,exp));
}

int power(int base,int exp){
	int i;
	if(exp==0) return 1;
	if(exp!=0)
	{
		return(base*power(base,exp-1));
	}
}
