# University Management System

This project implements a **University Management System** designed to manage the administration of university entities such as **Students**, **Instructors**, **Employees**, **Courses**, **Departments**, **Faculties**, and **University** itself.

## Features

- **Person Class Hierarchy**: 
  - The `Person` class serves as a base class for `Student`, `Instructor`, and `Employee`. Each class represents different roles within the university.
  - **Student**: Manages student-specific attributes such as GPA and ID.
  - **Instructor**: Stores information related to instructors, including their name, age, and ID.
  - **Employee**: Manages employee data, including salary, name, and ID.

- **Course Management**: 
  - The `Course` class allows for storing course details such as course name and ID.
  - The system provides functionality for adding new courses to a department.

- **Department Management**:
  - The `Department` class manages multiple courses and provides functionality to add courses to the department.
  - It also stores a list of courses offered by the department and writes course information to a file.

- **Faculty Management**:
  - The `Faculty` class allows the management of multiple students, instructors, and employees within a faculty.
  - Users can add new students, instructors, and employees, which are stored and written to respective text files.

- **University Structure**:
  - The `University` class represents the university as a whole, allowing users to manage multiple faculties.
  - Faculties can be added, and their information is stored in a file for persistence.

- **File Management**:
  - Course, student, instructor, employee, and faculty information is written to respective text files (`courses.txt`, `students.txt`, `instructors.txt`, `employees.txt`, `faculties.txt`).
  - This ensures persistence and tracking of entities within the system.

- **Singleton Design Pattern**:
  - A `Manager` class is implemented as a Singleton, ensuring only one instance of the manager can be created.
  - The `Manager` class manages the salary of employees and provides a method to show messages.

- **Modular Code**:
  - The project is divided into multiple files to ensure clean and organized code. Key components like classes for `Person`, `Course`, `Faculty`, `Department`, and `University` are separated into individual files.

## Usage

- Add new faculties, courses, students, instructors, and employees using the provided prompts.
- View the added entities through the details function for each respective class.


Here’s an example of a UML class diagram for your **University Management System** project:

### UML Class Diagram

```plaintext
+----------------------------------------------------+
|                   Person                          |
+----------------------------------------------------+
| - name: string                                     |
| - age: int                                         |
| - id: int                                          |
+----------------------------------------------------+
| + Person()                                         |
| + Person(n: string, a: int, id: int)               |
| + virtual void role() = 0                          |
| + ~Person()                                        |
+----------------------------------------------------+
           /       |      \
          /        |       \
    +-----------+  +------------+   +-----------+
    |  Student  |  | Instructor |   |  Employee |
    +-----------+  +------------+   +-----------+
    | - GPA: float|  |            |   | - salary: int |
    +-----------+  +------------+   +-----------+
    | + Student() |  | + role()   |   | + Employee() |
    | + role()    |  | + ~Instructor()| | + role()    |
    | + ~Student()|  |               |   | + ~Employee()|
    +-----------+  +------------+   +-----------+

                      +----------------+
                      |     Manager    |
                      +----------------+
                      | - salary: int  |
                      | - instance: Manager*|
                      +----------------+
                      | + getSalary(): int|
                      | + setSalary(int)  |
                      | + showMessage(): void|
                      | + static getInstance(): Manager*|
                      +----------------+

+----------------------------------------------------+
|                   Course                          |
+----------------------------------------------------+
| - title: string                                   |
| - courseID: int                                    |
+----------------------------------------------------+
| + Course()                                         |
| + Course(t: string, courseid: int)                 |
| + ~Course()                                        |
| + void details()                                   |
+----------------------------------------------------+

+----------------------------------------------------+
|                   Department                      |
+----------------------------------------------------+
| - courses: vector<Course>                          |
+----------------------------------------------------+
| + Department()                                     |
| + ~Department()                                    |
| + void details()                                   |
| + void addCourse()                                 |
+----------------------------------------------------+

+----------------------------------------------------+
|                   Faculty                         |
+----------------------------------------------------+
| - title: string                                    |
| - students: vector<Student>                        |
| - instructors: vector<Instructor>                  |
| - employees: vector<Employee>                      |
| - depts: vector<Department>                        |
+----------------------------------------------------+
| + Faculty()                                        |
| + Faculty(t: string)                               |
| + ~Faculty()                                       |
| + void details()                                   |
| + void addStudents()                               |
| + void addInstructor()                             |
| + void addEmployee()                               |
+----------------------------------------------------+

+----------------------------------------------------+
|                   University                      |
+----------------------------------------------------+
| - faculties: vector<Faculty>                       |
+----------------------------------------------------+
| + University()                                     |
| + ~University()                                    |
| + void details()                                   |
| + void addFaculty()                                |
+----------------------------------------------------+
```

### Explanation of the UML Diagram:

- **Person Class**: The abstract base class representing a generic person with common attributes (`name`, `age`, `id`) and a pure virtual method `role()`. Derived classes are `Student`, `Instructor`, and `Employee`.
- **Student**: Inherits from `Person` and adds a `GPA` attribute. Implements `role()`.
- **Instructor**: Inherits from `Person` and implements `role()`. 
- **Employee**: Inherits from `Person` and adds a `salary` attribute. Implements `role()`.
- **Manager**: Singleton class that manages salary and prints a message.
- **Course**: Represents a university course, containing `title` and `courseID` attributes, and includes a `details()` method to display course information.
- **Department**: Contains a vector of `Course` objects and provides methods to add and display courses.
- **Faculty**: Holds multiple `Student`, `Instructor`, and `Employee` objects, as well as multiple `Department` objects. It manages adding and displaying students, instructors, and employees.
- **University**: Manages multiple `Faculty` objects and provides methods to add and display faculties.

The relationships between the classes are:

- **Person** is the base class for **Student**, **Instructor**, and **Employee** (inheritance).
- **Faculty** aggregates **Student**, **Instructor**, **Employee**, and **Department** (composition).
- **University** aggregates **Faculty** (composition).
- **Department** aggregates **Course** (composition).
- **Manager** is a Singleton and does not directly relate to other classes.

This UML class diagram helps in visualizing the structure of the project and understanding how the components interact with each other.

## Contributors

- **Mohammed Khalaf** – *Project Lead and Developer*


