/*
The using namespace directive can be declared inside a block or function,
where it is valid only within those scopes:
*/

#include <iostream>
using namespace std;

namespace People
{
    class Employee
    {
    public:
        void display()
        {
            cout << "Employee created!" << endl;
        }
    };
}

void f()
{
    using namespace People;
    Employee e;
    e.display();
}

void g()
{
    {
        using namespace People;
        Employee e;
        e.display();
    }
    // Employee e; // Error: 'Employee' is not defined in this scope
}

int main()
{
    f();
    g();
    return 0;
}
