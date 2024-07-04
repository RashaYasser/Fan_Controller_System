/*
 ============================================================================
 Module      : T0_PWM
 Name        : pwm.h
 Layer       : MCAL
 Author      : RASHA_YASSER
 Description : Header file for interface the pwm on Timer0 fast mode
 Date        : 28/9/2023
 ============================================================================
 */
#ifndef PWM_H_
#define PWM_H_
#include"std_types.h"
#define MAX_COUNT  256
void T0_PWM_init(uint8 duty_cycle);


#endif /* PWM_H_ */
