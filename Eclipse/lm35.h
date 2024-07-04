/*
 ============================================================================
 Module      : LM35
 Name        : lm35.h
 Layer       : HAL
 Author      : RASHA_YASSER
 Description : source file for interface  Lm35 driver
 Date        : 9/10/2023
 ============================================================================
 */

#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"

#define LM35_MAX_TEMP  150
#define LM35_MAX_VOLT  1.5 /*10mV per celsius*/


#define LM35_CHANNEL_ID  2

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint16 LM35_getTemperature();



#endif /* LM35_H_ */
