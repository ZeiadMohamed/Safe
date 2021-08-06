#include "Keypad.h"
#include "Keypad_Config.h"


static const UINT8 keypad_array[4][4] =  { KEYPAD_ARRAY };


void Keypad_Init(void){
  
  int row [4] = {R1_PIN, R2_PIN, R3_PIN, R4_PIN};// so i can loop in row pins instead of writing multiple lines
	int coloumb [4] = {C1_PIN, C2_PIN, C3_PIN, C4_PIN};// so i can loop in coloumb pins instead of writing multiple lines
	int i ;
	for (i=0; i<4; i++)
	{
		GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, row[i], OUTPUT);
		GPIO_WRITE_PIN_VALUE(KEYPAD_PORT, row[i], type_of_connection);
	}
	for (i=0; i<4; i++)
	{
		GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, coloumb[i], INPUT);
	}

}


}


UINT8 Keypad_GetKey(void){



}
