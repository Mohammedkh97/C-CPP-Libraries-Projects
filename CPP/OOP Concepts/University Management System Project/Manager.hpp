#ifndef MANAGER_H
#define MANAGER_H

class Manager
{
private:
    int salary;
    static Manager *instance;

    Manager() {}

public:
    void role();
    void setSalary(int Salary);
    int getSalary();

    static Manager *getInstance();

    void showMessage();
};

#endif
