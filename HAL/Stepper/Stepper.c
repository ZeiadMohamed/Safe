#include "Stepper.h"
static UINT8 DELAY_TIME = 100;// to be able to change time in (ms)




void Stepper_Init(){



}


void Stepper_SetSpeed(UINT8 speed)
{
	DELAY_TIME = (1/((STEPS_PER_REVOLUTION * speed)/60))*1000 ; // time in ms


}

void Stepper_SetDirection(UINT8 direction){


}


void Stepper_Step(UINT8 steps){


}

