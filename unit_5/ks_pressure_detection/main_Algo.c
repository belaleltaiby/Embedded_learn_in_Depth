#include "main_Algo.h"
extern void Psensor_busy();
extern void stop_alarm();
extern void start_alarm();

extern int Pval;
int threshold = 20;

void Set_Pressure_val(int V)
{
	Pval = V ;
	//(Pval > threshold)? (Pmain_Algo = state_start_alarm ):(Pmain_Algo = state_stop_alarm);
	if(Pval > threshold)
	{
		Pmain_Algo = state_start_alarm ;
	}else{
		Pmain_Algo = state_stop_alarm ;
	}
	
}

void state_start_alarm()
{
	start_alarm();
	//(Pval > threshold)? (Pmain_Algo = state_start_alarm ):(Pmain_Algo = state_stop_alarm);

	Pmain_Algo = Psensor_busy;
}

void state_stop_alarm()
{
	stop_alarm();
	//(Pval > threshold)? (Pmain_Algo = state_start_alarm ):(Pmain_Algo = state_stop_alarm);

	Pmain_Algo = Psensor_busy;
}