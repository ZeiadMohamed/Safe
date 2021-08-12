#include "APP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"

/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter New Pass
*/
void print_enter_new_password(void){

	LCD_Clear();
	LCD_WriteSentence(" Enter New Pass ");
}


/* 	 Function    : get_password
**   Parameters  : None
**   Return      : password
**   Description : It will get key from user , print '*' on LCD
*/
UINT8 get_password(void){

	UINT8 password;
	UINT8 i;
	LCD_2nd_Line();

	password = Keypad_GetKey();
	LCD_WriteData('*');

	for(i = 0;i<3;i++){
	  password *= 10 ;
	  password += Keypad_GetKey();
	  LCD_WriteData('*');
	}

	return password;
}



