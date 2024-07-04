/*
 ============================================================================
 Module      : ADC
 Name        : adc.h
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : header file for interface the AVR ADC driver
 Date        : 28/9/2023
 ============================================================================
 */


#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

#define ADC_REF_VOLT   2.56
#define ADC_MAX_VALUE  1023 /*10 bit 2^10 */

typedef enum
{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannal(uint8 channal_num);

#endif /* ADC_H_ */
