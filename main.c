#include "APP/APP.h"
#include "APP/State_Machine.h"


void main(void){

				/*****  initialization of the (LCD - KEYPAD - Steppermotor)  *****/
	System_Init();

	while(1){

							/*****  State Machine  *****/
		state_machine();

	}



}


