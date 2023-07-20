/*
 * DC_motor.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Belal
 */

#include "DC_motor.h"

unsigned int DC_speed=0;

void DC_init()
{

	printf("DC_init\n");
}


void DC_motor(int s )
{
	DC_speed = s;

	(DC_speed == 0)?(DC_state = STATE(_DC_idle_)):(DC_state = STATE(_DC_busy_));
	printf("CA------->speed=%d--------->DC\n",DC_speed);

}

STATE_define(_DC_busy_)
{
	DC_state_id = DC_busy;
	printf("DC_busy_state : speed = %d\n",DC_speed);

}
STATE_define(_DC_idle_)
{
	DC_state_id = DC_idle;
	DC_state=STATE(_DC_idle_);

	printf("DC_idle_state : speed = %d\n",DC_speed);
}

