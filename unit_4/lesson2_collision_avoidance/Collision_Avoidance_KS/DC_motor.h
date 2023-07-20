/*
 * DC_motor.h
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state_machine.h"

enum{
	DC_busy,
	DC_idle
}DC_state_id;

void DC_init();
STATE_define(_DC_busy_);
STATE_define(_DC_idle_);
void DC_motor(int s );

void (*DC_state)();

#endif /* DC_MOTOR_H_ */
