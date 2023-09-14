/*
 * alarm_monitor.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */


#include "alarm_monitor.h"

int alarm_monitor_Pval;
int threshold_monitor = 20;
void high_pressure_detection(int val)
{
	alarm_monitor_Pval = val ;
	(alarm_monitor_Pval <= threshold_monitor)? (alarmAction =state_stop_alarm ):(alarmAction =state_start_alarm);

}


void state_start_alarm()
{
	printf("pressure value now is %d,,,the alarm will be ON\n",alarm_monitor_Pval);
	start_alarm();
}


void state_stop_alarm()
{
	printf("pressure value now is %d,,,the alarm will be OFF\n",alarm_monitor_Pval);
	stop_alarm();
}
