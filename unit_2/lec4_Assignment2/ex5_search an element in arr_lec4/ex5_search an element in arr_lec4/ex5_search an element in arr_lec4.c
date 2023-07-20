/*
 * ex5_search an element in arr_lec4.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Belal
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int siz,i,desired_num,arr[10];
    printf("enter the number of elements: ");
	fflush(stdin); fflush(stdout);
    scanf("%d",&siz);

    printf("enter %d element\n",siz);
	fflush(stdin); fflush(stdout);
    for(i=0;i<siz;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the desired number: ");
	fflush(stdin); fflush(stdout);
    scanf("%d",&desired_num);

    for(i=0;i<siz;i++){
        if(i==desired_num){
            printf("number found at location %d",i);
            break;
        }
        else
            printf("number is not in array");
        	break;


    }
    return 0;
}

