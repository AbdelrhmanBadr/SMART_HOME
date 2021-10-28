/*
 * LDR.c
 *
 * Created: 28-Oct-21 1:47:26 AM
 *  Author: Abdelrhman
 */ 
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "ADC.h"
#include "LDR.h"

void LDR_Setup(LDR_t *ldr)
{
	/*set pin as input pin*/
	DIO_SetPinDirection(ldr->Port,ldr->Pin,DIO_OUTPUT_PIN);
	/*initiate ADC*/
	ADC_Initiate();
}
void LDR_GetValue(LDR_t *ldr , uint8 *Value)
{
	ADC_StartConversionSynch(ldr->Pin,Value);
}