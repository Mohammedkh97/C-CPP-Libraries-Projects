#include <stdio.h>
#include "String_lib.h"

/*************************************** Global Variables  ***************************/
u8 name[15] = "MOHAMMED";
int main ()
{
    UpperTolower(name);
    printf("Name after conversion: %s\n", name);
/////////////////////////////////////////////////////////////////////
    reverseString(name);
    printf("Name after reverse: %s\n", name);
}