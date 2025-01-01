#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <iomanip>

namespace Calculator
{

    void displayMenu();
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

} // namespace Calculator

#endif // CALCULATOR_H