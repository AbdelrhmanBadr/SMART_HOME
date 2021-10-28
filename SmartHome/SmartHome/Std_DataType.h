/** @file Std_DataType.h
*
* @brief This file is used to define standarded data types in AVR (unsigned and signed) integers and floats.
* @layer Service
* @note	THIS FILE MUST BE INCLUDED IN ALL SOURCE FILES
* @author Abdelrhman Badr
* @last update 27-sep-21
*/

#ifndef  STD_DATATYPES_H_
#define STD_DATATYPES_H_

/*unsigned datatypes*/
typedef unsigned char 		uint8;
typedef unsigned short 		uint16;
typedef unsigned long 		uint32;
typedef unsigned long long 	uint64;

/*signed datatypes*/
typedef signed char 		 int8;
typedef signed short 		 int16;
typedef signed long 		 int32;
typedef signed long long     int64;

/*float datatypes*/
typedef float 	float32_t;
typedef double 	float64_t;

/*bool*/
typedef enum
{
	false,true,
}bool;
#endif /* STD_DATATYPES_H_ */
