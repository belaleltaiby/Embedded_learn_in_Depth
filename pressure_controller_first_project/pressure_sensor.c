/*
 * pressure_sensor.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#include "pressure_sensor.h"

int Pval = 0 ;

void Psensor_init()
{
	printf("pressure_sensor_init\n");
}

//generating random values (sensor will read them)
int generate_random(int l, int r)
{
	int rand_num=(rand() % (r-l+1)) + l ;
	return rand_num;
}

//pressure sensor sends value to main algorithms
void state_Psensor_busy()
{
	Pval = generate_random(15, 25) ;
	printf("pressure sensor is busy reading pressure value = %d\n",Pval);
	Psensor_set_Pvalue(Pval);
	Psensor = state_Psensor_busy;
}

