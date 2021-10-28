/*
 * Relay.h
 *
 * Created: 22-Oct-21 2:21:16 PM
 *  Author: Abdelrhman
 */ 


#ifndef RELAY_H_
#define RELAY_H_

typedef struct
{
	uint8 RelayPort;
	uint8 RelayPin;
}Relay_t;

Error_t Relay_Setup(Relay_t *Relay);
Error_t Relay_TurnOn(Relay_t *Relay);
Error_t Relay_TurnOff(Relay_t *Relay);



#endif /* RELAY_H_ */