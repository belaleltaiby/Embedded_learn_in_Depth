/*
 * Collision_Avoidance.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#include "Collision_Avoidance.h"



unsigned int CA_distance = 0;
unsigned int CA_speed = 0;
unsigned int CA_threshold = 50;


void US_set_distance(int d)
{
	CA_distance = d;
	(CA_distance > CA_threshold)?(CA_state = STATE(_CA_driving_)):(CA_state = STATE(_CA_waiting_));
	printf("US---------->distance=%d ------->CA\n",CA_distance);
}

STATE_define(_CA_driving_){
	CA_states_id = CA_driving;
	printf("CA_driving state : distance =%d \t speed = %d\n",CA_distance,CA_speed);
	//state actions
	CA_speed = 30;
	DC_motor(CA_speed);

}

STATE_define(_CA_waiting_){
	CA_states_id = CA_waiting; ////?????
	printf("CA_waiting state : distance =%d \tspeed = %d\n",CA_distance,CA_speed);
	//state action
	CA_speed = 0;
	DC_motor(CA_speed);

}
