/*
 * capital or small lec3.c
 *
 *  Created on: Jul 8, 2022
 *      Author: Belal
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char c;
	printf("enter the alpha\n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	if(c=='a'||c=='g'||c=='n')
		printf("the alpha is small");
	else if(c=='A'||c=='G'||c=='N')
		printf("the alpha is capital");
	return 0;
}
