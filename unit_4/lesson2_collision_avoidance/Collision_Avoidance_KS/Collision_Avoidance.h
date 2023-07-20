/*
 * Collision_Avoidance.h
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_

#include "state_machine.h"

//global pointer to function
void (*CA_state)();
enum{
	CA_waiting,
	CA_driving
}CA_states_id;

//prototypes
void US_set_distance(int d);

STATE_define(_CA_waiting_);
STATE_define(_CA_driving_);



#endif /* COLLISION_AVOIDANCE_H_ */
