/*
 * String.c
 *
 * Created: 5/17/2023 12:55:05 AM
 *  Author: Mohammed Khalaf
 */

#include "stdTypes.h"
#include <stdarg.h>
#include "String_lib.h"

// Swaps the values of two integers using a temporary variable.
void swapMethod1(s16 *x, s16 *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Swaps the pointers of two strings (pointer to pointer), effectively swapping their addresses.
void swapPointers(u8 **p1, u8 **p2)
{
    u8 *temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Appends a character to the end of a string, ensuring there is space in the string buffer.
void appendChar(u8 *str, u8 c, u16 str_size)
{
    // Move to the end of the string
    while (*str && --str_size)
    {
        str++;
    }

    // If there's space, append the character
    if (str_size > 1)
    {
        *str = c;
        str++;
        *str = '\0';
    }
}

// Concatenates two strings, str2 is appended to the end of str1.
void stringConcat(u8 *str1, u8 *str2, u16 str1_size)
{
    // Move to the end of str1
    while (*str1 && --str1_size)
    {
        str1++;
    }

    // Copy characters from str2 to str1
    while (*str2 && --str1_size)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }

    // Null-terminate the result string
    *str1 = '\n';
}

// Concatenates multiple strings (passed as variadic arguments) into str1, with each string added in sequence.
void stringConcat_unlimited(u8 *str1, u16 str1_size, ...)
{
    va_list args;
    u8 *str2;

    // Initialize the argument list
    va_start(args, str1_size);

    // Iterate through all the additional string arguments
    while ((str2 = va_arg(args, const u8 *)) != Null_Ptr)
    {
        stringConcat(str1, str2, str1_size);

        // Update the size to prevent buffer overflow
        str1_size -= (u16)string_len(str1);
    }

    // Clean up the argument list
    va_end(args);
}

// Returns the length of the given string (not including the null-terminator).
u16 string_len(u8 *str)
{
    u8 i;
    for (i = 0; str[i]; i++)
    {
    }

    return i;
}

// Reverses the order of characters in a string.
void reverseString(u8 *str)
{
    u16 temp;
    u16 length = string_len(str);
    for (u16 i = 0; i < length / 2; i++)
    {
        temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Converts a signed integer to a string representation, handling negative numbers.
void intoString(s32 num, u8 *str)
{
    u16 rem = 0, i = 0;
    // Corner case if the number is zero
    if (num == 0)
    {
        str[0] = '0';
        str[1] = 0;
        return;
    }

    for (i = 0; num != 0; i++)
    {
        if (num < 0)
        {
            num = num * (-1);
            for (i = 0; num != 0; i++)
            {
                rem = num % 10;
                str[i] = rem + '0';
                num = num / 10;
            }
            str[i] = '-';
        }
        else
        {
            rem = num % 10;
            str[i] = rem + '0';
            num = num / 10;
        }
    }
    str[i] = 0;
    reverseString(str);
}

// Converts a floating point number to a string with a specified number of decimal places.
void floatToString(f32 num, u8 *buffer, u16 decimalPlaces)
{
    // Handle negative numbers
    if (num < 0)
    {
        *buffer++ = '-';
        num = -num;
    }

    // Convert the integer part to string
    int intPart = (int)num;
    intoString(intPart, buffer); // Convert integer part to string

    // Move the buffer pointer to the end of the integer part
    while (*buffer != '\0')
    {
        buffer++;
    }

    // Append decimal point
    *buffer++ = '.';

    // Convert the fractional part to string
    f32 fractionalPart = num - intPart;
    for (u8 i = 0; i < decimalPlaces; i++)
    {
        fractionalPart *= 10;
        int digit = (int)fractionalPart;
        *buffer++ = '0' + digit;
        fractionalPart -= digit;
    }

    // Null-terminate the string
    *buffer = '\0';
}

// Converts all uppercase letters in the string to lowercase.
void UpperTolower(u8 *str)
{
    for (u16 i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// Compares two strings lexicographically. Returns 1 if str1 is greater, 2 if str2 is greater, or 0 if they are equal.
u8 compareChar(u8 *str1, u8 *str2)
{
    for (int i = 0; (str1[i] || str2[i]); i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return 2;
        }
    }
    return 0; // if the two strings are the same
}

// Compares two strings without considering case. Returns 1 if str1 is greater, 2 if str2 is greater, or 0 if they are equal.
u8 compareCharNotCaseSensitive(u8 *str1, u8 *str2)
{
    for (u16 i = 0; (str1[i] || str2[i]); i++)
    {
        if (str1[i] > str2[i] || (str1[i] == str2[i] - 'A' + 'a') || (str2[i] == str1[i] - 'A' + 'a'))
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return 2;
        }
    }
    return 0; // if the two strings are the same
}

// Sorts an array of strings in lexicographical order using a case-insensitive comparison.
void sortStrings(u8 **arrayOfPointers, u16 size)
{
    // We can use Bubble sort Technique:
    for (u16 i = 0; i < size; i++)
    {
        for (u16 j = 0; j < size - 1 - i; j++)
        {
            if (compareCharNotCaseSensitive(arrayOfPointers[j], arrayOfPointers[j + 1]) == 1)
            {
                swapPointers(&arrayOfPointers[j], &arrayOfPointers[j + 1]); // Both are right
            }
        }
    }
}

// Performs a binary search on an array of strings. Returns the index of the matching string or -1 if not found.
u8 binarySearchString(u8 **arrayOfPointers, u16 size, u8 *str)
{
    u16 first = 0, last = size - 1, middle = 0;
    while (last >= first)
    {
        middle = (first + last) / 2;
        if (compareCharNotCaseSensitive(arrayOfPointers[middle], str) == 0)
        {
            return middle;
        }
        else if (compareCharNotCaseSensitive(arrayOfPointers[middle], str) == 1)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return -1;
}

// Fills a block of memory with a specified value (similar to memset).
void *memorySet(void *ptr, u8 value, u8 size)
{
    u8 *byte_ptr = ptr; // Cast pointer to unsigned char pointer
    // Fill the memory block byte-by-byte
    while (size--)
    {
        *byte_ptr++ = (u8)value; // Set byte value and move pointer
    }

    return ptr; // Return the original pointer
}
