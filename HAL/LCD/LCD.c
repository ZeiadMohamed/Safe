#include "LCD.h"
#include "util/delay.h"



static void LCD_WriteCommand(UINT8 Command)
{

}

void LCD_Init(void)
{


}

void LCD_WriteData(UINT8 Data)
{
	
}




void LCD_WriteSentence(UINT8 *PtrSentance)
	
{
    UINT8 i=0;
	
	while( PtrSentance[i] != '\0' )
	{
	  LCD_WriteData( PtrSentance[i] ) ;
          i++ ;
        }	

}

void LCD_Clear(void)
{

	

}
