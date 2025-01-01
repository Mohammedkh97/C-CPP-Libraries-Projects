#include <iostream>
#include <memory> // For smart pointers

class AbstractClass
{
public:
    virtual ~AbstractClass() {}

    void templateMethod()
    {
        primitiveOperation1();
        primitiveOperation2();
    }

    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
};

class ConcreteClass : public AbstractClass
{
public:
    ~ConcreteClass() {}

    void primitiveOperation1()
    {
        std::cout << "Primitive Operation 1" << std::endl;
    }

    void primitiveOperation2()
    {
        std::cout << "Primitive Operation 2" << std::endl;
    }
};

int main()
{
    // AbstractClass *templateClass = new ConcreteClass();
    // templateClass->templateMethod();

    // there is a memory leak because the dynamically allocated object(ConcreteClass) is never deleted.
    // The object templateClass is created using new but is not deleted.This leads to a memory leak.
    // To fix this issue we can use smart pointers(like std::unique_ptr) or manually delete the object after usage.

    // Use unique_ptr to automatically manage memory
    std::unique_ptr<AbstractClass> templateClass = std::make_unique<ConcreteClass>();
    templateClass->templateMethod(); // Calls template method

    // No need to manually delete; unique_ptr will automatically clean up
}