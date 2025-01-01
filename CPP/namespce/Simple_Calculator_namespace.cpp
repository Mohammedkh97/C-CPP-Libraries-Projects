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

using namespace Calculator;

int main()
{
    char operation;
    double num1, num2;
    bool running = true;

    while (running)
    {
        displayMenu();
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;
        std::cout << "Choose operation (+, -, *, /) or q to quit: ";
        std::cin >> operation;

        if (operation == 'q')
        {
            std::cout << "Exiting calculator.\n";
            break;
        }

        switch (operation)
        {
        case '+':
            std::cout << "Result: " << std::fixed << std::setprecision(2) << add(num1, num2) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << std::fixed << std::setprecision(2) << subtract(num1, num2) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << std::fixed << std::setprecision(2) << multiply(num1, num2) << std::endl;
            break;
        case '/':
            if (num2 == 0)
            {
                std::cout << "Error: Division by zero!" << std::endl;
            }
            else
            {
                std::cout << "Result: " << std::fixed << std::setprecision(2) << divide(num1, num2) << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation. Please try again." << std::endl;
            break;
        }

        std::cout << "\n";
    }

    return 0;
}

void Calculator::displayMenu()
{
    std::cout << "\n--- Simple Calculator ---\n";
    std::cout << "Available operations: +  -  *  /" << std::endl;
    std::cout << "Press 'q' to quit.\n";
}

double Calculator::add(double a, double b)
{
    return a + b;
}

double Calculator::subtract(double a, double b)
{
    return a - b;
}

double Calculator::multiply(double a, double b)
{
    return a * b;
}

double Calculator::divide(double a, double b)
{
    return a / b;
}