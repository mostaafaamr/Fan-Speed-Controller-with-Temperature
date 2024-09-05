/*
 * dcmotor.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mostafa Amr
 */
#include "gpio.h"
#include "adc.h"
#include "Timer0PWM.h"
#include "dcmotor.h"
#include "lm35_sensor.h"

void DcMotor_Init()
{
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

void DcMotor_Rotate(uint8 state,uint8 speed)
{
	if(state==0)
	{
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	}
	else
	{
		if(speed==25)
			PWM_Timer0_Start(64);
		else if(speed==50)
			PWM_Timer0_Start(128);
		else if(speed==75)
			PWM_Timer0_Start(192);
		else if(speed==100)
			PWM_Timer0_Start(255);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);

	}

}

