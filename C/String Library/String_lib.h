/*
 * String.h
 *
 * Created: 10/17/2023 12:55:05 AM
 * Author: Mohammed Khalaf
 */


#ifndef STRING_STRING_LIB_H_
#define STRING_STRING_LIB_H_
#include "stdTypes.h"

void swapMethod1(s16 *x, s16 *y);
void swapPointers(u8 **p1, u8 **p2);
void appendChar(u8 *str, u8 c, u16 str_size);
void stringConcat(u8 *str1, u8 *str2, u16 str1_size);
void stringConcat_unlimited(u8 *str1, u16 str1_size, ...);
u16 string_len(u8 *str);
void reverseString(u8 *str);
void intoString(s32 num, u8 *str);
void floatToString(f32 num, u8 *buffer, u16 decimalPlaces);
void printString(u8 *str);
void printArrayOfPointers(u8 **arr, u16 size);
void UpperTolower(u8 *str);
u8 compareChar(u8 *str1, u8 *str2);
u8 compareCharNotCaseSensitive(u8 *str1, u8 *str2);
void sortStrings(u8 **arrayOfPointers, u16 size);
u8 binarySearchString(u8 **arrayOfPointers, u16 size, u8 *str);
void *memorySet(void *ptr, u8 value, u8 size);


#endif /* STRING_STRING_LIB_H_ */
