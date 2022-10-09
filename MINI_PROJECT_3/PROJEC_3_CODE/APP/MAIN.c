/******************************************************************************
 *
 * Module: MAIN For Mini project 3
 *
 * File Name: MAIN.c
 *
 * Description: Source file for the Application Layer
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#include "../HAL/LCD/LCD.h"
#include "../HAL/LM35/lm35_sensor.h"
#include "../HAL/DC_MOTOR/DC_MOTOR.h"
#include "MAIN.h"
int main (void)
{
	ALL_INIT();
	LCD_displayStringRowColumn (0,3,"FAN IS ");
	LCD_displayStringRowColumn (1,3,"Temp =    C");


	while(1)
	{

		uint16 LOC_TEMP_READING = LM35_getTemperature ();
		DISPLAY (LOC_TEMP_READING);
		Motor_Movement (LOC_TEMP_READING);


	}

}

/*
 * Function To Display the Temperature By LCDS
 * */
void DISPLAY (uint16 TEMP_READING)
{
	/*Move to the place determined to put the temp*/
	LCD_moveCursor (1,10);
	/*Print the Temp*/
	LCD_intgerToString(TEMP_READING);
	/*Leave a space instead of the last member*/
	if (TEMP_READING <100)
	{
		LCD_displayCharacter (' ');
	}
	/*statement to print the state whether ON or OFF*/
	if (TEMP_READING <30)
	{
		LCD_moveCursor (0,10);
		LCD_displayString ("OFF");
	}
	else
	{
		LCD_moveCursor (0,10);
		LCD_displayString ("ON");
		LCD_displayCharacter (' ');
	}

}

void Motor_Movement (uint16 TEMP_READING)
{

	if (TEMP_READING <30)
		{
		/*If the temperature is less than 30C turn off the fan*/

			DcMotor_Rotate (CW ,ZERO );
		}

		else if ((TEMP_READING >=30) && (TEMP_READING <60))
		{
			/*If the temperature is greater than or equal 30C
			 * turn on the fan with 25% of its maximum speed.*/
			DcMotor_Rotate (CW ,QUARTER_PERCENT );
		}
		else if ((TEMP_READING >=60) && (TEMP_READING <90))
		{
			/*If the temperature is greater than or equal 60C turn on the fan
			 * with 50% of its maximum speed.*/

			DcMotor_Rotate (CW ,HALF_PERCENT );
		}
		else if ((TEMP_READING >=90) && (TEMP_READING <120))
		{
			/*If the temperature is greater than or equal 90C turn on the fan
			 *  with 75% of its maximum speed.
			 * */

			DcMotor_Rotate (CW ,THREE_QUARTER_PERCENT );
		}
		else if ((TEMP_READING >=120) )
		{
			/*If the temperature is greater than or equal 120C turn on the fan
			 *  with 100% of its maximum speed.*/

			DcMotor_Rotate (CW ,HUNDRED_PERCENT );
		}
}



/*
 * Function To initialize all the devices needed
 * */

void ALL_INIT(void)
{
	/*Initialize the temp sensor*/
	LM35_INIT ();
	/*Initialize the LCD */
	LCD_init ();
	/*Initialize the DC Motor*/
	DcMotor_Init();

}

