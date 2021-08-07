#ifndef STEPPER_CONF_H_
#define STEPPER_CONF_H_

#include "../../MCAL/GPIO/GPIO_CONFIG.h"



#define MOTOR_PORT				PORT_D
#define PIN0					0
#define PIN1					1
#define PIN2					2
#define PIN3					3
#define PIN4					4
#define PIN5					5


#define MOTOR_TYPE				UNIPOLAR
#define STEP_SEQUENCE_TYPE 		NORMAL_STEP_SEQUENCE_4
#define MOTOR_DIRECTION 		CLOCKWISE




/*************************************************************/
#define UNIPOLAR	1
#define BIPOLAR 	2
#define UNIVERSAL 	3


#define NORMAL_STEP_SEQUENCE_4 	0
#define HALF_STEP_SEQUENCE_8 	1


#define CLOCKWISE 			0
#define ANTI_CLOCKWISE 		1


#endif /* STEPPER_CONF_H_ */
