/*
 ============================================================================
 Module      : ADC
 Name        : adc.c
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : source file for interface the AVR ADC driver the configuration technique
               based on the polling design.
 Date        : 28/9/2023
 ============================================================================
 */
#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*Here We Select If We Want The Voltage Reference To Be AREF Or AVCC Or Internal*/
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6); /*clear bits 7,6 and put the value on them*/


	ADCSRA = (1<<ADEN);/*Enable ADC*/

	/*Here We Adjust The Pre_scaler
	 * By Clearing The First 3 Bits In ADCSRA Register
	 *  And Then Inserting The Pre_scaler In Them*/
	ADCSRA=(ADCSRA&0xF8)|((Config_Ptr->prescaler));/*clear 2,1,0 */
}


uint16 ADC_readChannal(uint8 channal_num){

	ADMUX=(ADMUX&0xE0)|(channal_num);  /*clear 5 pin 11100000 and set channel number */

	SET_BIT(ADCSRA,ADSC);
	/* Start conversion write 1 to ADSC
	 *chose set_bit to control  one pin
	 *  */

	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1'*/

	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it */

	return ADC; /* Read the digital value from the data register */
   /*NOTE THE POLLING MAKE FUNCTION SYNCHRONOUS TISH MEAN FUNCTION REURNS RESULT OF REQUEST  */
}



