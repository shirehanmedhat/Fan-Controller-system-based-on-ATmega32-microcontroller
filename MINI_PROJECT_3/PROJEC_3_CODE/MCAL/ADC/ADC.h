/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_
#include "../../STD_LIBRARIES/std_types.h"

/*1- Typedefs For the New Data Types */
typedef enum
{
	INTERNAL_IS_OFF,AVCC_EX,RESERVED,INTERNAL_2_56
}ADC_ReferenceVolatge;

typedef enum
{
	NO_CLOCK,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*2- Macros For The Sensor In the Upper Layer*/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*3- Function Prototypes*/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);
#endif /* ADC_H_ */
