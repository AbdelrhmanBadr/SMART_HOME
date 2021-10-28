/*
 * Relay.c
 *
 * Created: 22-Oct-21 2:19:42 PM
 *  Author: Abdelrhman Badr
 */ 

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "Relay.h"

Error_t Relay_Setup(Relay_t *Relay)
{
	Error_t ReturnedError = NoError;
	/*Set relay pin as output pin*/
	ReturnedError = DIO_SetPinDirection(Relay->RelayPort,Relay->RelayPin,DIO_OUTPUT_PIN);
	return ReturnedError;
}
Error_t Relay_TurnOn(Relay_t *Relay)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_WritePin(Relay->RelayPort,Relay->RelayPin,DIO_HIGH_PIN);
	return ReturnedError;
}
Error_t Relay_TurnOff(Relay_t *Relay)
{
	Error_t ReturnedError = NoError;
	ReturnedError = DIO_WritePin(Relay->RelayPort,Relay->RelayPin,DIO_LOW_PIN);
	return ReturnedError;
}
