#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    int id;

    Person();
    Person(string n, int a, int id);
    virtual void role() = 0;
    virtual ~Person();
};

class Student : public Person
{
public:
    float GPA;
    Student();
    Student(string n, int a, int ID, float gpa);
    void role() override;
    ~Student();
};

class Instructor : public Person
{
public:
    Instructor();
    Instructor(string n, int a, int ID);
    void role() override;
    ~Instructor();
};

class Employee : public Person
{
public:
    int salary;
    Employee();
    Employee(string n, int a, int ID, int s);
    void role() override;
    ~Employee();
};

#endif
