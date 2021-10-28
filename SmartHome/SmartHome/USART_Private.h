/*
 * USART_Private.h
 *
 * Created: 22-Oct-21 5:16:58 PM
 *  Author: Abdelrhman Badr
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define USART_ENABLE	(1)
#define USART_DISABLE	(2)

#define USART_ASYNCH	(1)
#define USART_SYNCH		(2)

#define USART_NO_PARITY			(1)
#define USART_EVEN_PARITY		(2)
#define USART_ODD_PARITY		(3)

#define USART_ONE_STOP_BIT		(1)
#define USART_TWO_STOP_BIT		(2)

#define USART_FIVE_CHAR_BIT		(5)
#define USART_SIX_CHAR_BIT		(6)
#define USART_SEVEN_CHAR_BIT	(7)
#define USART_EIGHT_CHAR_BIT	(8)
#define USART_NINE_CHAR_BIT		(9)

#define USART_RISING_TX_FALLING_RX	(1)
#define USART_FALLING_TX_RISING_RX	(2)
#endif /* USART_PRIVATE_H_ */