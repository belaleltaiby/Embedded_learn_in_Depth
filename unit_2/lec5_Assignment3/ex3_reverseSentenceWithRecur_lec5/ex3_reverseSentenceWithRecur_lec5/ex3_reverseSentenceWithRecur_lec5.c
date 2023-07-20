/*
 * ex3_reverseSentenceWithRecur_lec5.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Reverse_str(char *s);
int main()
{
	char str[14];
	int count=0;
	printf("Enter a string\n");
	fflush(stdin);fflush(stdout);
	gets(str);

	for(int i=0;str[i]!='\0';i++){count++;}
	count--;

	while(count >=0){
		Reverse_str(str+count);
		count--;
	}
	return 0;
}
int Reverse_str(char *s)
{
		printf("%c",*s);
	return 0;
}
