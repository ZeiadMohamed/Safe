#include "Stepper.h"
static UINT8 DELAY_TIME = 100;// to be able to change time
static UINT8 RESOLUTION = 500;// resolution of the stepper motor




void Stepper_Init(){



}


void Stepper_SetSpeed(UINT8 speed){

  speed *= 60;
	DELAY_TIME = RESOLUTION/speed ;
}


void Stepper_SetDirection(UINT8 direction){


}


void Stepper_Step(UINT8 steps){


}

