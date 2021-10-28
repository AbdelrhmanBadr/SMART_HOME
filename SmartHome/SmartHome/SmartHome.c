/*
 * SmartHome.c
 *
 * Created: 24-Oct-21 4:24:48 PM
 *  Author: Abdelrhman
 */ 

#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include <stdlib.h>
#include <util/delay.h>
/*Include MCAL files*/
#include "DIO.h"
#include "ADC.h"
#include "Timers.h"
#include "USART.h"
/*Include HAL files*/
#include "Relay.h"
#include "Servo.h"
#include "DCMotor.h"
#include "LED.h"
#include "SevenSegment.h"
#include "Blutooth_HC06.h"
#include "IR.h"
#include "Buzzer.h"
#include "TempSensorLm35.h"
#include "LDR.h"
/*Include app file*/
#include "SmartHome_Private.h"
#include "SmartHome_Config.h"
#include "SmartHome.h"


uint8 LoginSystem(SevenSegment_t *_7Segment)
{	
	uint8 returnValue = 0;
	uint8 EnteredID = 0;
	uint8 IDTriesCounter = 0;
	char RecivedString[4] = {'0','0','0'};
	while(IDTriesCounter != 3)
	{
		EnteredID = 0;
		SevenSegment_DisplayNumber(_7Segment, 3 - IDTriesCounter);
		BluetoothHc06_SendStringToBluetooth("Welcome to smart home system\n");
		BluetoothHc06_SendStringToBluetooth("**********************************\n");
		BluetoothHc06_SendStringToBluetooth("Enter your ID \n");
		BluetoothHc06_ReceiveStringFromBluetooth(RecivedString,3);
		BluetoothHc06_SendStringToBluetooth(RecivedString);
		EnteredID = atoi(RecivedString);
		BluetoothHc06_SendToBluetooth(EnteredID);
		if (EnteredID == USER1_ID)
		{
			BluetoothHc06_SendStringToBluetooth("\nWelcome Mr: ");
			BluetoothHc06_SendStringToBluetooth(USER1_NAME);
			BluetoothHc06_SendStringToBluetooth("\n**********************************\n");
			SevenSegment_TurnOff(_7Segment);
			break;
		}
		else if (EnteredID == USER2_ID)
		{
			BluetoothHc06_SendStringToBluetooth("\nWelcome Mr: ");
			BluetoothHc06_SendStringToBluetooth(USER2_NAME);
			BluetoothHc06_SendStringToBluetooth("\n**********************************\n");
			SevenSegment_TurnOff(_7Segment);
			break;
		}
		else if (EnteredID == USER3_ID)
		{
			BluetoothHc06_SendStringToBluetooth("\nWelcome Mr: ");
			BluetoothHc06_SendStringToBluetooth(USER3_NAME);
			BluetoothHc06_SendStringToBluetooth("\n**********************************\n");
			SevenSegment_TurnOff(_7Segment);
			break;
		}
		else
		{
			BluetoothHc06_SendStringToBluetooth("\nError ID\n");
			IDTriesCounter++;
		}
	}
	/*No error at login system*/
	if (IDTriesCounter != 3)
	{
		returnValue = LOGIN_SUCCSESS;
	}
	/*Error at login system*/
	else if (IDTriesCounter == 3)
	{
		returnValue = LOGIN_FAILED;
		IDTriesCounter = 0;
	}
	return returnValue;
}
void OpenDoor(Servo_t *Door)
{
	Servo_WriteAngle(Door,OPEN_DOOR_ANGLE);
}
void CloseDoor(Servo_t *Door)
{
	Servo_WriteAngle(Door,CLOSE_DOOR_ANGLE);
}
void TurnOnFan(DCMotor_t *DcMotor)
{
	DCMotor_MoveCW(DcMotor);
}
void TurnOffFan(DCMotor_t *DcMotor)
{
	DCMotor_Stop(DcMotor);
}
void ControlFanByTemp(DCMotor_t *DcMotor , Lm35_t *TempSensor)
{
	uint8 Temperature = 0;
	Lm35_GetTemp(TempSensor,&Temperature);
	if (Temperature < 30)
	{
		TurnOffFan(DcMotor);
		BluetoothHc06_SendStringToBluetooth("FAN IS OFF\n");
	}
	else if (Temperature >= 30 && Temperature < 35)
	{
		DCMotor_ControlSpeed(DcMotor,128,DC_MOTOR_CW);
		BluetoothHc06_SendStringToBluetooth("FAN IS HALF SPEED\n");
	}
	else if (Temperature >= 35)
	{
		TurnOnFan(DcMotor);
		BluetoothHc06_SendStringToBluetooth("FAN IS FULL SPEED\n");
	}
}

