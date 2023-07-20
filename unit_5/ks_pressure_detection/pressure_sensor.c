#include "pressure_sensor.h"
#include "driver.h"

int Pval;

void Psensor_init()
{
	Pval = 0;
	Ppsensor = Psensor_busy;
	
}

void Psensor_busy()
{
	Pval = getPressureVal();
	Set_Pressure_val(Pval);
	Delay(6000);
	Ppsensor = Psensor_busy;
}