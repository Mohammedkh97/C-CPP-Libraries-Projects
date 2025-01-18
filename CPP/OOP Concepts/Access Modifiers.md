In C++, **private**, **protected**, and **public** are access specifiers that control the visibility and 
accessibility of class members (data members and member functions). Here's a detailed comparison:

### **1. Private:**
   - **Visibility**: Members declared as `private` are accessible only within the same class.
   - **Inheritance**: Private members are not directly accessible by derived classes.
   - **Use Case**: Typically used for data or methods that should not be exposed or modified outside the class (encapsulation).

   ```cpp
   class Example {
   private:
       int secretValue; // Only accessible within the Example class
   public:
       void setValue(int val) { secretValue = val; } // Accessor method
   };
   ```

---

### **2. Protected:**
   - **Visibility**: Members declared as `protected` are accessible within the same class and by derived classes.
   - **Inheritance**: Useful when you want derived classes to have access to certain members but do not want them exposed publicly.
   - **Use Case**: Commonly used when you need inheritance-specific access.

   ```cpp
   class Base {
   protected:
       int value; // Accessible by Base and derived classes
   };

   class Derived : public Base {
   public:
       void setValue(int val) { value = val; } // Derived can access `value`
   };
   ```

---

### **3. Public:**
   - **Visibility**: Members declared as `public` are accessible from anywhere, including outside the class.
   - **Inheritance**: Public members are inherited as public in the derived class (depending on the inheritance type).
   - **Use Case**: Used for methods and attributes that should be accessible to other parts of the program.

   ```cpp
   class Example {
   public:
       int publicValue; // Accessible by anyone
   };
   ```

---

### Example Demonstration:

```cpp
#include <iostream>
using namespace std;

class Base {
private:
    int privateValue = 10; // Only accessible within Base
protected:
    int protectedValue = 20; // Accessible by Base and Derived
public:
    int publicValue = 30; // Accessible everywhere

    void showValues() {
        cout << "Private: " << privateValue << endl;
        cout << "Protected: " << protectedValue << endl;
        cout << "Public: " << publicValue << endl;
    }
};

class Derived : public Base {
public:
    void accessValues() {
        // cout << privateValue; // Error: privateValue is private
        cout << "Protected: " << protectedValue << endl; // Allowed
        cout << "Public: " << publicValue << endl;       // Allowed
    }
};

int main() {
    Base base;
    base.showValues();
    // base.privateValue = 15; // Error: privateValue is private
    // base.protectedValue = 25; // Error: protectedValue is protected
    base.publicValue = 35; // Allowed

    Derived derived;
    derived.accessValues();

    return 0;
}
```

---

### Summary Table:
| Specifier    | Accessible in Same Class | Accessible in Derived Class | Accessible Outside Class |
|--------------|---------------------------|-----------------------------|---------------------------|
| **private**  | Yes                       | No                          | No                        |
| **protected**| Yes                       | Yes                         | No                        |
| **public**   | Yes                       | Yes                         | Yes                       |