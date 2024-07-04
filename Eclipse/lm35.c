/*
 ============================================================================
 Module      : LM35
 Name        : lm35.c
 Layer       : HAL
 Author      : RASHA_YASSER
 Description : source file for interface  Lm35 driver
 Date        : 9/10/2023
 ============================================================================
 */

#include"lm35.h"
#include"common_macros.h"
#include"adc.h"


uint16 LM35_getTemperature(){

	uint16 adc_value=0;  /*ADC 10 bit*/
	uint8  temp=0;
	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannal(LM35_CHANNEL_ID); /*use adc polling "return function"*/

	temp=(uint8)(((uint32)adc_value*LM35_MAX_TEMP*ADC_REF_VOLT)/(ADC_MAX_VALUE*LM35_MAX_VOLT));
	return temp;

}
