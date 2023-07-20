/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Belal
 */

#include "DC_motor.h"
#include "US_sensor.h"
#include "Collision_Avoidance.h"

void setup()
{
	DC_init();
	US_init();
	US_state = STATE(_US_busy_);
	DC_state = STATE(_DC_idle_);
	CA_state = STATE(_CA_waiting_);
}

int main()
{
	setup();
	while(1)
	{

		US_state();
		CA_state();
		DC_state();


	}
	return 0;
}
