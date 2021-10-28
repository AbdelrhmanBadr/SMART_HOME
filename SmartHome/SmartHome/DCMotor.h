/*
 * DCMotor.h
 *
 * Created: 16-Oct-21 6:06:59 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#define DC_MOTOR_CW	 (1)
#define DC_MOTOR_CCW (2)

#define DC_MOTOR_MAX_SPEED	(255)
typedef struct
{
	uint8 MotorPort;
	uint8 MotorPin1;
	uint8 MotorPin2;
}DCMotor_t;

Error_t DCMotor_Setup(DCMotor_t *Motor);
Error_t DCMotor_MoveCW(DCMotor_t *Motor);
Error_t DCMotor_MoveCCW(DCMotor_t *Motor);
Error_t DCMotor_Stop(DCMotor_t *Motor);
Error_t DCMotor_ControlSpeed(DCMotor_t *Motor , uint8 SpeedValue , uint8 MotorDirection);

#endif /* DCMOTOR_H_ */