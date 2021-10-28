/*
 * IR.h
 *
 * Created: 25-Oct-21 1:44:30 PM
 *  Author: Abdelrhman
 */ 


#ifndef IR_H_
#define IR_H_

typedef struct
{
	uint8 Port;
	uint8 Pin;
}IR_t;

Error_t IR_Setup(IR_t *IrSensor);
Error_t IR_GetValue(IR_t *IrSensor,uint8 *ReturnedValue);



#endif /* IR_H_ */