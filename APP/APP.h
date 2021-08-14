#ifndef APP_H_
#define APP_H_


#include "../LIB/STD_TYPES.h"


#define MASTER_PASSWORD 8070


/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter New Pass "
*/
void print_enter_new_password(void);


/* 	 Function    : get_password
**   Parameters  : None
**   Return      : password
**   Description : It will get key from user , print '*' on LCD
*/
UINT8 get_password(void);


/* 	 Function    : print_enter_old_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints " enter old password " on LCD
*/
void print_enter_old_password(void);

/* 	 Function    : print_enter_master_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter master Password "
*/
void print_enter_master_password(void);


/* 	 Function    : print_enter_confirm_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter Confirmation Pass
*/
void print_enter_confirm_password(void);


/* 	 Function    : print_enter_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter Pass "
*/
void print_enter_password(void);


/* 	 Function    : key_or_pass
**   Parameters  : None
**   Return      : password or key
**   Description : It will get password from user , print '*' on LCD  or  get key from user
*/
UINT8 key_or_pass(void);


/* 	 Function    : open_safe
**   Parameters  : None
**   Return      : None
**   Description : It will determination of motor direction and open the safe
*/
void open_safe(void);


/* 	 Function    : close_safe
**   Parameters  : None
**   Return      : None
**   Description : It will close the safe
*/
void close_safe(void);


/* 	 Function    : wait_in_second
**   Parameters  : time
**   Return      : None
**   Description : It will wait for user enter seconds
*/
void wait_in_second(UINT8 time);


#endif /* APP_H_ */

