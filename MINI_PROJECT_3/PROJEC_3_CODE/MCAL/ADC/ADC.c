/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Shirehan Medhat
 *
 *******************************************************************************/



#include "../../STD_LIBRARIES/common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h"
#include "ADC.h"
/*
 * Vref = 2.56
 * prescaler = F_CPU_8
 *
 * */
void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*1- Reference Selection Bits "implemented by insertion" */
	ADMUX = (ADMUX & (0x3f)) | (((Config_Ptr->ref_volt)<<6) &0xc0);
	/*2- ADC Enable Bit*/
	SET_BIT(ADCSRA,ADEN);
	/*3- ADC INTERRUPT Disable*/
	CLEAR_BIT(ADCSRA,ADIE);
	/*4- Prescaler Selection Bits " implemented by insertion" */
	ADCSRA = (ADCSRA & 0xf8) | ((Config_Ptr->prescaler) & 0x07);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/*1- Insert Channel Number */
	ADMUX = (ADMUX & 0xE0 ) | (channel_num & 0x07);
	/*2- Start Conversion*/
	SET_BIT(ADCSRA,ADSC);
	/*3- Polling until the flag equal 1*/
	while (BIT_IS_CLEAR(ADCSRA,ADIF));
	/*4- Clear the Flag*/
	SET_BIT(ADCSRA,ADIF);
	/*5- Read Data*/
	return ADC;
}
