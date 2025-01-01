#include "Calculator.hpp"

namespace Calculator
{

    void displayMenu()
    {
        std::cout << "\n--- Simple Calculator ---\n";
        std::cout << "Available operations: +  -  *  /" << std::endl;
        std::cout << "Press 'q' to quit.\n";
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double subtract(double a, double b)
    {
        return a - b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    double divide(double a, double b)
    {
        return a / b;
    }

} // namespace Calculator