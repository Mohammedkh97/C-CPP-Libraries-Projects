#include "Person.hpp"
#include <iostream>

Person::Person() {}

Person::Person(string n, int a, int ID) : name{n}, age{a}, id{ID} {}

Person::~Person() {}

Student::Student() {}

Student::Student(string n, int a, int ID, float gpa) : Person(n, a, ID), GPA{gpa} {}

void Student::role()
{
    cout << "Student Role" << endl;
}

Student::~Student() {}

Instructor::Instructor() {}

Instructor::Instructor(string n, int a, int ID) : Person(n, a, ID) {}

void Instructor::role()
{
    cout << "Instructor Role" << endl;
}

Instructor::~Instructor() {}

Employee::Employee() {}

Employee::Employee(string n, int a, int ID, int s) : Person(n, a, ID), salary{s} {}

void Employee::role()
{
    cout << "Employee Role" << endl;
}

Employee::~Employee() {}
