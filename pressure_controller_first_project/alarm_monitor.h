/*
 * alarm_monitor.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "pressure_sensor.h"
#include "alarm_monitor.h"
//methods declaration
void state_start_alarm();
void state_stop_alarm();
void high_pressure_detection(int val);

//global pointer to function
void (*alarmAction)();


#endif /* ALARM_MONITOR_H_ */
