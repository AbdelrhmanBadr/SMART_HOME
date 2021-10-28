/*
 * Blutooth_HC06.c
 *
 * Created: 25-Oct-21 2:13:46 PM
 *  Author: Abdelrhman Badr
 */ 
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "USART.h"

void BluetoothHc06_Setup(void)
{
	/*Initiate USART module*/
	USART_Initiate();
}
void BluetoothHc06_SendToBluetooth(uint8 Data)
{
	USART_SendCharSynch(Data);
}
void BluetoothHc06_ReceiveFromBluetooth(uint8 *ReceivedData)
{
	uint8 Data = 0;
	USART_RecieveCharSynch(&Data);
	if(Data >= '0')
	{
		*ReceivedData = Data;	
	}
}

void BluetoothHc06_SendStringToBluetooth(char String[])
{
	uint8 i = 0;
	for (i = 0 ; String[i] != '\0' ; i++)
	{
		USART_SendCharSynch(String[i]);
	}
}

void BluetoothHc06_ReceiveStringFromBluetooth(char *string , uint8 StringSize)
{
	uint8 i = 0;
	uint8 Data = 0;
	while (i < StringSize)
	{
		USART_RecieveCharSynch(&Data);
		if(Data >= '0')
		{
			string[i] = Data;
			i++;
		}
	}
	string[StringSize] = '\0';
}
	
