/*
 ============================================================================
 Module      : T0_PWM
 Name        : pwm.c
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : source file for interface  PWM driver
 Date        : 12/10/2023
 ============================================================================
 */
#include <avr/io.h>
#include "pwm.h"

void T0_PWM_init(uint8 duty_cycle){
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	TCNT0=0;
	OCR0=(uint8)(((float32)duty_cycle/100)*MAX_COUNT);
	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.
}


