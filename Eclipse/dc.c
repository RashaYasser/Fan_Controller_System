/*
 ============================================================================
 Module      : DC_Motor driver
 Name        : dc.c
 Layer       : HAL
 Author      : RASHA_YASSER
 Description : source file for interface  DC_Motor driver
 Date        : 11/10/2023
 ============================================================================
 */

#include"dc.h"
#include"gpio.h"
#include"common_macros.h"
#include"pwm.h"

void DcMotor_Init(void){
GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,PIN_OUTPUT);
GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,PIN_OUTPUT);
GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID,LOGIC_LOW);
GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID,LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
/*We Send The Speed To The PWM_driver To Make In It Some Calculations
 * And Put The Result in OCR0 To Generate PWM Signal In OC0*/
	T0_PWM_init(speed);
		if(state==CW){
			GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_LOW);
			GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_HIGH);

		 }
		else if(state==CCW){
			GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN1_ID,LOGIC_HIGH);
			GPIO_writePin(MOTOR_PORT_ID,MOTOR_PIN2_ID,LOGIC_LOW);

		 }
		else{
			GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID,LOGIC_LOW);
			GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID,LOGIC_LOW);
		 }
}
