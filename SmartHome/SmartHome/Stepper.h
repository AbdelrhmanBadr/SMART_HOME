/*
 * Stepper.h
 *
 * Created: 16-Oct-21 12:48:22 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#define STEPPER_FULL_STEP_MODE	(0)
#define STEPPER_HALF_STEP_MODE	(1)
#define STEPPER_CW				(2)
#define STEPPER_CCW				(3)
#define STEPPER_STOP			(4)

/*By increasing the time between the step and the next step the motor speed decreases*/
#define STEPPER_DELAY_MS		(10)

typedef struct
{
	uint8 StepperPort;
	uint8 Coil1Pin;
	uint8 Coil2Pin;
	uint8 Coil3Pin;
	uint8 Coil4Pin;
	uint8 StepperMode;
}Stepper_t;

Error_t Stepper_Setup(Stepper_t *MyStepper);
Error_t Stepper_Move(Stepper_t *MyStepper , uint8 Direction , uint16 Angle);
Error_t Stepper_Stop(Stepper_t *MyStepper);

#endif /* STEPPER_H_ */