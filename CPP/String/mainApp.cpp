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

    return 0;
}
