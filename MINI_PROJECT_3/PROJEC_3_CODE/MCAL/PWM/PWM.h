/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_
#include "../../STD_LIBRARIES/std_types.h"

/*
 * Description :
 * Function responsible for initialize the PWM TIMER0 driver.
 */
/*MACROS To represent The Max Number For Counting To Avoid Magic Numbers*/
#define MAX_FOR_TIMER_REG 255
void PWM_Timer0_Start(uint8 duty_cycle);
#endif /* MCAL_PWM_PWM_H_ */
