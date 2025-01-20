#include "Faculty.hpp"
#include <iostream>
#include <fstream>

Faculty::Faculty() {}

Faculty::Faculty(string t) : title{t} {}

Faculty::~Faculty() {}

void Faculty::details()
{
    cout << "Faculty Details" << endl;
}

void Faculty::addStudents()
{
    string name;
    int age, id;
    float gpa;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student GPA: ";
    cin >> gpa;

    Student newStudent(name, age, id, gpa);
    students.push_back(newStudent);

    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name: " << name << " "
                << "Age: " << age << " "
                << "ID: " << id << " "
                << "GPA: " << gpa << endl;
        outFile.close();
        cout << "Student added and written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void Faculty::addInstructor()
{
    string name;
    int age, id;

    cout << "Enter instructor name: ";
    cin >> name;
    cout << "Enter instructor age: ";
    cin >> age;
    cout << "Enter instructor ID: ";
    cin >> id;

    Instructor newInstructor(name, age, id);
    instructors.push_back(newInstructor);

    ofstream outFile("instructors.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << name << " " << age << " " << id << endl;
        outFile.close();
        cout << "Instructor added and written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

void Faculty::addEmployee()
{
    string name;
    int age, id, salary;
    cout << "Enter Employee name: ";
    cin >> name;
    cout << "Enter Employee age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Salary: ";
    cin >> salary;

    Employee newEmployee(name, age, id, salary);
    employees.push_back(newEmployee);

    ofstream outFile("employees.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name: " << name << " "
                << "Age: " << age << " "
                << "ID: " << id << " "
                << "Salary: " << salary << endl;
        outFile.close();
        cout << "Employee added and written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
