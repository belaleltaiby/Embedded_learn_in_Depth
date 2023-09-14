/*
 * pressure_sensor.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "stdio.h"
#define Dprintf(...)  {fflush(stdout);\
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin); \
}

//methods declaration
void init();
int generate_random(int l, int r);
void state_Psensor_busy();
void Psensor_init();
//global pointer to function
void (*Psensor)();


#endif /* PRESSURE_SENSOR_H_ */
