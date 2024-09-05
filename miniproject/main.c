/*
 * main.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mostafa Amr
 */

#include "lcd.h"
#include "lm35_sensor.h"
#include "dcmotor.h"

int main(void)
{
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_ConfigType o_adc1;
	o_adc1.ref_volt=Internal;
	o_adc1.prescaler=FCPU8;
	ADC_init(&o_adc1); /* initialize ADC driver */

	LCD_displayString("Fan is OFF");

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");
	DcMotor_Init();

    while(1)
    {

    	temp = LM35_getTemperature();

    	/* Display the temperature value every time at same position */
    	LCD_moveCursor(1,7);
    	if(temp >= 100)
    	{
    		LCD_intgerToString(temp);
    	}
    	else
    	{
    		LCD_intgerToString(temp);
    		/* In case the digital value is two or one digits print space in the next digit place */
    		LCD_displayCharacter(' ');
    	}
    	if(temp<30)
    	{
    		DcMotor_Rotate(0, 0);
    		LCD_moveCursor(0,0);
    		LCD_displayString("Fan is OFF");


    	}
    	else if(temp>=120)
    	{
    		DcMotor_Rotate(1, 100);
    		LCD_moveCursor(0,0);
    		LCD_displayString("Fan is ON ");

    	}
    	else if(temp>=90)
    	{
    		DcMotor_Rotate(1, 75);
    		LCD_moveCursor(0,0);
    		LCD_displayString("Fan is ON ");
    	}
    	else if(temp>=60)
    	{
    		DcMotor_Rotate(1, 50);
    		LCD_moveCursor(0,0);
    		LCD_displayString("Fan is ON ");
    	}
    	else if(temp>=30)
    	{
    		DcMotor_Rotate(1, 25);
    		LCD_moveCursor(0,0);
    		LCD_displayString("Fan is ON ");
    	}
    }
}



