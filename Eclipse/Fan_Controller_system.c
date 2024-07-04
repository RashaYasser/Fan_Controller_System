/*
 ============================================================================
 Name        : Fan_Controller_system.c
 Layer       : APP
 Author      : RASHA_YASSER
 Description : Fan Controller system
 Date        : 12/10/2023
 ============================================================================
 */
#include"std_types.h"
#include"common_macros.h"
#include "lm35.h"
#include"dc.h"
#include"lcd.h"
#include"adc.h"/*For ADC_init*/
#include<util/delay.h>


int main(){
	uint8 temp=0;

	LCD_init();

	DcMotor_Init();
	ADC_ConfigType ADC_Configurations = {F_CPU_8,INTERNAL};/*Define The Prescalar And The Reference Voltage We Want To Use In The In The Project  */
	ADC_init(&ADC_Configurations);/*Initialize ADC By Sending The Address Of The Struct */
	LCD_moveCursor(0,4);/*Move Cursor To Row :0 And Column :4*/
	LCD_displayString(" By Rasha ");/*Display This String In ROw :0 And Column:4*/
    LCD_displayCharacter('  ');

    _delay_ms(100);
	LCD_moveCursor(0,4);/*Move Cursor To Row :0 And Column :4*/
	LCD_displayString("FAN IS ");/*Display This String In ROw :0 And Column:4*/
	while(1){
		temp=LM35_getTemperature();

		if(temp<30)
		{
        DcMotor_Rotate(stop,0);
        LCD_moveCursor(0,11);
        LCD_displayString("OFF");
        LCD_moveCursor(1,4);
        LCD_displayString("temp=");
        LCD_moveCursor(1,9);
        if(temp<10)
        {/* In case the digital value is one digits print space in the next digit place */
        LCD_intgerToString(temp);
        LCD_displayCharacter(' ');
        }
        else
        {
        LCD_intgerToString(temp);
        }
        		}


		if((temp>=30)&&(temp<60))
		{
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,11);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,4);
			LCD_displayString("temp=");
			LCD_moveCursor(1,9);
			if(temp<10)
			{/* In case the digital value is one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}
		}

		if((temp>=60)&&(temp<90))
		{
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,11);
			LCD_displayString("CW");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,4);
			LCD_displayString("temp=");
			LCD_moveCursor(1,9);
			if(temp<10)
			{/* In case the digital value is one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}

		}
		if((temp>=90)&&(temp<120))
		{
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,11);
			LCD_displayString("CW");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,4);
			LCD_displayString("temp=");
			LCD_moveCursor(1,9);
			if(temp<10)
			{/* In case the digital value is one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}
		}
		if(temp>=120)
		{
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,11);
			LCD_displayString("CW");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,4);
			LCD_displayString("temp=");
			LCD_moveCursor(1,9);
			if(temp<100)
			{/* In case the digital value is one digits print space in the next digit place */
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
			}
		}


  }

}
