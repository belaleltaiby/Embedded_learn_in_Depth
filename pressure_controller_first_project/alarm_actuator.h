/*
 * alarm_actuator.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_
#include "pressure_sensor.h"

enum alarm_state{
	alarm_OFF,
	alarm_ON
};
//methods declaration
void start_alarm();
void stop_alarm();
void alarm_actuator_init();
//global pointer to function
//void (*alarm_actuator)();


#endif /* ALARM_ACTUATOR_H_ */
