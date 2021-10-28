/*
 * TempSensorLm35.c
 *
 *  Created on: Aug 18, 2021
 *      Author: Abdelrhman Badr
 */

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "ADC.h"
#include "TempSensorLm35.h"

Error_t Lm35_Setup(Lm35_t *Sensor)
{
	Error_t ReturnedError = NoError;
	/*Set pin as input pin*/
	ReturnedError =  DIO_SetPinDirection(Sensor->SensorPort , Sensor->SensorPin , DIO_INPUT_PIN);
	/*Initiate ADC*/
	ADC_Initiate();
	return ReturnedError;
}
Error_t Lm35_GetTemp(Lm35_t *Sensor , uint8 *TempReading)
{
	Error_t ReturnedError = NoError;
	uint16 ADCVal = 0;

	/*Get ADC Value*/
	ReturnedError = ADC_StartConversionSynch(Sensor->SensorPin,&ADCVal);
	/*Convert digital value to volt*/
	ADCVal = ((float32_t)(ADCVal * 5.00)) / 256.00;
	/*Convert volt to temp*/
	*TempReading = ADCVal * 100;
	/*Return value*/
	return ReturnedError;
}
