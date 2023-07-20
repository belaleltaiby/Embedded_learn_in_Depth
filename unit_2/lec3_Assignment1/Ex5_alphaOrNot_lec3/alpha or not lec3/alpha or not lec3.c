/*
 * alpha or not lec3.c
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
	printf("enter a character\n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	if(c >= 'a' && c<= 'z' || c >= 'A' && c<= 'Z' )
		printf("%c is an alphabet",c);
	else
		printf("%c is not an alphabet",c);

	return 0;
}
