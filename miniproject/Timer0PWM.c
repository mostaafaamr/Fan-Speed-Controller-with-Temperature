/*
 * Timer0PWM.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mostafa Amr
 */
#include <avr/io.h>
#include "Timer0PWM.h"
#include "gpio.h"
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);
	TCNT0=0;
	OCR0=duty_cycle;
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

}

