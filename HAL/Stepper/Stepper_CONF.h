#ifndef STEPPER_CONF_H_
#define STEPPER_CONF_H_

#include "../../MCAL/GPIO/GPIO_CONFIG.h"



#define MOTOR_PORT				PORT_D
#define WINDING_A				3
#define WINDING_B				2
#define WINDING_C				1
#define WINDING_D				0



#define MOTOR_TYPE				UNIPOLAR
#define STEPS_PER_REVOLUTION    48
#define TIME_BETWEEN_STEPS		50   //time in milliseconds



/*************************************************************/
#define UNIPOLAR	1
#define BIPOLAR 	2


#define NORMAL_STEP_SEQUENCE_4 	0
#define HALF_STEP_SEQUENCE_8 	1
#define WAVE_STEP_SEQUENCE_4	2

#define CLOCKWISE 				0
#define COUNTER_CLOCKWISE 		1


#endif /* STEPPER_CONF_H_ */
