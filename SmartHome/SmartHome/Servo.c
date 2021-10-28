/*
 * Servo.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Abdelrhman Badr
 */

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "Timers.h"
#include "Servo.h"

Error_t Servo_Setup(Servo_t *MyServo)
{
	Error_t ReturnedError = NoError;
	/*Set pin as output pin*/
	ReturnedError = DIO_SetPinDirection(MyServo->ServoPort,MyServo->ServoPin,DIO_OUTPUT_PIN);
	/*Initiate Timer1*/
	Timer1_Initiate();
	/*Check for Hardware PWM signal*/
		/*OC1B pin*/
		if((MyServo->ServoPort == PORTD) && (MyServo-> ServoPin == PIN4))
		{
			Timer1_SetICRValue(20000);
		}
		/*OC1A pin*/
		else if ((MyServo->ServoPort == PORTD) && (MyServo-> ServoPin == PIN5))
		{
			Timer1_SetICRValue(20000);
		}
		else /*Software PWM*/
		{

		}
	return ReturnedError;
}
Error_t Servo_WriteAngle (Servo_t *MyServo, uint8 Angle)
{
	Error_t ReturnedError = NoError;
	uint16 ConvertedValueFromAngleToTime = (5.55556 * Angle) + 1000;
	/*Check for Hardware PWM signal*/
	/*OC1B pin*/
	if((MyServo->ServoPort == PORTD) && (MyServo-> ServoPin == PIN4))
	{
		Timer1_PWM_OC1BPin(ConvertedValueFromAngleToTime);
	}
	/*OC1A pin*/
	else if ((MyServo->ServoPort == PORTD) && (MyServo-> ServoPin == PIN5))
	{
		Timer1_PWM_OC1APin(ConvertedValueFromAngleToTime);
	}
	else /*Software PWM*/
	{
		/*TODO: Will implemented later*/
	}
	return ReturnedError;
}

