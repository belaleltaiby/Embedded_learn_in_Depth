/*
 * ex5_AreaOfCircle_lec6.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Belal
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415
#define area(r) ((pi)*(r)*(r))

int main (){

	float raduis,area;
	printf("enter radius\n");
	fflush(stdin); 	fflush(stdout);
	scanf("%f",&raduis);
	area=area(raduis);
	printf("Area = %.2f",area);


}
