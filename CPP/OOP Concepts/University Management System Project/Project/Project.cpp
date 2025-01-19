#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Person
{
private:
public:
    string name;
    int age;
    int id;
    Person();
    Person(string n, int a, int id);
    virtual void role() = 0;
    ~Person();
};

Person::Person()
{
}
Person::Person(string n, int a, int ID) : name{n}, age{a}, id{ID}
{
}
Person::~Person()
{
}

class Student : public Person
{
private:
    /* data */
public:
    float GPA;
    Student();
    Student(string n, int a, int ID, float gpa);
    void role()
    {
    }
    ~Student();
};

Student::Student()
{
}
Student::Student(string n, int a, int ID, float gpa)
{
    name = n;
    age = a;
    id = ID;
    GPA = gpa;
}

Student::~Student()
{
}

class Instructor : public Person
{
private:
    /* data */
public:
    Instructor();
    Instructor(string n, int a, int ID);
    ~Instructor();

    void role()
    {

    }
};

Instructor::Instructor()
{
}
Instructor::Instructor(string n, int a, int ID)
{
    name = n;
    age = a;
    id = ID;
}
Instructor::~Instructor()
{
}

class Employee : public Person
{
private:
public:
    int salary;
    Employee();
    Employee(string n, int a, int ID, int s);
    ~Employee();
    void role()
    {
    }
};

Employee::Employee()
{
}
Employee::Employee(string n, int a, int ID, int s)
{
    name = n;
    age = a;
    id = ID;
    salary = s;
}

Employee::~Employee()
{
}

class Manager : public Person
{
private:
    int salary;
    static Manager *instance; // The single instance

    // Private constructor to prevent instantiation
    Manager() {}

public:
    void role()
    {
    }
    void setSalary(int Salary);

    int getSalary();

    // Method to get the instance
    static Manager *getInstance()
    {
        if (!instance)
        {
            instance = new Manager();
        }
        return instance;
    }

    void showMessage()
    {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};
// Initialize the static instance to nullptr
Manager *Manager::instance = nullptr;

void Manager::setSalary(int Salary)
{
    salary = Salary;
}
int Manager::getSalary()
{
    return salary;
}

/*==================================================================================*/

class Course
{
private:
    /* data */
public:
    string title;
    int courseID;
    void details();
    Course();
    Course(string t, int courseid);
    ~Course();
};

Course::Course()
{
}
Course::Course(string t, int courseid)
{
    title = t;
    courseID = courseid;
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
    vector<Course> courses{};
    Department();
    ~Department();
};

Department::Department()
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
    string title;
    int courseid;
    cout << "Enter Course name: ";
    cin >> title;
    cout << "Enter Course ID: ";
    cin >> courseid;

    // Create a new Course object
    Course newCourse(title, courseid);

    // Add the new Course to the vector
    courses.push_back(newCourse);

    // Write Course data to a text file
    ofstream outFile("courses.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Course Name: " << title << "            "
                << "Coures ID: " << courseid << endl;
        outFile.close();
        cout << "Course Name added and data written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
class Faculty
{
private:
    /* data */
public:
    string title;
    vector<Student> students{};
    vector<Instructor> instructors{};
    vector<Employee> employees{};
    vector<Department> depts{};
    void details();
    void addStudents();
    void addInstructor();
    void addEmployee();

    Faculty();
    Faculty(string t);
    ~Faculty();
};

Faculty::Faculty()
{
}
Faculty::Faculty(string t)
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
    string name;
    int age;
    int id;
    float gpa;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student GPA: ";
    cin >> gpa;

    // Create a new Student object
    Student newStudent(name, age, id, gpa);

    // Add the new student to the vector
    students.push_back(newStudent);

    // Write student data to a text file
    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name: " << name << " "
                << "Age: " << age << " "
                << "ID: " << id << " "
                << "GPA: " << gpa << endl;
        outFile.close();
        cout << "Student added and data written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
void Faculty::addInstructor()
{
    // Get instructor data from user input or elsewhere
    string name;
    int age, id;

    cout << "Enter instructor name: ";
    cin >> name;
    cout << "Enter instructor age: ";
    cin >> age;
    cout << "Enter instructor ID: ";
    cin >> id;

    // Create a new Instructor object
    Instructor newInstructor(name, age, id);

    // Add the new instructor to the vector
    instructors.push_back(newInstructor);

    // Write instructor data to a text file
    ofstream outFile("instructors.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << name << " " << age << " " << id << endl;
        outFile.close();
        cout << "Instructor added and data written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
void Faculty::addEmployee()
{
    string name;
    int age;
    int id;
    int salary;
    cout << "Enter Employee name: ";
    cin >> name;
    cout << "Enter Employee age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Salary: ";
    cin >> salary;

    // Create a new Employee object
    Employee newEmployee(name, age, id, salary);

    // Add the new Employee to the vector
    employees.push_back(newEmployee);

    // Write Employee data to a text file
    ofstream outFile("employees.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name: " << name << " "
                << "Age: " << age << " "
                << "ID: " << id << " "
                << "Salary: " << salary << endl;
        outFile.close();
        cout << "Employee added and data written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

class University
{
private:
public:
    string title;
    vector<Faculty> faculties{};
    void details();
    void addFaculty();
    University()
    {
    }
    ~University();
};

University::~University()
{
}
void University::details()
{
}
void University::addFaculty()
{
    string title;
    cout << "Enter Faculty name: ";
    getline(cin, title);

    // Create a new faculty object
    Faculty newFaculty(title);

    // Add the new faculty to the vector
    faculties.push_back(newFaculty);

    // Write instructor data to a text file
    ofstream outFile("faculties.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << title << endl;
        outFile.close();
        cout << "Faculty added and data written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

int main()
{
    // vector<Student> students{{"Ahmed", 20, 1001, 3.023}};
    Faculty s1;
    s1.addStudents();
    Faculty i;
    i.addInstructor();
    University f1;
    f1.addFaculty();
    Department c;
    c.addCourse();
    Manager *man = Manager::getInstance();
    man->setSalary(7000);
    cout << man->getSalary();
    return 0;
}