void TurnOnLamp(Relay_t *Relay)
{
	Relay_TurnOn(Relay);
}
void TurnOffLamp(Relay_t *Relay)
{
	Relay_TurnOff(Relay);
}
void NightMode(LED_t LedPort[] , LDR_t *LDR)
{
	uint8 LightIntensity = 0;
	LDR_GetValue(LDR , &LightIntensity);
	if(LightIntensity < 32)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOff(&LedPort[1]);
		LED_TurnOff(&LedPort[2]);
		LED_TurnOff(&LedPort[3]);
		LED_TurnOff(&LedPort[4]);
		LED_TurnOff(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity < 64)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOff(&LedPort[2]);
		LED_TurnOff(&LedPort[3]);
		LED_TurnOff(&LedPort[4]);
		LED_TurnOff(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 64 && LightIntensity < 96)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOff(&LedPort[3]);
		LED_TurnOff(&LedPort[4]);
		LED_TurnOff(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 96 && LightIntensity < 128)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOn(&LedPort[3]);
		LED_TurnOff(&LedPort[4]);
		LED_TurnOff(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 128 && LightIntensity < 160)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOn(&LedPort[3]);
		LED_TurnOn(&LedPort[4]);
		LED_TurnOff(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 160 && LightIntensity < 192)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOn(&LedPort[3]);
		LED_TurnOn(&LedPort[4]);
		LED_TurnOn(&LedPort[5]);
		LED_TurnOff(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 192 && LightIntensity < 224)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOn(&LedPort[3]);
		LED_TurnOn(&LedPort[4]);
		LED_TurnOn(&LedPort[5]);
		LED_TurnOn(&LedPort[6]);
		LED_TurnOff(&LedPort[7]);
	}
	else if(LightIntensity >= 224 && LightIntensity < 256)
	{
		LED_TurnOn(&LedPort[0]);
		LED_TurnOn(&LedPort[1]);
		LED_TurnOn(&LedPort[2]);
		LED_TurnOn(&LedPort[3]);
		LED_TurnOn(&LedPort[4]);
		LED_TurnOn(&LedPort[5]);
		LED_TurnOn(&LedPort[6]);
		LED_TurnOn(&LedPort[7]);
	}
}
void PrintScreen(uint8 Screen)
{
	switch(Screen)
	{
		case MAIN_SCREEN: 
						BluetoothHc06_SendStringToBluetooth("What do you want to control ?!\n");
						BluetoothHc06_SendStringToBluetooth("F: Control Fan\n");
						BluetoothHc06_SendStringToBluetooth("D: Control Door\n");
						BluetoothHc06_SendStringToBluetooth("L: Control Light system\n");
						BluetoothHc06_SendStringToBluetooth("E: Exist\n");
						break;
		case FAN_SCREEN:	
						BluetoothHc06_SendStringToBluetooth("O: Open Fan\n");
						BluetoothHc06_SendStringToBluetooth("C: Close Fan\n");
						BluetoothHc06_SendStringToBluetooth("T: Control fan with temperature\n");	
						break;
		case DOOR_SCREEN:
						BluetoothHc06_SendStringToBluetooth("O: Open Door\n");
						BluetoothHc06_SendStringToBluetooth("C: Close Door\n");
						break;
		case LIGHT_SCREEN:
						BluetoothHc06_SendStringToBluetooth("O: Turn On Lamp\n");
						BluetoothHc06_SendStringToBluetooth("C: Turn Off Lamp\n");
						BluetoothHc06_SendStringToBluetooth("N: Night Mode\n");
						break;
	}
}