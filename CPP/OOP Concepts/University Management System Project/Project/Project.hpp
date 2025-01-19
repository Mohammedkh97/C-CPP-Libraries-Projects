#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Course
{
private:
    /* data */
public:
string title;
int courseID;
void details();
    Course(/* args */);
    ~Course();
};

class Department
{
private:
    /* data */
public:
    void details();
    void addCourse();
    Department(/* args */);
    ~Department();
};

class Faculty
{
private:
    /* data */
public:
    string title;
    vector<Student> students{};
    vector<Instructor> nstructors{};
    vector<Employee> employees{};
    vector<Department> depts{};
    void details();
    void addStudents();
    void addInstructor();
    void addEmployee();

    Faculty();
    ~Faculty();
};

class University
{
private:
public:
    string title;
    vector<Faculty> faculties{};
    void details();
    void addFaculty();
    University();
    ~University();
};
