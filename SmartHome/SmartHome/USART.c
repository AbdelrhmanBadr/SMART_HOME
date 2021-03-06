/*
 * USART.c
 *
 * Created: 22-Oct-21 5:17:14 PM
 *  Author: Abdelrhman Badr
 */ 
#include "Std_DataType.h"
#include "Math.h"
#include "Error.h"
#include "Atmega32A.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "USART.h"

void USART_Initiate(void)
{
	uint8 UCSRC_RegVal = 0X00;
	/*Set baud rate*/
	#if USART_MODE == USART_ASYNCH
		uint16 BaudRate = ((uint32)CPU_FREQUENCY /((uint32)(16 * USART_BAUD_RATE))) - 1;
		CLEAR_BIT(UCSRA_REG,UCSRA_U2X_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UMSEL_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UCPOL_BIT); /*Write this bit to zero when Asynchronous mode is used.*/
	#elif USART_MODE == USART_SYNCH 
		uint16 BaudRate = ((uint32)CPU_FREQUENCY /((uint32)(2 * USART_BAUD_RATE))) - 1;
		CLEAR_BIT(UCSRA_REG,UCSRA_U2X_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UMSEL_BIT);
		
		#if USART_CLOCK_PARITY == USART_RISING_TX_FALLING_RX
			CLEAR_BIT(UCSRC_RegVal,UCSRC_UCPOL_BIT);
		#elif USART_CLOCK_PARITY == USART_FALLING_TX_RISING_RX
			SET_BIT(UCSRC_RegVal,UCSRC_UCPOL_BIT);
		#else
			#error "Error in USART_CLOCK_PARITY config"
		#endif /*USART_CLOCK_PARITY*/
	#else 
		#error "Error in USART_MODE config"
	#endif /*USART_MODE*/
	
	UBRRL_REG = (uint8) BaudRate;
	UBRRH_REG = (uint8) (BaudRate >> 8);

	#if USART_MULTI_PROCESSOR_COMMUNICATION_MODE == USART_ENABLE
		SET_BIT(UCSRA_REG,UCSRA_MPCM_BIT);
	#elif  USART_MULTI_PROCESSOR_COMMUNICATION_MODE == USART_DISABLE
		CLEAR_BIT(UCSRA_REG,UCSRA_MPCM_BIT);
	#else 
		#error "Error in USART_MULTI_PROCESSOR_COMMUNICATION_MODE config"
	#endif /*USART_MULTI_PROCESSOR_COMMUNICATION_MODE*/

	#if USART_ENABLE_TX == USART_ENABLE
		SET_BIT(UCSRB_REG,UCSRB_TXEN_BIT);
	#elif USART_ENABLE_TX == USART_DISABLE
		CLEAR_BIT(UCSRB_REG,UCSRB_TXEN_BIT);
	#else
		#error "Error in USART_ENABLE_TX config"
	#endif /*USART_ENABLE_TX*/
	
	#if USART_ENABLE_RX	== USART_ENABLE
		SET_BIT(UCSRB_REG,UCSRB_RXEN_BIT);
	#elif USART_ENABLE_RX == USART_DISABLE
		CLEAR_BIT(UCSRB_REG,UCSRB_RXEN_BIT);
	#else
		#error "Error in USART_ENABLE_RX config"
	#endif /*USART_ENABLE_RX*/
	
	SET_BIT(UCSRC_RegVal,UCSRC_URSEL_BIT); /*The URSEL must be one when writing the UCSRC.*/
	
	#if USART_PARITY_MODE == USART_NO_PARITY
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UPM1_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UPM0_BIT);
	#elif USART_PARITY_MODE == USART_EVEN_PARITY
		SET_BIT(UCSRC_RegVal,UCSRC_UPM1_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UPM0_BIT);
	#elif USART_PARITY_MODE == USART_ODD_PARITY
		SET_BIT(UCSRC_RegVal,UCSRC_UPM1_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UPM0_BIT);
	#else 
		#error "Error in USART_PARITY_MODE config"
	#endif /*USART_PARITY_MODE*/
	
	#if USART_STOP_BIT == USART_ONE_STOP_BIT
		CLEAR_BIT(UCSRC_RegVal,UCSRC_USBS_BIT);
	#elif USART_STOP_BIT == USART_TWO_STOP_BIT
		SET_BIT(UCSRC_RegVal,UCSRC_USBS_BIT);
	#else
		#error "Error in USART_STOP_BIT Config"
	#endif /*USART_STOP_BIT*/

	#if USART_CHAR_SIZE == USART_FIVE_CHAR_BIT
		CLEAR_BIT(UCSRB_REG,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UCSZ0_BIT);
	#elif USART_CHAR_SIZE == USART_SIX_CHAR_BIT
		CLEAR_BIT(UCSRB_REG,UCSRB_UCSZ2_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ0_BIT);
	#elif USART_CHAR_SIZE == USART_SEVEN_CHAR_BIT
		CLEAR_BIT(UCSRB_REG,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ1_BIT);
		CLEAR_BIT(UCSRC_RegVal,UCSRC_UCSZ0_BIT);
	#elif USART_CHAR_SIZE == USART_EIGHT_CHAR_BIT
		CLEAR_BIT(UCSRB_REG,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ0_BIT);
	#elif USART_CHAR_SIZE == USART_NINE_CHAR_BIT
		SET_BIT(UCSRB_REG,UCSRB_UCSZ2_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ1_BIT);
		SET_BIT(UCSRC_RegVal,UCSRC_UCSZ0_BIT);
	#else
		#error "Error in USART_CHAR_SIZE config"
	#endif /*USART_CHAR_SIZE*/
	
	UCSRC_REG = UCSRC_RegVal;
}
void USART_SendCharSynch(uint8 Data)
{
	/*Check if the buffer is empty*/
	while(GET_BIT(UCSRA_REG,UCSRA_UDRE_BIT) == 0);
	UDR_REG = Data;
}
int8 USART_RecieveCharSynch(uint8 *RecievedData)
{
	int8 ReturnedError = 0;
	/*Check if the receive is complete*/
	while(GET_BIT(UCSRA_REG,UCSRA_RXC_BIT) == 0);
	/*Check for errors*/
	if (GET_BIT(UCSRA_REG,UCSRA_FE_BIT) == 1)
	{
		ReturnedError = USART_FRAME_ERROR;
	}
	else if (GET_BIT(UCSRA_REG,UCSRA_PE_BIT) == 1)
	{
		ReturnedError = USART_PARITY_ERROR;
	}
	else if (GET_BIT(UCSRA_REG,UCSRA_DOR_BIT) == 1)
	{
		ReturnedError = USART_DATA_OVER_RUN_ERROR;
	}
	else
	{
		*RecievedData = UDR_REG;
	}
	
	/*Clear the flag*/
	SET_BIT(UCSRA_REG,UCSRA_RXC_BIT);
	return ReturnedError;
}
void USART_SendDataSynch(uint16 Data)
{

}
void USART_RecieveDataSynch(int16 *RecievedData)
{

}