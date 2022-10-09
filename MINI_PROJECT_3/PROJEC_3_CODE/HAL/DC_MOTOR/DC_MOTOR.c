/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DC_MOTOR.c
 *
 * Description: Source file for the DC MOTOR driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/
#include <util/delay.h> /* For the delay functions */
#include "../../STD_LIBRARIES/common_macros.h" /* For GET_BIT Macro */
#include "DC_MOTOR.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/PWM.h"

void DcMotor_Init(void)
{
   /*Configure the H-bridge pins as an output*/
	GPIO_setupPinDirection (PORTB_ID , PIN0_ID , PIN_OUTPUT);
	GPIO_setupPinDirection (PORTB_ID , PIN1_ID , PIN_OUTPUT);
	/*the initial Value is LOW*/
	GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_LOW);
	GPIO_writePin (PORTB_ID , PIN1_ID , LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*initialization Of PWM Timer0 Peripheral*/
	PWM_Timer0_Start (speed);

	/*The OutPut State Depending On The Input Argument State*/
	switch (state)
	{
	case CW:
		GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_LOW);
		GPIO_writePin (PORTB_ID , PIN1_ID , LOGIC_HIGH);
		break;
	case A_CW:

		GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_HIGH);
		GPIO_writePin (PORTB_ID , PIN1_ID , LOGIC_LOW);
		break;
	}
	if (0== speed)
	{
		GPIO_writePin (PORTB_ID , PIN0_ID , LOGIC_LOW);
		GPIO_writePin (PORTB_ID , PIN1_ID , LOGIC_LOW);
	}
}

