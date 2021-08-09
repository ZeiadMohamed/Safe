#include "Stepper.h"





void Stepper_Init(){



}


void Stepper_SetSpeed(UINT8 speed){


}


void Stepper_SetDirection(UINT8 direction){


}


void Stepper_Step(UINT8 steps){
switch(steps){
case NORMAL_STEP_SEQUENCE_4:
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x09);  // A & D are high
	_delay_ms(DELAY_TIME);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x0C);  // A & B are high
	_delay_ms(DELAY_TIME);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x06);  // B & C are high
	_delay_ms(DELAY_TIME);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x03);  // C & D are high
	_delay_ms(DELAY_TIME);
	break;
    
case HALF_STEP_SEQUENCE_8:
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x08);  // A & D are high
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x0C);  // A is high only
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x04);  // A & B are high
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x06);  // B is high only
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x02);  // B & C are high
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x03);  // C is high only
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x01);  // C & D are high
	_delay_ms(DELAY_TIME/2);
	GPIO_WRITE_PORT_VALUE(MOTOR_PORT , 0x09);  // D is high only
	_delay_ms(DELAY_TIME/2);
	break;
    
case WAVE_STEP_SEQUENCE_4:
	   /*  I NEED SOME TIME   */

}

}

