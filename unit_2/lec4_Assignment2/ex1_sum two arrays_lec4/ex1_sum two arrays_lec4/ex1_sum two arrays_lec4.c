/*
 * ex1_sum two arrays_lec4.c
 *
 *  Created on: Jul 11, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int row,colomn,first[2][2],second[2][2],sum[2][2];

	printf("Enter elements of first array\n");
	fflush(stdin); fflush(stdout);
	for (row=0;row<2;row++){

		for(colomn=0;colomn<2;colomn++){
			printf("enter a%d%d :  ",row+1,colomn+1);
			fflush(stdin); fflush(stdout);
			scanf("%d\n",&first[row][colomn]);

		}

	}
	printf("Enter elements of second array\n");
	fflush(stdin); fflush(stdout);

	for (row=0;row<2;row++){

		for(colomn=0;colomn<2;colomn++){

			printf("enter b%d%d :  ",row+1,colomn+1);
			fflush(stdin); fflush(stdout);
			scanf("%d\n",&second[row][colomn]);

		}

	}
	printf("sum of two arrays:\n");
	fflush(stdin); fflush(stdout);

	for (row=0;row<2;row++){

		for(colomn=0;colomn<2;colomn++){
			sum[row][colomn]=first[row][colomn] + second[row][colomn];
			printf("%d\t",sum[row][colomn]);

		}

	}
	return 0;
}

