/*
 * ex4_insert elemnt in arr_lec4.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int arr[30],element,location,num;
    printf("enter the number of elements \n");
	fflush(stdin); fflush(stdout);
    scanf("%d",&num);

    //insert the array
   int i;
    printf("enter %d elements in array\n",num);
	fflush(stdin); fflush(stdout);
    for(i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the element to be inserted:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

    printf("enter the location:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	for(i=num;i>=location;i--)
	{
		arr[i]=arr[i-1];
	}

	arr[location-1] = element;

	printf("new array : \t");
    for(i=0;i<=num;i++){
        printf("%d\t",arr[i]);
    }



    return 0;
}

