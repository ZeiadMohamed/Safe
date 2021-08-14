#include "APP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/Stepper/Stepper.h"
#include <util/delay.h>  // so i can use _dealy_ms() function

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


/* 	 Function    : print_enter_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints " Enter Password " on LCD
*/
void print_enter_password(void){

	LCD_Clear();
	LCD_1st_Line();
	LCD_WriteSentence(" Enter Pass ");
}


/* 	 Function    : key_or_pass
**   Parameters  : None
**   Return      : password or key
**   Description : It will get password from user , print '*' on LCD  or  get key from user
*/
UINT8 key_or_pass(void)
{
	UINT8 password;
	UINT8 i;
	UINT8 key;
	LCD_2nd_Line();

	key = Keypad_GetKey();

	if (key == 'C')
	{
		return key;
	}
	else
	{

	/******* converting from ASCII to integer (Decimal) *******/
		password = key - '0'; //'0' = 48 in ASCII
		LCD_WriteData('*');

	/******* Getting password one digit at a time *******/
		for(i = 0;i<3;i++){
		  password *= 10 ;
		  password += Keypad_GetKey() - '0'; //'0' = 48 in ASCII
		  LCD_WriteData('*');
		}

		return password;
	}
}

/* 	 Function    : open_safe
**   Parameters  : None
**   Return      : None
**   Description : It will open the safe
*/
void open_safe(void){
	Stepper_SetDirection(CLOCKWISE);
	Stepper_Half_Revoloution();
}

/* 	 Function    : close_safe
**   Parameters  : None
**   Return      : None
**   Description : It will close the safe
*/
void close_safe(void){
	Stepper_SetDirection(COUNTER_CLOCKWISE);
	Stepper_Half_Revoloution();
}

/* 	 Function    : wait_in_second
**   Parameters  : time
**   Return      : None
**   Description : It will wait for user enter seconds
*/
void wait_in_second(UINT8 time){
	_delay_ms(1000*time);
}











