/*
 * ex2_average sum of arr elemnts_lec4.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    puts("enter the size of array: \n");
	fflush(stdin); fflush(stdout);

    int size,i;
    scanf("%d",&size);
    float num[size],sum=0.0;
    for(i=0;i<size;i++){
        puts("enter the number");
    	fflush(stdin); fflush(stdout);

        scanf("%f",&num[i]);
        sum=sum+num[i];
    }
	fflush(stdin); fflush(stdout);

    printf("Average= %f\n",sum/size);


    return 0;
}
