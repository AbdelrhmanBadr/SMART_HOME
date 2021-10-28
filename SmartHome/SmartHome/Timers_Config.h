/*
 * Timers_Config.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Abdelrhman
 */

#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 *	----------------------------------------> TIMER0 CONFIGRATIONS <----------------------------------------------------
 *||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */

/*
 * TIMER0_OPERATION_MODE : TIMER0_NORMAL (OverFlow) , TIMER0_PWM_PHASE_CORRECT , TIMER0_CTC , TIMER0_FAST_PWM
 */
#define TIMER0_OPERATION_MODE		(TIMER0_FAST_PWM)

/*
 * TIMER0_COMPARE_OUTPUT_MODE (For non PWM-modes)  : TIMER0_TOGGLE_OC0_PIN		    TIMER0_CLEAR_OC0_PIN		TIMER0_SET_OC0_PIN		TIMER0_DISCONNECT_OC0
 * TIMER0_COMPARE_OUTPUT_MODE (For Fast-PWM-mode)  : TIMER0_NON_INVERTING_MODE		TIMER0_INVERTING_MODE	    TIMER0_DISCONNECT_OC0
 * NOTE : NON_INVERTING_MODE --> Clear OC0 on compare match, set OC0 at BOTTOM.
 * 		  INVERTING_MODE     --> Set OC0 on compare match, clear OC0 at BOTTOM.
 * TIMER0_COMPARE_OUTPUT_MODE (For Phase-correct-PWM-mode)  : TIMER0_CLEAR_OC0_AT_UP_COUNT	TIMER0_SET_OC0_AT_UP_COUNT	TIMER0_DISCONNECT_OC0
 */
#define TIMER0_COMPARE_OUTPUT_MODE	(TIMER0_NON_INVERTING_MODE)

/*
 * TIMER0_CLK_PRESCALER --> TIMER0_FOSC	 			TIMER0_FOSC_OVER_8		TIMER0_FOSC_OVER_64
 *	 	 	 	 	 	 	TIMER0_FOSC_OVER_256	TIMER0_FOSC_OVER_1024	TIMER0_EXTERNAL_CLK_FALLING
 * 	 	 	 	 	 	 	TIMER0_EXTERNAL_CLK_RISING
 */
#define TIMER0_FREQUENCY	(TIMER0_FOSC_OVER_8)

/*
 * TIMER0_INTERRUPT_ENABLE --> TIMER0_ENABLE_INTERRUPT , TIMER0_DISABLE_INTERRUPT
 */
#define TIMER0_INTERRUPT_ENABLE	(TIMER0_ENABLE_INTERRUPT)


/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 *	----------------------------------------> TIMER1 CONFIGRATIONS <----------------------------------------------------
 *||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */

/*
 * 					**************
 * 					*For OC1A Pin*
 * 					**************
 * For NON-PWM modes:
 * ******************
 * TIMER1_TOGGLE_OC1A_PIN		TIMER1_CLEAR_OC1A_PIN		TIMER1_SET_OC1A_PIN		TIMER1_DISCONNECT_OC1A
 *
 * For Fast-PWM modes:
 * *******************
 * TIMER1_NON_INVERTING_MODE_OC1A		TIMER1_INVERTING_MODE_OC1A
 * NOTE : NON_INVERTING_MODE --> Clear OC1A/B on compare match, set OC1A/B at BOTTOM.
 * 		  INVERTING_MODE     --> Set OC1A/B on compare match, clear OC1A/B at BOTTOM.
 *
 * For Phase Correct and Phase and Frequency Correct PWM mode:
 * ***********************************************************
 * TIMER1_CLEAR_OC1A_AT_UP_COUNT	TIMER1_SET_OC1A_AT_UP_COUNT
*/
#define TIMER1_COMPARE_OUTPUT_MODE_OC1A	(TIMER1_NON_INVERTING_MODE_OC1A)

/*
 *   				**************
 * 					*For OC1B Pin*
 * 					**************
 * For NON-PWM modes:
 * ******************
 * TIMER1_TOGGLE_OC1B_PIN		TIMER1_CLEAR_OC1B_PIN		TIMER1_SET_OC1B_PIN		TIMER1_DISCONNECT_OC1B
 *
 * For Fast-PWM modes:
 * *******************
 * TIMER1_NON_INVERTING_MODE_OC1B		TIMER1_INVERTING_MODE_OC1B
 * NOTE : NON_INVERTING_MODE --> Clear OC1B on compare match, set OC1B at BOTTOM.
 * 		  INVERTING_MODE     --> Set OC1B on compare match, clear OC1B at BOTTOM.
 *
 * For Phase Correct and Phase and Frequency Correct PWM mode:
 * ***********************************************************
 * TIMER1_CLEAR_OC1B_AT_UP_COUNT	TIMER1_SET_OC1B_AT_UP_COUNT		TIMER1_DISCONNECT_OC1B
*/
#define TIMER1_COMPARE_OUTPUT_MODE_OC1B	(TIMER1_DISCONNECT_OC1B)

