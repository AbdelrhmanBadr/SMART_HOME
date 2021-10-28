/*
 * SmartHome.h
 *
 * Created: 24-Oct-21 4:23:14 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef SMARTHOME_H_
#define SMARTHOME_H_

#define OPEN_DOOR_ANGLE		(255)
#define CLOSE_DOOR_ANGLE	(0)

#define  LOGIN_SUCCSESS		(1)
#define  LOGIN_FAILED		(0)

#define  MAIN_SCREEN		(1)
#define  FAN_SCREEN			(2)
#define  DOOR_SCREEN		(3)
#define  LIGHT_SCREEN		(4)

#define FAN					('F')
#define DOOR				('D')
#define LIGHT_SYSTEM		('L')
#define EXIST				('E')
#define OPEN				('O')
#define CLOSE				('C')
#define TEMP_CONTROL		('T')
#define NIGHT_MODE			('N')
uint8 LoginSystem(SevenSegment_t *_7Segment);
void OpenDoor(Servo_t *Door);
void CloseDoor(Servo_t *Door);
void TurnOnFan(DCMotor_t *DcMotor);
void TurnOffFan(DCMotor_t *DcMotor);
void ControlFanByTemp(DCMotor_t *DcMotor , Lm35_t *TempSensor);
void TurnOnLamp(Relay_t *Relay);
void TurnOffLamp(Relay_t *Relay);
void NightMode(LED_t LedPort[] , LDR_t *LDR);
void PrintScreen(uint8 Screen);
#endif /* SMARTHOME_H_ */