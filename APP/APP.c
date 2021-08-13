#include "APP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"

/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter New Pass "
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

/******* converting from ASCII to integer (Decimal) *******/
	password = Keypad_GetKey() - '0'; //'0' = 48 in ASCII
	LCD_WriteData('*');

/******* Getting password one digit at a time *******/
	for(i = 0;i<3;i++){
	  password *= 10 ;
	  password += Keypad_GetKey() - '0'; //'0' = 48 in ASCII
	  LCD_WriteData('*');
	}

	return password;
}



/*   Function    : print_enter_confirm_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter Confirmation Pass
*/
void print_enter_confirm_password(void)
{
	LCD_Clear();
	LCD_WriteSentence(" Confirm Pass ");
}



/* 	 Function    : print_enter_master_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter master Password "
*/
void print_enter_master_password(void){

	LCD_Clear();
	LCD_WriteSentence("Master password:");
}

/* 	 Function    : print_enter_old_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints enter old password on LCD
*/
void print_enter_old_password(void){

	LCD_Clear();
	LCD_1st_Line();
	LCD_WriteSentence(" Enter Old Pass ");
}











