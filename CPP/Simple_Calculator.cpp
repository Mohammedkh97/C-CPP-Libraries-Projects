#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main()
{
    char operation;
    double num1, num2;
    bool running = true;

    while (running)
    {
        displayMenu();
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Choose operation (+, -, *, /) or q to quit: ";
        cin >> operation;

        if (operation == 'q')
        {

            cout << "Exiting calculator.\n";
            break;
        }

        switch (operation)
        {
        case '+':
            cout << "Result: " << fixed << setprecision(2) << add(num1, num2) << endl;
            break;
        case '-':
            cout << "Result: " << fixed << setprecision(2) << subtract(num1, num2) << endl;
            break;
        case '*':
            cout << "Result: " << fixed << setprecision(2) << multiply(num1, num2) << endl;
            break;
        case '/':
            if (num2 == 0)
            {
                cout << "Error: Division by zero!" << endl;
            }
            else
            {
                cout << "Result: " << fixed << setprecision(2) << divide(num1, num2) << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please try again." << endl;
            break;
        }

        cout << "\n";
    }

    /*
    The setprecision function in C++ is part of the <iomanip> library and is used to control
    the number of digits displayed after the decimal point when printing floating-point numbers.
    How it Works:
    By default, setprecision(n) controls the total number of significant digits displayed
    (both before and after the decimal point).
    When used with fixed, it specifies the number of digits after the decimal point.

    In C++, fixed is a stream manipulator that sets the floating-point output style to
    fixed-point notation. Here's a breakdown:

    What it does:
    Fixed-point notation: When fixed is used, floating-point numbers are displayed with a fixed
    number of digits after the decimal point. This number is determined by the setprecision() manipulator.
    No scientific notation: Unlike scientific notation (which uses exponents), fixed-point notation
    displays the entire number with a decimal point.
    */

    double value = 12.3456789;

    cout << "Default: " << value << endl;
    cout << "setprecision(2): " << setprecision(2) << value << endl;
    cout << "fixed + setprecision(2): " << fixed << setprecision(2) << value << endl;

    double num = 3.14159;
    cout << "Without fixed: " << num << endl;
    cout << "With fixed: " << fixed << num << endl;
    cout << "With fixed and setprecision(2): " << fixed << setprecision(2) << num << endl;

    return 0;
}

void displayMenu()
{
    cout << "\n--- Simple Calculator ---\n";
    cout << "Available operations: +  -  *  /" << endl;
    cout << "Press 'q' to quit.\n";
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
