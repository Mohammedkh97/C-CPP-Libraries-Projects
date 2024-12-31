/*
 * String.hpp
 *
 * Created: 10/17/2023 12:55:05 AM
 *  Author: Mohammed Khalaf
 */

#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <vector>
#include <iostream>

typedef enum
{
    OK,                 // Operation successful
    SEGMENTATION_FAULT, // Segmentation fault: Accessing memory outside the program's allocated range
    ARRAY_OUT_OF_BOUNDS,
    NULL_POINTER_EXCEPTION,
    STRING_TOO_LONG,
    MEMORY_EXCEEDED // Memory exceeded: Attempting to allocate more memory than is available
} ErrorCode;

/********************************************* Function Prototypes *************************************/

void
swap(int &x, int &y);
void swapPointers(std::string *&p1, std::string *&p2);
void appendChar(std::string &str, char c);
ErrorCode stringCopy(char *emptyString, char *str2, int str_size1, int str_size2);
void stringConcat(std::string &str1, const std::string &str2);
size_t stringLen(const std::string &str);
void reverseString(std::string &str);
std::string intToString(int num);
std::string floatToString(float num, int decimalPlaces);
void printString(const std::string &str);
void printArrayOfPointers(const std::vector<std::string *> &arr);
void upperToLower(std::string &str);
int compareString(const std::string &str1, const std::string &str2);
int compareStringIgnoreCase(const std::string &str1, const std::string &str2);
void sortStrings(std::vector<std::string *> &arrayOfPointers);
int binarySearchString(const std::vector<std::string *> &arrayOfPointers, const std::string &str);

#endif // STRING_HPP
