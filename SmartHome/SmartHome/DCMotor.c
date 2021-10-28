/*
 * DCMotor.c
 *
 * Created: 16-Oct-21 6:06:44 PM
 *  Author: Abdelrhman Badr
 */ 
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "Timers.h"
#include "DCMotor.h"
#include <util/delay.h>

Error_t DCMotor_Setup(DCMotor_t *Motor)
{
	Error_t ReturnedError = NoError;
	/*Set motor pins as output pins*/
	ReturnedError = DIO_SetPinDirection(Motor->MotorPort,Motor->MotorPin1,DIO_OUTPUT_PIN);
	ReturnedError = DIO_SetPinDirection(Motor->MotorPort,Motor->MotorPin2,DIO_OUTPUT_PIN);
	if (Motor->MotorPort == OC0_PORT && ((Motor->MotorPin1 == OC0_PIN) || (Motor->MotorPin2 == OC0_PIN)))
	{
		Timer0_Initiate();
	}
	if (Motor->MotorPort == OC2_PORT && ((Motor->MotorPin1 == OC2_PIN) || (Motor->MotorPin2 == OC2_PIN)))
	{
		Timer2_Initiate();
	}
	if (Motor->MotorPort == OC1A_PORT && ((Motor->MotorPin1 == OC1A_PIN) || (Motor->MotorPin2 == OC1A_PIN)))
	{
		Timer1_Initiate();
	}
	if (Motor->MotorPort == OC1B_PORT && ((Motor->MotorPin1 == OC1B_PIN) || (Motor->MotorPin2 == OC1B_PIN)))
	{
		Timer1_Initiate();
	}
	return ReturnedError;
}
Error_t DCMotor_MoveCW(DCMotor_t *Motor)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin1,DIO_HIGH_PIN);
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin2,DIO_LOW_PIN);
	return ReturnedError;
}
Error_t DCMotor_MoveCCW(DCMotor_t *Motor)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin2,DIO_HIGH_PIN);
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin1,DIO_LOW_PIN);
	return ReturnedError;	
}
Error_t DCMotor_Stop(DCMotor_t *Motor)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin2,DIO_LOW_PIN);
	ReturnedError = DIO_WritePin(Motor->MotorPort,Motor->MotorPin1,DIO_LOW_PIN);
	return ReturnedError;
}
Error_t DCMotor_ControlSpeed(DCMotor_t *Motor , uint8 SpeedValue , uint8 MotorDirection)
{
	Error_t ReturnedError = NoError;
	if (MotorDirection == DC_MOTOR_CCW)
	{
		Timer_PWM(Motor->MotorPort,Motor->MotorPin1,SpeedValue);
		Timer_PWM(Motor->MotorPort,Motor->MotorPin2,0);	
	}
	else if (MotorDirection == DC_MOTOR_CW)
	{
		Timer_PWM(Motor->MotorPort,Motor->MotorPin2,SpeedValue);
		Timer_PWM(Motor->MotorPort,Motor->MotorPin1,0);
	}
	else
	{	
		ReturnedError = FunctionParameterError;  
	}
	return ReturnedError;
}