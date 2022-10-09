 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#include "lm35_sensor.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
ADC_ConfigType VAR = {INTERNAL_2_56,F_CPU_8};

void LM35_INIT(void)
{
	ADC_init(&VAR);
}
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 ADC_READING = 0;

	/* Read ADC channel where the temperature sensor is connected */
	ADC_READING = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	/* Casting For Internal And External Operations*/
	temp_value = (uint8)(((uint32)ADC_READING*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

