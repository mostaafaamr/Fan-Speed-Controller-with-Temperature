/*
 * dcmotor.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Mostafa Amr
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
#include "adc.h"
#define OFF 0
#define ON 1

void DcMotor_Init();
void DcMotor_Rotate(uint8 state,uint8 speed);


#endif /* DCMOTOR_H_ */
