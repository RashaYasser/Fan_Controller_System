/*
 ============================================================================
 Module      : DC_Motor driver
 Name        : dc.h
 Layer       : HAL
 Author      : RASHA_YASSER
 Description : Header file for interface  DC_Motor driver
 Date        : 11/10/2023
 ============================================================================
 */


#ifndef DC_H_
#define DC_H_
#include "std_types.h"

#define MOTOR_PORT_ID   PORTB_ID
#define MOTOR_PIN1_ID   PIN0_ID
#define MOTOR_PIN2_ID   PIN1_ID

typedef enum {
	stop,CW,CCW
}DcMotor_State;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_H_ */
