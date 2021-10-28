/*
 * SevenSegment.h
 *
 *  Created on: Sep 29, 2021
 *      Author: Abdelrhman
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

/*Define seven segment types*/
#define SEVEN_SEGMENT_COMMON_CATHODE	(1)
#define SEVEN_SEGMENT_COMMON_ANODE		(2)

typedef struct
{
	uint8 _7SegPort;
	uint8 _7SegType;
}SevenSegment_t;

Error_t SevenSegment_Setup(SevenSegment_t *_7Seg);
Error_t SevenSegment_DisplayNumber(SevenSegment_t *_7Seg , uint8 Number);
Error_t SevenSegment_TurnOff(SevenSegment_t *_7Seg );
#endif /* SEVENSEGMENT_H_ */
