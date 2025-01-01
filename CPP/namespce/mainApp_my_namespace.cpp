#include "my_namespace.hpp"
#include <iostream>
int main()
{
    std::cout << "PI: " << MyNamespace::PI << std::endl;
    std::cout << "Sum: " << MyNamespace::add(5, 3) << std::endl;
    return 0;
}