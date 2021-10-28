/*
 * LDR.h
 *
 * Created: 28-Oct-21 1:44:40 AM
 *  Author: Abdelrhman
 */ 


#ifndef LDR_H_
#define LDR_H_



typedef struct
{
	uint8 Port;
	uint8 Pin;
}LDR_t;

void LDR_Setup(LDR_t *ldr);
void LDR_GetValue(LDR_t *ldr , uint8 *Value);
#endif /* LDR_H_ */