/*
 * US_sensor.h
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_
#include "state_machine.h"


enum{
	US_busy
}US_state_id;

void US_init();

STATE_define(_US_busy_);

//global pointer to function
void  (*US_state)();

#endif /* US_SENSOR_H_ */
