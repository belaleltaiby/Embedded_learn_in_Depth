/*
 * US_senseor.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#include "US_sensor.h"


//variables module
int US_distance = 0;

int generate_random(int l, int r)
{
	int rand_num=(rand() % (r-l+1)) + l ;
	return rand_num;
}

void US_init()
{

	printf("US_init\n");
}

STATE_define(_US_busy_)
{
	//state action
	US_state_id = US_busy;

	printf("US_busy State : Distance =%d\n",US_distance);
	US_distance = generate_random(45, 55) ;
	US_set_distance(US_distance);
	US_state = STATE(_US_busy_);

}


