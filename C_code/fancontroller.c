/*
 * fancontroller.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Ahmed Said
 */
#include "lcd.h" /*To display the temperature*/
#include "adc.h" /*To convert the sensor output to digital value*/
#include"lm35_sensor.h" /*To use the sensor driver*/
#include "motor.h" /*To use the motor driver*/

int main(void) {
	LCD_init();
	ADC_ConfigType adc_config = {INTERNAL, DIVISION_FACTOR_8};
	ADC_init(&adc_config);
	DcMotor_Init();
	uint8 Temperature = LM35_getTemperature();
	while (1) {

		if (Temperature < 30) {
			LCD_displayStringRowColumn(0, 0, "FAN is OFF");
			LCD_displayStringRowColumn(1, 0, "Temp = ");
			LCD_intgerToString(Temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP, 0);
		} else if (Temperature >= 30 && Temperature < 60) {
			LCD_displayStringRowColumn(0, 0, "FAN is ON ");
			LCD_displayStringRowColumn(1, 0, "Temp = ");
			LCD_intgerToString(Temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 25);
		} else if (Temperature >= 60 && Temperature < 90) {
			LCD_displayStringRowColumn(0, 0, "FAN is ON ");
			LCD_displayStringRowColumn(1, 0, "Temp = ");
			LCD_intgerToString(Temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 50);
		} else if (Temperature >= 90 && Temperature < 120) {
			LCD_displayStringRowColumn(0, 0, "FAN is ON ");
			LCD_displayStringRowColumn(1, 0, "Temp = ");
			LCD_intgerToString(Temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 75);
		} else {
			LCD_displayStringRowColumn(0, 0, "FAN is ON ");
			LCD_displayStringRowColumn(1, 0, "Temp = ");
			LCD_intgerToString(Temperature);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 100);
		}
		Temperature = LM35_getTemperature();
	}
	return 0;
}


