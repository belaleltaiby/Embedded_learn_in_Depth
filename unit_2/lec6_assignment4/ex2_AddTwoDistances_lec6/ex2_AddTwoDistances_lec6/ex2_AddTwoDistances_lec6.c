/*
 * ex2_AddTwoDistances_lec6.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Belal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct distance
{
	int feet;
	float inches;
};
void main()
{
	struct distance dis1,dis2,sum;

	printf("Enter information for 1st distance\n");
	printf("\nEnter feet : ");
	fflush(stdin); fflush(stdout);
	scanf("%d\n",&dis1.feet);

	printf("Enter inches : ");
	fflush(stdin); fflush(stdout);
	scanf("%f\n",&dis1.inches);

	printf("Enter information for 2nd distance\n");
	printf("\nEnter feet : ");
	fflush(stdin); fflush(stdout);
	scanf("%d\n",&dis2.feet);

	printf("Enter inches : ");
	fflush(stdin); fflush(stdout);
	scanf("%f\n",&dis2.inches);

	sum.feet=dis1.feet+dis2.feet;
	sum.inches=dis1.inches+dis2.inches;

	if(sum.inches>12){
		sum.inches-=12;
		sum.feet++;
	}
	printf("sum of distances= %d`-%f\n",sum.feet,sum.inches);

}
