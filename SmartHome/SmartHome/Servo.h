/*
 * Servo.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef SERVO_H_
#define SERVO_H_

typedef struct
{
	uint8 ServoPort;
	uint8 ServoPin;
}Servo_t;

Error_t Servo_Setup(Servo_t *MyServo);
Error_t Servo_WriteAngle (Servo_t *MyServo, uint8 Angle);
#endif /* SERVO_H_ */
