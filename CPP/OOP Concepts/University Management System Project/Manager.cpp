#include "Manager.hpp"
#include <iostream>

Manager *Manager::instance = nullptr;

void Manager::role()
{
    std::cout << "Manager Role\n";
}

void Manager::setSalary(int Salary)
{
    salary = Salary;
}

int Manager::getSalary()
{
    return salary;
}

Manager *Manager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Manager();
    }
    return instance;
}

void Manager::showMessage()
{
    std::cout << "Manager message.\n";
}
