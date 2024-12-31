/*
 * String.cpp
 *
 * Created: 10/17/2023 12:55:05 AM
 *  Author: Mohammed Khalaf
 */

#include "String.hpp"
#include <algorithm>
#include <cctype> // for std::tolower
#include <stdarg.h>
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapPointers(std::string *&p1, std::string *&p2)
{
    std::string *temp = p1;
    p1 = p2;
    p2 = temp;
}

void appendChar(std::string &str, char c)
{
    str.push_back(c); // Utilize std::string's push_back method
}

size_t stringLen(char *str)
{
    char i;
    for (i = 0; str[i]; i++)
    {
    }

    return i;
}

ErrorCode stringCopy(char *emptyString, char *str2, int emptyStringlength, int str_size2)
{
    int length2 = stringLen(str2);
//  std::cout << emptyStringlength << "   " << length2 << std::endl;
    ErrorCode status = OK;
    char i = 0;
    if (emptyStringlength >= str_size2)
    {
        for (i = 0; i < length2; i++)
        {
            emptyString[i] = str2[i];
        }
        emptyString[i] = 0;
        status = OK;
    }
    else if (emptyStringlength < str_size2)
    {
        status = ARRAY_OUT_OF_BOUNDS;
    }
    else
    {
        status = NULL_POINTER_EXCEPTION;
    }

    return status;
}

void stringConcat(std::string &str1, const std::string &str2)
{
    str1 += str2; // Use C++'s operator+= for string concatenation
}
/*
void stringConcat_unlimited(char *str1, int str1_size, ...)
{
    va_list args;
    const char *str2;

    // Initialize the argument list
    va_start(args, str1_size);

    // Iterate through all the additional string arguments
    while ((str2 = va_arg(args, const char *)) != NULL)
    {
        stringConcat(str1, str2);

        // Update the size to prevent buffer overflow
        str1_size -= (int)stringLen(str1);
    }

    // Clean up the argument list
    va_end(args);
}
*/
size_t stringLen(const std::string &str)
{
    return str.size(); // Utilize std::string's size() method
}

void reverseString(std::string &str)
{
    std::reverse(str.begin(), str.end());
}

std::string intToString(int num)
{
    return std::to_string(num); // Use std::to_string for integer to string conversion
}

std::string floatToString(float num, int decimalPlaces)
{
    std::string buffer = std::to_string(num);
    size_t dotPos = buffer.find('.');
    if (dotPos != std::string::npos)
    {
        buffer = buffer.substr(0, dotPos + decimalPlaces + 1);
    }
    return buffer;
}

void printString(const std::string &str)
{
    std::cout << str << std::endl;
}

void printArrayOfPointers(const std::vector<std::string *> &arr)
{
    for (const auto &str : arr)
    {
        if (str)
        {
            std::cout << *str << std::endl;
        }
    }
    std::cout << "==================================" << std::endl;
}

void upperToLower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
                   { return std::tolower(c); });
}

int compareString(const std::string &str1, const std::string &str2)
{
    if (str1 > str2)
        return 1;
    if (str1 < str2)
        return -1;
    return 0;
}

int compareStringIgnoreCase(const std::string &str1, const std::string &str2)
{
    std::string str1Lower = str1;
    std::string str2Lower = str2;
    upperToLower(str1Lower);
    upperToLower(str2Lower);
    return compareString(str1Lower, str2Lower);
}

void sortStrings(std::vector<std::string *> &arrayOfPointers)
{
    std::sort(arrayOfPointers.begin(), arrayOfPointers.end(), [](const std::string *a, const std::string *b)
              { return compareStringIgnoreCase(*a, *b) < 0; });
}

int binarySearchString(const std::vector<std::string *> &arrayOfPointers, const std::string &str)
{
    int left = 0, right = arrayOfPointers.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cmp = compareStringIgnoreCase(*arrayOfPointers[mid], str);
        if (cmp == 0)
            return mid;
        if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
