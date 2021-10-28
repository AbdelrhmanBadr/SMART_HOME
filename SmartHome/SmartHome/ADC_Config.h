/*
 * ADC_Config.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Abdelrhman
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_CONVERSION_TIME	(50000)
/*
 * Select the Voltage reference mode:
 * 1) ADC_AREF --> when the refernce voltage is connected to AREF pin
 * 2) ADC_AVCC --> when the refernce voltage is connected to AVCC pin
 * 3) ADC_INTERNAL_VOLT --> when the refence voltage is internal voltage 2.56 volt
 */
#define ADC_VOLTAGE_REFERENCE_MODE		(ADC_AVCC)

/*
 * Control the ADC interrupt flag
 * ADC_INTERRUPT_ENABLE  --> enable  ADC_interrupt
 * ADC_INTERRUPT_DISABLE --> disable ADC_interrupt
 */
#define ADC_INTERRUPT	(ADC_INTERRUPT_DISABLE)

/*
 * ADC Prescaler Selections
 * ADC_FOSC_OVER_2		ADC_FOSC_OVER_4		ADC_FOSC_OVER_8
 * ADC_FOSC_OVER_16		ADC_FOSC_OVER_32	ADC_FOSC_OVER_64
 * ADC_FOSC_OVER_128
 * These configuration determine the division factor between the XTAL frequency and the input
 * clock to the ADC.
 */
#define ADC_FREQUENCY		(ADC_FOSC_OVER_64)

/*
 * ADC adjust mode
 * ===============
 * 8	-->  The digital will be at 8 bits
 * 10 -->  The digital result will be at 10 bits
 */
#define ADC_NUMBER_OF_BITS		(8)

/*
 * Auto triggering source
 * ======================
 * ADC_FREE_RUNNING_MODE
 * ADC_ANALOG_COMPARATOR
 * ADC_EXTERNAL_INT0
 * ADC_TIMER0_COMPARE_MATCH
 * ADC_TIMER0_OVERFLOW
 * ADC_TIMER1_COMPARE_MATCH_B
 * ADC_TIMER1_OVERFLOW
 * ADC_TIMER1_CAPTURE_EVENT
 * ADC_SINGLE_CONVERSION
 */
#define ADC_TRIGGER_SOURCE		(ADC_FREE_RUNNING_MODE)

#endif /* ADC_CONFIG_H_ */
