
#include "State_Machine.h"
#include "APP.h"

/****************************************************
*  					Global Variables  			    *
*****************************************************/

typedef enum {NEW_PASSWORD , MASTER_MODE , CONFIRM_PASSWORD , OLD_PASSWORD , ENTER_PASSWORD , OPEN_SAFE , CLOSE_SAFE}State;

static State state = NEW_PASSWORD;


static UINT8 password;


/****************************************************
*  					Functions						*
*****************************************************/




/* 	 Function    : state_machine
**   Parameters  : None
**   Return      : None
**   Description : It will make the state machine
*/
void state_machine(void){
	UINT8 pass ;
	switch(state){
		case NEW_PASSWORD:

			print_enter_new_password();
			password = get_password();
			state = CONFIRM_PASSWORD;

		break;
		case MASTER_MODE:

		break;
		case CONFIRM_PASSWORD:

			print_enter_confirm_password();   //Display Confirmation Text
			pass = get_password();            //Function To Get Confirm Password
			if(pass != password)              //Comparing With Default Password
			{
				state = NEW_PASSWORD;
			}
			else
				state = OPEN_SAFE;

		break;
		case OLD_PASSWORD:

		break;
		case ENTER_PASSWORD:

		break;
		case OPEN_SAFE:

		break;
		case CLOSE_SAFE:

		break;


	}


}

=======
#include "State_Machine.h"
#include "APP.h"


/****************************************************
*  					Global Variables  			    *
*****************************************************/

typedef enum {NEW_PASSWORD , MASTER_MODE , CONFIRM_PASSWORD , OLD_PASSWORD , ENTER_PASSWORD , OPEN_SAFE , CLOSE_SAFE}State;

static State state = NEW_PASSWORD;


static UINT8 password;


/****************************************************
*  					Functions						*
*****************************************************/




/* 	 Function    : state_machine
**   Parameters  : None
**   Return      : None
**   Description : It will make the state machine
*/
void state_machine(void){


	UINT8 counter = 0; // used to count number of mistakes the user will enter the password wrong


	UINT8 check_master;

	switch(state){
		case NEW_PASSWORD:

			print_enter_new_password();
			password = get_password();
			state = CONFIRM_PASSWORD;

		break;
		case MASTER_MODE:
			print_enter_master_password();
            check_master = get_password();

            if( check_master != MASTER_PASSWORD )
            	state = MASTER_MODE ;
            else
            	state = NEW_PASSWORD;
		break;
		case CONFIRM_PASSWORD:

		break;
		case OLD_PASSWORD:

			print_enter_old_password();

			/* checks if the password user entered "correct" or "wrong"
			 * - correct ---->>>>   goes to "NEW_PASSWORD" state machine
			 * - false   ---->>>>  increment the counter by 1 and return to "OLD_PSSWORD" state machine
			 */
			if (get_password() == password)
			{
				state = NEW_PASSWORD;
				counter = 0;
			}
			else
			{
				counter += 1;
				state = OLD_PASSWORD;
			}
			if (counter == 3)
			{
				counter = 0 ;
				state = MASTER_MODE;
			}


			break;
		case ENTER_PASSWORD:

		break;
		case OPEN_SAFE:

		break;
		case CLOSE_SAFE:

		break;


	}


}


