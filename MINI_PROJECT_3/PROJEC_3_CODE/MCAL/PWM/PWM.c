/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for the AVR PWM driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/


#include "../../STD_LIBRARIES/common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h"
#include "../GPIO/gpio.h"
#include "PWM.h"

void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*1- Fast PWM Mode WGM01=1 & WGM00=1 */
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
	/*2-(non inverted mode) COM00=0 & COM01=1*/
	CLEAR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	/*3-clock = F_CPU/8 CS00=0 CS01=1 CS02=0 */
	CLEAR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
    /*4- Timer Initial Value =0*/
	TCNT0 =0;
	/*5- Timer Compare value in percentage */
	OCR0 = ((duty_cycle*.01)*MAX_FOR_TIMER_REG);
	//OCR0 =duty_cycle;
	//SET PB3 As An Output Pin "OC0_PIN"
	GPIO_setupPinDirection (PORTB_ID , PIN3_ID , PIN_OUTPUT);

}


