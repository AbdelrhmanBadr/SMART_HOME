/*
 * Stepper.c
 *
 * Created: 16-Oct-21 12:47:52 PM
 *  Author: Abdelrhman Badr
 */ 
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "Stepper.h"
#include <util/delay.h>

Error_t Stepper_Setup(Stepper_t *MyStepper)
{
	Error_t ReturnedError = NoError;
	/*Set pins as output pins*/
	ReturnedError = DIO_SetPinDirection(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_OUTPUT_PIN);
	ReturnedError = DIO_SetPinDirection(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_OUTPUT_PIN);
	ReturnedError = DIO_SetPinDirection(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_OUTPUT_PIN);
	ReturnedError = DIO_SetPinDirection(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_OUTPUT_PIN);
	return ReturnedError;
}
Error_t Stepper_Move(Stepper_t *MyStepper , uint8 Direction , uint16 Angle)
{
	Error_t ReturnedError = NoError;
	uint16 NumberOfIterations = 0;
	uint16 i = 0;
	switch(MyStepper->StepperMode)
	{
		case STEPPER_FULL_STEP_MODE:
									NumberOfIterations = (float)Angle / 0.7032;
									if(Direction == STEPPER_CW)
									{
										for(i = 0 ; i <= NumberOfIterations ; i++)
										{
											/*step 1*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 2*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 3*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 4*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_LOW_PIN);
											_delay_ms(STEPPER_DELAY_MS);
										}
									}
									else if (Direction == STEPPER_CCW)
									{
										for(i = 0 ; i <= NumberOfIterations ; i++)
										{
											/*step 4*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_LOW_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 3*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 2*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 1*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
												
										}
									}
									
									break;
		case STEPPER_HALF_STEP_MODE:
									NumberOfIterations = (float)Angle / 1.4064;
									if(Direction == STEPPER_CW)
									{
										for(i = 0 ; i <= NumberOfIterations ; i++)
										{
											/*step 1*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 2*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 3*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_LOW_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											/*step 4*/
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_LOW_PIN);
											_delay_ms(STEPPER_DELAY_MS);
										}
									}
									else if (Direction == STEPPER_CCW)
									{
										for(i = 0 ; i <= NumberOfIterations ; i++)
										{
											/*step 4*/
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_LOW_PIN);
											 _delay_ms(STEPPER_DELAY_MS);
											 /*step 3*/
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_LOW_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											 _delay_ms(STEPPER_DELAY_MS);
											 /*step 2*/
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_LOW_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											 _delay_ms(STEPPER_DELAY_MS);
											/*step 1*/
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_LOW_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
											 ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
											_delay_ms(STEPPER_DELAY_MS);
											
										}
									}
									break;
		default: ReturnedError = FunctionParameterError; 
	}
	return ReturnedError;
}

Error_t Stepper_Stop(Stepper_t *MyStepper)
{
	Error_t ReturnedError = NoError;
		/*step 4*/
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
		_delay_ms(STEPPER_DELAY_MS);
		/*step 3*/
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
		_delay_ms(STEPPER_DELAY_MS);
		/*step 2*/
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
		_delay_ms(STEPPER_DELAY_MS);
		/*step 1*/
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil1Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil2Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil3Pin,DIO_HIGH_PIN);
		ReturnedError = DIO_WritePin(MyStepper->StepperPort,MyStepper->Coil4Pin,DIO_HIGH_PIN);
		_delay_ms(STEPPER_DELAY_MS);
		return ReturnedError;
}