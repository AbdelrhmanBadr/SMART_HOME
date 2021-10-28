/*
 * CLCD.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Abdelrhman
 */

#ifndef CLCD_H_
#define CLCD_H_


void CLCD_Setup(void);
void CLCD_PrintString(char *str);
void CLCD_SetCursor(uint8 x_position , uint8 y_position);
void CLCD_PrintString(char *str);
void CLCD_SetCursor(uint8 x_position , uint8 y_position);
void CLCD_BlinkCursor(void);
void CLCD_NoBlinkCursor(void);
void CLCD_TurnOnCursor(void);
void CLCD_TurnOffCursor(void);
void CLCD_TurnOnDisplay(void);
void CLCD_TurnOffDisplay(void);
void CLCD_ShiftCursorRight(void);
void CLCD_ShiftCursorLeft(void);
void CLCD_ShiftDisplayLeft(void);
void CLCD_ShiftDisplayRight(void);
void CLCD_PrintChar(char Ch);
void CLCD_PrintNumber(int16 Number);
void CLCD_StoreSpecialCharater(uint8 PixelsArray[] , uint8 Location);
void CLCD_PrintSpecialCharacter(uint8 Location);
void CLCD_ClearCLCD(void);
void CLCD_PrintFloat(float32_t Number);


#endif /* CLCD_H_ */
