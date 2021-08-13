
#ifndef APP_H_
#define APP_H_

#include "../LIB/STD_TYPES.h"


/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter New Pass
*/
void print_enter_new_password(void);


/* 	 Function    : get_password
**   Parameters  : None
**   Return      : password
**   Description : It will get key from user , print '*' on LCD
*/
UINT8 get_password(void);

/* 	 Function    : print_enter_confirm_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter Confirmation Pass
*/
void print_enter_confirm_password(void);


#endif /* APP_H_ */
=======
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



#endif /* APP_H_ */

