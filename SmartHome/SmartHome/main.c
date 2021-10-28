/*
 * main.c
 *
 * Created: 22-Oct-21 2:06:54 PM
 *  Author: Abdelrhman Badr
 */ 

/*Include Services file*/
#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
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

int main(void)
{
	Servo_t DoorServo = {PORTD,PIN5};
	DCMotor_t FanMotor = {PORTD,PIN4,PIN7};
	SevenSegment_t _7Segment = {PORTC,SEVEN_SEGMENT_COMMON_CATHODE};
	Relay_t LampRelay = {PORTD,PIN2};
	Buzzer_t SireinBuzzer = {PORTD,PIN6};
	IR_t DoorSensor = {PORTD,PIN3};
	Lm35_t TempSensor = {PORTA,PIN1};
	LED_t LedPort[7];
	LDR_t LDR = {PORTA,PIN0};
	uint8 i;
	Servo_Setup(&DoorServo);
	DCMotor_Setup(&FanMotor);
	Buzzer_Setup(&SireinBuzzer);
	Relay_Setup(&LampRelay);
	IR_Setup(&DoorSensor);
	Lm35_Setup(&TempSensor);
	BluetoothHc06_Setup();
	SevenSegment_Setup(&_7Segment);
	for (i = 0 ; i < 8 ; i++)
	{
		LedPort[i].LedPort = PORTB;
		LedPort[i].LedPin = i;
		LedPort[i].LedConnectionType = LED_FORWARD;
	}
	for (i = 0 ; i < 7 ; i++)
	{
		LED_Setup(&LedPort[i]);
	}
	LDR_Setup(&LDR);
	uint8 LoginState = LOGIN_FAILED;
	uint8 EnteredVal = 0;
	uint8 NightModeFlag = 0;
	uint8 TemperatureFlag = 0;
	while(1)
	{
		/*Login system*/
		LoginState = LoginSystem(&_7Segment);
		NightModeFlag = 0;
		TemperatureFlag = 0;
		if (LoginState == LOGIN_SUCCSESS)
		{
			while(1)	
			{
				PrintScreen(MAIN_SCREEN);
				EnteredVal = 0;
				do
				{
					BluetoothHc06_ReceiveFromBluetooth(&EnteredVal);
					BluetoothHc06_SendToBluetooth(EnteredVal);
					BluetoothHc06_SendStringToBluetooth("\n");
				} while ((EnteredVal != FAN) && (EnteredVal != DOOR) && (EnteredVal != LIGHT_SYSTEM) && (EnteredVal != EXIST));
				
				if (EnteredVal == FAN) /*Control Fan*/
				{
					PrintScreen(FAN_SCREEN);
					EnteredVal = 0;
					do
					{
						BluetoothHc06_ReceiveFromBluetooth(&EnteredVal);
						BluetoothHc06_SendToBluetooth(EnteredVal);
						BluetoothHc06_SendStringToBluetooth("\n");
					}while (EnteredVal != OPEN && EnteredVal != CLOSE && EnteredVal != TEMP_CONTROL);
					
					switch(EnteredVal)
					{
						case OPEN  :TemperatureFlag = 0; TurnOnFan(&FanMotor); break;
						case CLOSE :TemperatureFlag = 0; TurnOffFan(&FanMotor); break;
						case TEMP_CONTROL : TemperatureFlag = 1; ControlFanByTemp(&FanMotor,&TempSensor); break;
					}
				}
				else if (EnteredVal == DOOR) /*Control Door*/
				{
					PrintScreen(DOOR_SCREEN);
					EnteredVal = 0;
					do
					{
						BluetoothHc06_ReceiveFromBluetooth(&EnteredVal);
						BluetoothHc06_SendToBluetooth(EnteredVal);
						BluetoothHc06_SendStringToBluetooth("\n");
					}while (EnteredVal != OPEN && EnteredVal != CLOSE);
					
					switch(EnteredVal)
					{
						case OPEN : OpenDoor(&DoorServo); break;
						case CLOSE : CloseDoor(&DoorServo); break;
					}
				}
				else if (EnteredVal == LIGHT_SYSTEM) /*Control light system*/
				{
					PrintScreen(LIGHT_SCREEN);
					EnteredVal = 0;
					do
					{
						BluetoothHc06_ReceiveFromBluetooth(&EnteredVal);
						BluetoothHc06_SendToBluetooth(EnteredVal);
						BluetoothHc06_SendStringToBluetooth("\n");
					}while (EnteredVal != OPEN && EnteredVal != CLOSE && EnteredVal != NIGHT_MODE);
					
					switch(EnteredVal)
					{
						case OPEN  : NightModeFlag = 0; TurnOnLamp(&LampRelay); break;
						case CLOSE : NightModeFlag = 0; TurnOffLamp(&LampRelay); break;
						case NIGHT_MODE : NightModeFlag = 1; NightMode(LedPort,&LDR); break;
					}
				}
				else if (EnteredVal == EXIST) /*Exist*/
				{
					EnteredVal = 0;
					TurnOffLamp(&LampRelay);
					CloseDoor(&DoorServo);
					break;
				}
				if (NightModeFlag == 1)
				{
					NightMode(LedPort,&LDR);
				}
				if (TemperatureFlag == 1)
				{
					ControlFanByTemp(&FanMotor,&TempSensor);
				}
			}
		}
		else if (LoginState == LOGIN_FAILED)
		{
			BluetoothHc06_SendStringToBluetooth("\nYOUR ID ISNOT EXSIST\n");
			SevenSegment_TurnOff(&_7Segment);
		}
				
	}
}