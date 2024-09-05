 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mostafa Amr
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*******************************************************************************
*                       Enums and Structures                                   *
 *******************************************************************************/

/* Enum to define the used reference voltage for ADC*/
typedef enum
{
	AREF=0,AVCC=0x40,Internal=0xC0
}ADC_ReferenceVolatge;

/* Enum to define the used Prescaler for ADC*/
 typedef enum
{
	FCPU2,FCPU21,FCPU4,FCPU8,FCPU16,FCPU32,FCPU64,FCPU128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;


}ADC_ConfigType;
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
