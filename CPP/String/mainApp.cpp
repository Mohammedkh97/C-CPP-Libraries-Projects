#include <iostream>
#include "String.hpp"
#define ARRAY_SIZE 10
int main()
{

    std::string str1 = "Hello";
    std::string str2 = "World";
    char string2[10] = "Mohammed";
    appendChar(str1, '!');
    //  stringConcat(str1, str2);
    //     printString(str1); // Should print: "Hello!World"

    //     std::vector<std::string *> vec = {&str1, &str2}; // That will store pointers to std::string objects.
    // //*                                                     The type std::string * means a pointer to a std::string.
    //     std::cout << "Vec. Elements: ";  // includes str1, str2 addresses
    //     for (auto i: vec)
    //     {
    //         std::cout << i << "  ";
    //     }
    //     std::cout << std::endl;

    //     sortStrings(vec);
    //     printArrayOfPointers(vec);

    //     std::string searchStr = "world";
    //     int index = binarySearchString(vec, searchStr);
    //     if (index != -1)
    //     {
    //         std::cout << "Found " << searchStr << " at index " << index << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << searchStr << " not found!" << std::endl;
    //     }
    char emptyString[ARRAY_SIZE];
    stringCopy(emptyString, string2, ARRAY_SIZE, sizeof(string2));
    std::cout << emptyString << std::endl;

/*==========================================================================*/

    //   std::string str;
    char str[100]; // assuming max length of input is 99 characters
    char ch = 0;
    int i = 0;
    std::cout << "Enter a string: ";
    //    ch = std::cin.get(); // Read one character at a time
    // Read characters using a for loop
    for (i = 0; i < (sizeof(str) - 1); i++)
    {
        ch = std::cin.get(); // Read one character at a time
        //    std::cin >> str[i];
        /*  Why std::cin.get() is needed : std::cin >> str[i] will not capture spaces or newlines because it skips whitespace.
            This is why std::cin.get() is used instead, as it can read all characters including spaces and the newline.if (ch == '\n')
        */
        if (ch == '\n')
        {                  // Stop when Enter key (newline) is pressed
            str[i] = '\0'; // Null-terminate the string
            break;
        }

        str[i] = ch; // Store the character in the string array
    }
    str[i] = '\0'; // Null-terminate the string

    std::cout << "You entered: " << str << std::endl;

    return 0;
}
