/*
 * alarm_actuator.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */


#include "alarm_actuator.h"


int State_alarm;

void alarm_actuator_init()
{
	printf("alarm_actuator_init");
}

void start_alarm()
{
	State_alarm = alarm_ON;
	printf("alarm state is ON\n");
}


void stop_alarm()
{
	State_alarm = alarm_OFF;
	printf("alarm state is OFF\n");
}
