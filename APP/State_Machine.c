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

	switch(state){
		case NEW_PASSWORD:

			print_enter_new_password();
			password = get_password();
			state = CONFIRM_PASSWORD;

		break;
		case MASTER_MODE:

		break;
		case CONFIRM_PASSWORD:

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

