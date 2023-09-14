/*
 * main_algorithm.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */


#include "main_algorithm.h"
#include "alarm_monitor.h"

int mainALgo_Pval ;
int threshold = 20 ;

void Psensor_set_Pvalue(int val)
{
	mainALgo_Pval = val ;
	(mainALgo_Pval <= threshold)? (Pressure_detected = state_low_pressure ) : (Pressure_detected = state_high_pressure) ;
}

void state_high_pressure()
{
	high_pressure_detection(mainALgo_Pval);
}


void state_low_pressure()
{
	high_pressure_detection(mainALgo_Pval);
}






