#include "Keypad.h"
#include "Keypad_Config.h"


static const UINT8 keypad_array[COL][ROW] =  { KEYPAD_ARRAY };   //more readable


void Keypad_Init(void){
  
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, R1_PIN, OUTPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, R2_PIN, OUTPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, R3_PIN, OUTPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, R4_PIN, OUTPUT);

	GPIO_WRITE_PIN_VALUE(KEYPAD_PORT, R1_PIN, type_of_connection);
	GPIO_WRITE_PIN_VALUE(KEYPAD_PORT, R2_PIN, type_of_connection);
	GPIO_WRITE_PIN_VALUE(KEYPAD_PORT, R3_PIN, type_of_connection);
	GPIO_WRITE_PIN_VALUE(KEYPAD_PORT, R4_PIN, type_of_connection);

	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, C1_PIN, INPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, C2_PIN, INPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, C3_PIN, INPUT);
	GPIO_INIT_PIN_DIRECTION(KEYPAD_PORT, C4_PIN, INPUT);

}


}


UINT8 Keypad_GetKey(void)
{
  UINT8 ROWCOUNT;
	UINT8 COLCOUNT;
	UINT8 RESULT;
	for(ROWCOUNT=ROW_INT; ROWCOUNT<=ROW_END ;ROWCOUNT++)
	{
		GPIO_WRITE_PIN_VALUE(PORT_B ,ROWCOUNT , LOW);
		for (COLCOUNT=COL_INT ;COLCOUNT<=COL_END ;COLCOUNT++)
		{
			if(GPIO_READ_PIN_VALUE(PORT_B,COLCOUNT)==LOW)
			{
				RESULT=keypad_array[ROWCOUNT][COLCOUNT-COL_INT];
				 /* because we don't use timer we use this condition for one press */
				while(GPIO_READ_PIN_VALUE(PORT_B,COLCOUNT)==LOW);
				
				_delay_ms(10);  //to avoid bouncing
			}
			
		}
    
		GPIO_WRITE_PIN_VALUE(PORT_B ,ROWCOUNT , HIGH);  //deactivate again
	}

   return RESULT;


}
