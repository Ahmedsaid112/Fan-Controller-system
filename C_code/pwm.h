 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Ahmed Said
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define OC0_PORT_ID PORTB_ID
#define OC0_PIN_ID PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Configure the PWM signal
 */

void Timer0_PWM_Start(unsigned char speed);

#endif /* PWM_H_ */
