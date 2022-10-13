 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file for the Motor driver
 *
 * Author: Ahmed Said
 *
 *******************************************************************************/

#include"motor.h"
#include"gpio.h"
#include"common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

 /* Description :
* Initialize the Motor.
*/

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, PIN_OUTPUT);
	DcMotor_Rotate(STOP, 0);
}

/*
 * Description :
 * Rotate the motor at the sent speed:
 * 1. Get the state.
 * 2. Rotate the motor at the sent speed.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT1_PIN_ID, GET_BIT(state, 0));
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_INPUT2_PIN_ID, GET_BIT(state, 1));
	Timer0_PWM_Start(speed);
}
