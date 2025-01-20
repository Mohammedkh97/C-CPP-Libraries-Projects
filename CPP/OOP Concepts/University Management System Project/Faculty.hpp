#ifndef FACULTY_H
#define FACULTY_H

#include <vector>
#include "Person.hpp"
#include "Department.hpp"

class Faculty
{
public:
    string title;
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Employee> employees;
    vector<Department> depts;

    Faculty();
    Faculty(string t);
    ~Faculty();

    void details();
    void addStudents();
    void addInstructor();
    void addEmployee();
};

#endif
