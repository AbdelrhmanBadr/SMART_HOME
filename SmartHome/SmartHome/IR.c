/*
 * IR.c
 *
 * Created: 25-Oct-21 1:44:14 PM
 *  Author: Abdelrhman
 */ 

/*Include Services file*/
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
/*Include MCAL files*/
#include "DIO.h"
#include "IR.h"

Error_t IR_Setup(IR_t *IrSensor)
{
	Error_t ReturnedError = NoError;
	/*Set pin as input pin*/
	ReturnedError = DIO_SetPinDirection(IrSensor->Port,IrSensor->Pin,DIO_INPUT_PIN);
	return ReturnedError;
}

Error_t IR_GetValue(IR_t *IrSensor,uint8 *ReturnedValue)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_ReadPin(IrSensor->Port,IrSensor->Pin,ReturnedValue);
	return ReturnedError;
}