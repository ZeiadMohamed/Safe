#include "Stepper.h"
static UINT8 DELAY_TIME = 100;// to be able to change time in (ms)

static UINT8 motor_direction = MOTOR_DIRECTION;


void Stepper_Init(){
#if MOTOR_TYPE == UNIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_E, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_F, OUTPUT);

#elif MOTOR_TYPE == BIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);

#elif MOTOR_TYPE == UNIVERSAL

	GPIO_INIT_PORT_DIRECTION(MOTOR_PORT,OUTPUT);

#endif



}


void Stepper_SetSpeed(UINT8 speed)
{
	DELAY_TIME = (1/((STEPS_PER_REVOLUTION * speed)/60))*1000 ; // time in ms


}

void Stepper_SetDirection(UINT8 direction){
	switch(direction){
	case CLOCKWISE:
		motor_direction = CLOCKWISE;
		break;
	case COUNTER_CLOCKWISE:
		motor_direction = COUNTER_CLOCKWISE;
		break;
	}

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

