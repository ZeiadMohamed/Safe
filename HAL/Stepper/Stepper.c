#include "Stepper.h"
#include "../../LIB/UTILES.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <util/delay.h>

static volatile enum {STATE_1,STATE_2,STATE_3,STATE_4}Motor_Step_Sequence_State_Clockwise,Motor_Step_Sequence_State_CounterClockwise;


static volatile UINT8 time_between_steps ;



void Stepper_Init(){

	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);

	 Motor_Step_Sequence_State_Clockwise = STATE_1;
	 Motor_Step_Sequence_State_CounterClockwise = STATE_1;
	 time_between_steps = TIME_BETWEEN_STEPS;
}


void Stepper_Set_Time_Per_Revolution(UINT16 time_ms){
	time_between_steps = time_ms / STEPS_PER_REVOLUTION; // time in milliseconds

}



void Stepper_Half_Revoloution(UINT8 direction){
	UINT8 steps = STEPS_PER_REVOLUTION>>1 ;//Divided by 2
	Stepper_Steps(steps,direction);

}

void Stepper_Full_Revoloution(UINT8 direction){
	Stepper_Steps(STEPS_PER_REVOLUTION,direction);
}


#if MOTOR_TYPE == UNIPOLAR

static void Stepper_One_Step_Clockwise(void){

	switch(Motor_Step_Sequence_State_Clockwise){
		case STATE_1:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);

		Motor_Step_Sequence_State_Clockwise = STATE_2;
		Motor_Step_Sequence_State_CounterClockwise = STATE_1;
		break;
		case STATE_2:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);

		Motor_Step_Sequence_State_Clockwise = STATE_3;
		Motor_Step_Sequence_State_CounterClockwise = STATE_2;
		break;
		case STATE_3:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);

		Motor_Step_Sequence_State_Clockwise = STATE_4;
		Motor_Step_Sequence_State_CounterClockwise = STATE_3;
		break;
		case STATE_4:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);

		Motor_Step_Sequence_State_Clockwise = STATE_1;
		Motor_Step_Sequence_State_CounterClockwise = STATE_4;
		break;
	}


}

static void Stepper_One_Step_CounterClockwise(void){


	switch(Motor_Step_Sequence_State_CounterClockwise){
		case STATE_1:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);

		Motor_Step_Sequence_State_CounterClockwise = STATE_4;
		Motor_Step_Sequence_State_Clockwise = STATE_1;
		break;
		case STATE_2:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);

		Motor_Step_Sequence_State_CounterClockwise = STATE_1;
		Motor_Step_Sequence_State_Clockwise = STATE_2;
		break;
		case STATE_3:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);

		Motor_Step_Sequence_State_CounterClockwise = STATE_2;
		Motor_Step_Sequence_State_Clockwise = STATE_3;
		break;
		case STATE_4:
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
		GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);

		Motor_Step_Sequence_State_CounterClockwise = STATE_3;
		Motor_Step_Sequence_State_Clockwise = STATE_4;
		break;
	}



}


void Stepper_Steps(UINT8 steps,UINT8 direction){
	UINT8 i ;

	if(direction == CLOCKWISE){
		for(i = 0;i<=steps;i++){
		  Stepper_One_Step_Clockwise();
		  _delay_ms(time_between_steps);
		}
	}
   else if(direction == COUNTER_CLOCKWISE){
		for(i = 0;i<=steps;i++){
		  Stepper_One_Step_CounterClockwise();
		  _delay_ms(time_between_steps);
		}
   }
}


#elif MOTOR_TYPE == BIPOLAR



#endif



