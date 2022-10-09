/******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: DC_MOTOR.c
 *
 * Description: Header file for the DC MOTOR driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_
#include "../../STD_LIBRARIES/std_types.h"

typedef enum {CW , A_CW}DcMotor_State ;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
