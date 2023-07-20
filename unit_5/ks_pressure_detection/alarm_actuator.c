#include "alarm_actuator.h"
#include "driver.h"

void alarm_actuator_init()
{
	Palarm_actuator = stop_alarm;
}


void start_alarm()
{
	 Set_Alarm_actuator(0);
	 Delay(500000);
	 stop_alarm();
}


void stop_alarm()
{
	Set_Alarm_actuator(1);
}