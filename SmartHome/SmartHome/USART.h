/*
 * USART.h
 *
 * Created: 22-Oct-21 5:16:08 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef USART_H_
#define USART_H_

#define USART_FRAME_ERROR				(-1)
#define USART_DATA_OVER_RUN_ERROR		(-2)
#define USART_PARITY_ERROR				(-3)


void USART_Initiate(void);
void USART_SendCharSynch(uint8 Data);
int8 USART_RecieveCharSynch(uint8 *RecievedData);
void USART_SendDataSynch(uint16 Data);
void USART_RecieveDataSynch(int16 *RecievedData);



#endif /* USART_H_ */