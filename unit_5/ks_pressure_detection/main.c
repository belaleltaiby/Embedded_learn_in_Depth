#include "pressure_sensor.h"
#include "alarm_actuator.h"
//#include "alarm_monitor.h"
#include "main_Algo.h"
#include "driver.h"

void setup()
{
	GPIO_INITIALIZATION();
	Psensor_init();
	alarm_actuator_init();
	
	Ppsensor          = Psensor_busy;
	Pmain_Algo 		  = state_stop_alarm ;
	Palarm_actuator   = stop_alarm ;
}

int main()
{
	setup();
	while(1)
	{

		Ppsensor();
		Pmain_Algo();
		//Palarm_actuator();
		Delay(70000);
	}
	return 0;
}
