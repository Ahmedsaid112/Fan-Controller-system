 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Ahmed Said
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	AREF, AVCC, REVERSED, INTERNAL
}ADC_ReferenceVolatge;

typedef enum{
	DIVISION_FACTOR_2,
	DIVISION_FACTOR__2,
	DIVISION_FACTOR_4,
	DIVISION_FACTOR_8,
	DIVISION_FACTOR_16,
	DIVISION_FACTOR_32,
	DIVISION_FACTOR_64,
	DIVISION_FACTOR_128,
}ADC_Prescaler;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the ADC:
 * 1. Configure the reference voltage.
 * 2. Configure the prescaler.
 */

void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Read the sent channel and return the digital value
 */

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
