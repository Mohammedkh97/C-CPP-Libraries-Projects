#include <iostream>
#include <array>
using namespace std;

/*2-write unit test for test if the sum of two number is less than 5 print "low sum case" otherwise
 print "high sum case" to the console , and entered name from console intput and test for length
 of this name less than 10 print "low name case" otherwise print "high name case".
*/

bool sum(int num1, int num2)
{
    int res = num1 + num2;
    return res > 5;
}
void isHigh()
{
    if (sum)
        cout << "high sum case";
}
void isLow()
{
    if(!sum)
    cout << "low sum case";
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp" // Include the Catch2 library

#include <iostream>
#include <string>

bool isLowSum(int a, int b)
{
    return a + b < 5;
}

bool isHighSum(int a, int b)
{
    return !isLowSum(a, b);
}

TEST_CASE("Sum of Two Numbers")
{
    REQUIRE(isLowSum(1, 2));
    REQUIRE(isHighSum(3, 3));
    REQUIRE(isHighSum(4, 4));
    REQUIRE(isLowSum(5, 6));
}

// Function to validate name length
bool isLowNameLength(const std::string &name)
{
    return name.length() < 10;
}

bool isHighNameLength(const std::string &name)
{
    return !isLowNameLength(name);
}

TEST_CASE("Name Length")
{
    REQUIRE(isLowNameLength("John"));
    REQUIRE(isHighNameLength("Christopher"));
    REQUIRE(isHighNameLength("Elizabeth"));
    REQUIRE(isLowNameLength("Alexander"));
}
