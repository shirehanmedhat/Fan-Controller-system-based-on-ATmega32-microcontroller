/******************************************************************************
 *
 * Module: MAIN For Mini project 3
 *
 * File Name: MAIN.h
 *
 * Description: Header file for the Application Layer.
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#ifndef APP_MAIN_H_
#define APP_MAIN_H_
#include "../STD_LIBRARIES/std_types.h"
/*Macros for the required percentage*/
#define ZERO 0
#define QUARTER_PERCENT 25
#define HALF_PERCENT    50
#define THREE_QUARTER_PERCENT 75
#define HUNDRED_PERCENT 100
/*
 * Function To initialize all the devices needed
 * */
void ALL_INIT(void);
/*
 * Function To Display the Temperature By LCDS
 * input argument : temperature reading
 * */
void DISPLAY (uint16 TEMP_READING);
/*
 * Function to control the motor speed depending on the temperature
 * input argument : temperature reading
 *
 * */
void Motor_Movement (uint16 TEMP_READING);
#endif /* APP_MAIN_H_ */
