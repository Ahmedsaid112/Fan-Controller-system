 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the Motor driver
 *
 * Author: Ahmed Said
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include"std_types.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_PORT_ID PORTB_ID
#define MOTOR_INPUT1_PIN_ID PIN0_ID
#define MOTOR_INPUT2_PIN_ID PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	STOP, A_CW, CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Description :
* Initialize the Motor.
*/
void DcMotor_Init(void);

/*
 * Description :
 * Rotate the motor at the sent speed:
 * 1. Get the state.
 * 2. Rotate the motor at the sent speed.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* MOTOR_H_ */
