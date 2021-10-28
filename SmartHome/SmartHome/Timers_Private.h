/*
 * Timers_Private.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

/**************************************************************************************************************************/
/*******************************************TIMER0*************************************************************************/
/**************************************************************************************************************************/
/*TIMER0_OPERATION_MODES*/
#define TIMER0_NORMAL 				(0X01)
#define TIMER0_PWM_PHASE_CORRECT  	(0X02)
#define TIMER0_CTC  				(0X03)
#define TIMER0_FAST_PWM			    (0X04)

/*TIMER0_COMPARE_OUTPUT_MODE_NON_PWM_MODES*/
#define TIMER0_TOGGLE_OC0_PIN		(0X01)
#define TIMER0_CLEAR_OC0_PIN		(0X02)
#define TIMER0_SET_OC0_PIN			(0X03)
#define TIMER0_DISCONNECT_OC0		(0X04)

/*TIMER0_COMPARE_OUTPUT_MODE_FAST_PWM_MODE*/
#define TIMER0_NON_INVERTING_MODE	(0X05)
#define TIMER0_INVERTING_MODE		(0X06)

/*TIMER0_COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE*/
#define TIMER0_CLEAR_OC0_AT_UP_COUNT	(0X02)
#define	TIMER0_SET_OC0_AT_UP_COUNT	    (0X03)

/*Timer0 clock prescaler*/
#define TIMER0_FOSC					(0x01)
#define TIMER0_FOSC_OVER_8			(0X02)
#define TIMER0_FOSC_OVER_64			(0X03)
#define TIMER0_FOSC_OVER_256		(0X04)
#define TIMER0_FOSC_OVER_1024		(0X05)
#define TIMER0_EXTERNAL_CLK_FALLING	(0X06)
#define TIMER0_EXTERNAL_CLK_RISING	(0X07)

/*Timer0 interrupt enable*/
#define TIMER0_ENABLE_INTERRUPT		(0X01)
#define TIMER0_DISABLE_INTERRUPT	(0X02)

/**************************************************************************************************************************/
/*******************************************TIMER1*************************************************************************/
/**************************************************************************************************************************/
/*Timer1 compare output mode non-PWM*/
			/*OC1A pin*/
#define TIMER1_TOGGLE_OC1A_PIN		(0X01)
#define TIMER1_CLEAR_OC1A_PIN		(0X02)
#define TIMER1_SET_OC1A_PIN			(0X03)
#define TIMER1_DISCONNECT_OC1A		(0X04)
			/*OC1B pin*/
#define TIMER1_TOGGLE_OC1B_PIN		(0X01)
#define TIMER1_CLEAR_OC1B_PIN		(0X02)
#define TIMER1_SET_OC1B_PIN		    (0X03)
#define TIMER1_DISCONNECT_OC1B		(0X04)

#define TIMER1_NON_INVERTING_MODE_OC1A		(1)	
#define TIMER1_INVERTING_MODE_OC1A			(2)
#define TIMER1_CLEAR_OC1A_AT_UP_COUNT		(3)	
#define TIMER1_SET_OC1A_AT_UP_COUNT			(4)


/*Timer1 wave generation modes*/
#define TIMER1_NORMAL				                (0)
#define TIMER1_PHASE_CORRECT_8BITS	                (1)
#define TIMER1_PHASE_CORRECT_9BITS	                (2)
#define TIMER1_PHASE_CORRECT_10BITS	                (3)
#define TIMER1_CTC_TOP_OCR1A					    (4)
#define TIMER1_FAST_PWM_8BITS	                    (5)
#define TIMER1_FAST_PWM_9BITS	                    (6)
#define TIMER1_FAST_PWM_10BITS	                    (7)
#define TIMER1_PHASE_FREQUENCY_CORRECT_TOP_ICR1	    (8)
#define TIMER1_PHASE_FREQUENCY_CORRECT_TOP_OCR1A	(9)
#define TIMER1_PHASE_CORRECT_TOP_ICR1				(10)
#define TIMER1_PHASE_CORRECT_TOP_OCR1A				(11)
#define TIMER1_CTC_TOP_ICR1					    	(12)
#define TIMER1_FAST_PWM_TOP_ICR1					(14)
#define TIMER1_FAST_PWM_TOP_OCR1A					(15)

/*Timer1 clock prescaler*/
#define TIMER1_FOSC					(0x01)
#define TIMER1_FOSC_OVER_8			(0X02)
#define TIMER1_FOSC_OVER_64			(0X03)
#define TIMER1_FOSC_OVER_256		(0X04)
#define TIMER1_FOSC_OVER_1024		(0X05)
#define TIMER1_EXTERNAL_CLK_FALLING	(0X06)
#define TIMER1_EXTERNAL_CLK_RISING	(0X07)


/*Timer1 interrupt enable*/
#define TIMER1_ENABLE_INTERRUPT		(0X01)
#define TIMER1_DISABLE_INTERRUPT	(0X02)

/**************************************************************************************************************************/
/*******************************************TIMER2**************************************************************************/
/**************************************************************************************************************************/
/*TIMER2_OPERATION_MODES*/
#define TIMER2_NORMAL 				(0X01)
#define TIMER2_PWM_PHASE_CORRECT  	(0X02)
#define TIMER2_CTC  				(0X03)
#define TIMER2_FAST_PWM			    (0X04)

/*TIMER2_COMPARE_OUTPUT_MODE_NON_PWM_MODES*/
#define TIMER2_TOGGLE_OC2_PIN		(0X01)
#define TIMER2_CLEAR_OC2_PIN		(0X02)
#define TIMER2_SET_OC2_PIN			(0X03)
#define TIMER2_DISCONNECT_OC2		(0X04)

/*TIMER2_COMPARE_OUTPUT_MODE_FAST_PWM_MODE*/
#define TIMER2_NON_INVERTING_MODE	(0X05)
#define TIMER2_INVERTING_MODE		(0X06)

/*TIMER2_COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE*/
#define TIMER2_CLEAR_OC2_AT_UP_COUNT	(0X02)
#define	TIMER2_SET_OC2_AT_UP_COUNT	    (0X03)

/*TIMER2 clock prescaler*/
#define TIMER2_FOSC					(0x01)
#define TIMER2_FOSC_OVER_8			(0X02)
#define TIMER2_FOSC_OVER_64			(0X03)
#define TIMER2_FOSC_OVER_256		(0X04)
#define TIMER2_FOSC_OVER_1024		(0X05)
#define TIMER2_EXTERNAL_CLK_FALLING	(0X06)
#define TIMER2_EXTERNAL_CLK_RISING	(0X07)

/*TIMER2 interrupt enable*/
#define TIMER2_ENABLE_INTERRUPT		(0X01)
#define TIMER2_DISABLE_INTERRUPT	(0X02)

#endif /* TIMERS_PRIVATE_H_ */
