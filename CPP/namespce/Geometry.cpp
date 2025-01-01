#include <iostream>

namespace Geometry
{
    const double PI = 3.14159;

    double areaOfCircle(double radius)
    {
        return PI * radius * radius;
    }

    double areaOfRectangle(double width, double height)
    {
        return width * height;
    }
}

int main()
{
    double circleRadius = 5.0;
    double rectangleWidth = 4.0;
    double rectangleHeight = 6.0;

    // Using the scope resolution operator (::)
    std::cout << "Area of circle: " << Geometry::areaOfCircle(circleRadius) << std::endl;
    std::cout << "Area of rectangle: " << Geometry::areaOfRectangle(rectangleWidth, rectangleHeight) << std::endl;

    return 0;
}

/*
Explanation:

1. Namespace Declaration:
   - namespace Geometry { ... } defines a namespace named "Geometry".
   - Inside this namespace, we define a constant `PI` and two functions: "areaOfCircle()" and "areaOfRectangle()".

2. Using Scope Resolution Operator:
   - In the main() function, we use the scope resolution operator (::) to access the members of the "Geometry" namespace:
      - Geometry::areaOfCircle(circleRadius)
      - Geometry::areaOfRectangle(rectangleWidth, rectangleHeight)

Key Points:

* This example demonstrates how a namespace can be used to group related geometric functions and a constant.
* The Geometry namespace provides a clear separation between these geometric functions and any other functions 
or variables in the program.
* Using the scope resolution operator allows you to access members of the namespace explicitly.

This example illustrates how namespaces can improve code organization and prevent potential naming conflicts,
especially when dealing with multiple libraries or modules that might have functions or variables with
the same names.
*/