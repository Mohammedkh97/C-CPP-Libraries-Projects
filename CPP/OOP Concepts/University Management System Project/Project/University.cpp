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
    Course();
    ~Course();
};

Course::Course()
{
}

Course::~Course()
{
}
void Course::details()
{
}

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

Department::Department(/* args */)
{
}

Department::~Department()
{
}
void Department::details()
{
}
void Department::addCourse()
{
}
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

Faculty::Faculty(/* args */)
{
}

Faculty::~Faculty()
{
}
void Faculty::details()
{
}
void Faculty::addStudents()
{
}
void Faculty::addInstructor()
{
}
void Faculty::addEmployee()
{
}

class University
{
private:
public:
    string title;
    vector<Faculty> faculties{};
    Manager manager;
    void details();
    void addFaculty();
    University();
    ~University();
};

University::University()
{
}

University::~University()
{
}
void University::details()
{
}
void University::addFaculty()
{
}
int main()
{
    return 0;
}
