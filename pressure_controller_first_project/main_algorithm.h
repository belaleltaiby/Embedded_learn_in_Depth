/*
 * main_algorithm.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Belal
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_
#include "pressure_sensor.h"

//methods declaration
void Psensor_set_Pvalue(int val);
void state_high_pressure();
void state_low_pressure();

//global pointer to function
void (*Pressure_detected)();

#endif /* MAIN_ALGORITHM_H_ */
