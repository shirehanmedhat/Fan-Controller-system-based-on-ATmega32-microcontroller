 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "../../STD_LIBRARIES/std_types.h"
/*include ADC here as we need the structure */
#include "../../MCAL/ADC/ADC.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
void LM35_INIT(void);
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
