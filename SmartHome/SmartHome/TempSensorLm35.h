/*
 * TempSensorLm35.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef MCAL_DIO_TEMPSENSORLM35_H_
#define MCAL_DIO_TEMPSENSORLM35_H_

typedef struct
{
	uint8 SensorPort;
	uint8 SensorPin;
}Lm35_t;

Error_t Lm35_Setup(Lm35_t *Sensor);
Error_t Lm35_GetTemp(Lm35_t *Sensor , uint8 *TempReading);

#endif /* MCAL_DIO_TEMPSENSORLM35_H_ */
