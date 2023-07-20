#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_

#include "driver.h"

//methods
void state_start_alarm();
void state_stop_alarm();
void Set_Pressure_val(int V);

//pointer to fun
void(*Pmain_Algo)();



#endif