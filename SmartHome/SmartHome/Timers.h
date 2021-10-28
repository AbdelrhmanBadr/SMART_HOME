/*
 * Timers.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Abdelrhman Badr
 */

/*
for 1second timer with timer_freq = 8MHZ
========================================
Timer_Freq = 8MHZ / 8 = 1MHZ
Tick_Time = 1 / 1MHZ = 1us
OverFlow_Time =
				Number_of_ticks			tickTime
						1      ----->      1us
			 (OVERFLOW)256     ----->      256us
overFlow_time = 256uS
req_time = 1sec
number of over flow = 1/256u = 3906.25 --> ctr = 3907
preload = (1-0.25) * 256 = 192
Example:
void func(void)
{
	static uint16 counter = 0;
	counter ++;
	if(counter == 3907)
	{
		//ANY CODE
		counter = 0;
		Timer0_SetPreLoadValue(192);
	}

}
*/

#ifndef TIMERS_H_
#define TIMERS_H_

void Timer0_Initiate(void);
void Timer0_Disable(void);
void Timer0_SetPreLoadValue(uint8 PreLoadVal);
void Timer0_SetCompareMatchValue(uint8 CompareMatchVal);
Error_t Timer0_SetCallBackFunctionCompareMatch(void (*Timer0_CompareMatchIsr) (void));
Error_t Timer0_SetCallBackFunctionOverFlow(void (*Timer0_OVERFLOWIsr) (void));
void Timer0_PWM_OC0Pin(uint8 CompareMatchValue);

void Timer1_Initiate(void);
void Timer1_Disable(void);
void Timer1_SetPreLoadValue(uint16 value);
void Timer1_SetCompareMatchAValue(uint16 value);
void Timer1_SetCompareMatchBValue(uint16 value);
void Timer1_SetICRValue(uint16 Value);
void Timer1_SetCallBackFunctionOverFlow(void (*Timer1_OVERFLOWIsr) (void));
void Timer1_SetCallBackFunctionCompareMatchA(void (*Timer1_CompareMatch_AIsr) (void));
void Timer1_SetCallBackFunctionCompareMatchB(void (*Timer1_CompareMatch_BIsr) (void));
void Timer1_SetCallBackFunctionCaptureEvent(void (*Timer1_CaptureEventIsr) (void));
void Timer1_PWM_OC1APin(uint16 CompareMatchAValue);
void Timer1_PWM_OC1BPin(uint16 CompareMatchBValue);

void Timer2_Initiate(void);
void Timer2_Disable(void);
void Timer2_SetPreLoadValue(uint8 PreLoadVal);
void Timer2_SetCompareMatchValue(uint8 CompareMatchVal);
Error_t Timer2_SetCallBackFunctionCompareMatch(void (*TIMER2_CompareMatchIsr) (void));
Error_t Timer2_SetCallBackFunctionOverFlow(void (*TIMER2_OVERFLOWIsr) (void));
void Timer2_PWM_OC2Pin(uint8 CompareMatchValue);

void Timer_PWM(uint8 Port, uint8 Pin , uint16 Value);
void Timer0_DisableOC0(void);
void Timer1_DisableOC1A(void);
void Timer1_DisableOC1B(void);
void Timer2_DisableOC2(void);

#endif /* TIMERS_H_ */
