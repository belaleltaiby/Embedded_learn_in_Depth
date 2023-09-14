/*
 * main.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#include "pressure_sensor.h"
#include "alarm_actuator.h"
#include "alarm_monitor.h"
#include "main_algorithm.h"
void setup()
{
	Psensor_init();
	alarm_actuator_init();

	Psensor           = state_Psensor_busy;
	Pressure_detected = state_low_pressure;
	alarmAction       = state_stop_alarm;
}



int main()
{
	setup();
	while(1)
	{

		Psensor();
		Pressure_detected();
		alarmAction();


	}
	return 0;
}