/*
 * TIMER1_NORMAL
 * TIMER1_PHASE_CORRECT_8BITS	 TIMER1_PHASE_CORRECT_9BITS	            TIMER1_PHASE_CORRECT_10BITS
 * TIMER1_CTC_TOP_OCR1A			 TIMER1_CTC_TOP_ICR1
 * TIMER1_FAST_PWM_8BITS	     TIMER1_FAST_PWM_9BITS	                TIMER1_FAST_PWM_10BITS	 TIMER1_FAST_PWM_TOP_ICR1		TIMER1_FAST_PWM_TOP_OCR1A
 * TIMER1_PHASE_FREQUENCY_CORRECT_TOP_ICR1	   TIMER1_PHASE_FREQUENCY_CORRECT_TOP_OCR1A
 * TIMER1_PHASE_CORRECT_TOP_ICR1			   TIMER1_PHASE_CORRECT_TOP_OCR1A
 */
#define TIMER1_WAVE_GENERATION_MODE		(TIMER1_FAST_PWM_TOP_ICR1)

/*
 * TIMER1_CLK_PRESCALER --> TIMER1_FOSC	 			TIMER1_FOSC_OVER_8		TIMER1_FOSC_OVER_64
 *	 	 	 	 	 	 	TIMER1_FOSC_OVER_256	TIMER1_FOSC_OVER_1024	TIMER1_EXTERNAL_CLK_FALLING
 * 	 	 	 	 	 	 	TIMER1_EXTERNAL_CLK_RISING
 */
#define TIMER1_FREQUENCY	(TIMER1_FOSC_OVER_8)

/*
 * TIMER1_INTERRUPT_ENABLE --> TIMER1_ENABLE_INTERRUPT , TIMER1_DISABLE_INTERRUPT
 */
#define TIMER1_INTERRUPT_ENABLE	(TIMER1_ENABLE_INTERRUPT)

/*||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 *	----------------------------------------> TIMER2 CONFIGRATIONS <----------------------------------------------------
 *||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */

/*
 * TIMER2_OPERATION_MODE : TIMER2_NORMAL (OverFlow) , TIMER2_PWM_PHASE_CORRECT , TIMER2_CTC , TIMER2_FAST_PWM
 */
#define TIMER2_OPERATION_MODE		(TIMER2_FAST_PWM)

/*
 * TIMER2_COMPARE_OUTPUT_MODE (For non PWM-modes)  : TIMER2_TOGGLE_OC2_PIN		    TIMER2_CLEAR_OC2_PIN		TIMER2_SET_OC2_PIN		TIMER2_DISCONNECT_OC2
 * TIMER2_COMPARE_OUTPUT_MODE (For Fast-PWM-mode)  : TIMER2_NON_INVERTING_MODE		TIMER2_INVERTING_MODE	    TIMER2_DISCONNECT_OC2
 * NOTE : NON_INVERTING_MODE --> Clear OC2 on compare match, set OC2 at BOTTOM.
 * 		  INVERTING_MODE     --> Set OC2 on compare match, clear OC2 at BOTTOM.
 * TIMER2_COMPARE_OUTPUT_MODE (For Phase-correct-PWM-mode)  : TIMER2_CLEAR_OC2_AT_UP_COUNT	TIMER2_SET_OC2_AT_UP_COUNT	TIMER2_DISCONNECT_OC2
 */
#define TIMER2_COMPARE_OUTPUT_MODE	(TIMER2_NON_INVERTING_MODE)

/*
 * TIMER2_CLK_PRESCALER --> TIMER2_FOSC	 			TIMER2_FOSC_OVER_8		TIMER2_FOSC_OVER_64
 *	 	 	 	 	 	 	TIMER2_FOSC_OVER_256	TIMER2_FOSC_OVER_1024	TIMER2_EXTERNAL_CLK_FALLING
 * 	 	 	 	 	 	 	TIMER2_EXTERNAL_CLK_RISING
 */
#define TIMER2_FREQUENCY	(TIMER2_FOSC_OVER_8)

/*
 * TIMER2_INTERRUPT_ENABLE --> TIMER2_ENABLE_INTERRUPT , TIMER2_DISABLE_INTERRUPT
 */
#define TIMER2_INTERRUPT_ENABLE	(TIMER2_ENABLE_INTERRUPT)

#endif /* TIMERS_CONFIG_H_ */
