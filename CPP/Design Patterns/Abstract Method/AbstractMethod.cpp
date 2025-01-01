#include <iostream>

// Abstract Base Class for ProductA family
class AbstractProductA
{
public:
    AbstractProductA() { std::cout << "AbstractProductA" << std::endl; }
    virtual ~AbstractProductA() {}   // Virtual destructor to ensure proper cleanup of derived classes
    virtual void checkProduct() = 0; // Pure virtual function (forces derived classes to implement this)
};

// Abstract Base Class for ProductB family
class AbstractProductB
{
public:
    AbstractProductB() { std::cout << "AbstractProductB" << std::endl; }
    virtual ~AbstractProductB() {}   // Virtual destructor for proper polymorphic cleanup
    virtual void checkProduct() = 0; // Pure virtual function
};

// Concrete ProductA1 (inherits from AbstractProductA)
class ProductA1 : public AbstractProductA
{
public:
    ProductA1() { std::cout << "ProductA1" << std::endl; }
    ~ProductA1() {}

    // Override checkProduct to provide specific implementation
    void checkProduct() override
    {
        std::cout << "ProductA1 has been created" << std::endl;
    }
};

// Concrete ProductA2 (inherits from AbstractProductA)
class ProductA2 : public AbstractProductA
{
public:
    ProductA2() { std::cout << "ProductA2" << std::endl; }
    ~ProductA2() {}

    // Override checkProduct
    void checkProduct() override
    {
        std::cout << "ProductA2 has been created" << std::endl;
    }
};

// Concrete ProductB1 (inherits from AbstractProductB)
class ProductB1 : public AbstractProductB
{
public:
    ProductB1() { std::cout << "ProductB1" << std::endl; }
    ~ProductB1() {}

    // Override checkProduct
    void checkProduct() override
    {
        std::cout << "ProductB1 has been created" << std::endl;
    }
};

// Concrete ProductB2 (inherits from AbstractProductB)
class ProductB2 : public AbstractProductB
{
public:
    ProductB2() { std::cout << "ProductB2" << std::endl; }
    ~ProductB2() {}

    // Override checkProduct
    void checkProduct() override
    {
        std::cout << "ProductB2 has been created" << std::endl;
    }
};

// Abstract Factory Class (declares factory methods)
class AbstractFactory
{
public:
    AbstractFactory() { std::cout << "AbstractFactory" << std::endl; }
    virtual ~AbstractFactory() {} // Virtual destructor for cleanup of derived factories

    // Pure virtual methods for creating products
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
};

// Concrete Factory 1 - Creates ProductA1 and ProductB1
class ConcreteFactory1 : public AbstractFactory
{
public:
    ConcreteFactory1() { std::cout << "ConcreteFactory1" << std::endl; }
    ~ConcreteFactory1() {}

    // Create ProductA1 and return as AbstractProductA*
    AbstractProductA *createProductA() override { return new ProductA1; }

    // Create ProductB1 and return as AbstractProductB*
    AbstractProductB *createProductB() override { return new ProductB1; }
};

// Concrete Factory 2 - Creates ProductA2 and ProductB2
class ConcreteFactory2 : public AbstractFactory
{
public:
    ConcreteFactory2() { std::cout << "ConcreteFactory2" << std::endl; }
    ~ConcreteFactory2() {}

    // Create ProductA2 and return as AbstractProductA*
    AbstractProductA *createProductA() override { return new ProductA2; }

    // Create ProductB2 and return as AbstractProductB*
    AbstractProductB *createProductB() override { return new ProductB2; }
};


// Main function to demonstrate Factory Pattern
int main(int argc, char *argv[])
{
    // Create Factory 1 and produce ProductA1 and ProductB1
    AbstractFactory *cf1 = new ConcreteFactory1();
    AbstractProductA *productA1 = cf1->createProductA();
    productA1->checkProduct();
    AbstractProductB *productB1 = cf1->createProductB();
    productB1->checkProduct();

    // Create Factory 2 and produce ProductA2 and ProductB2
    AbstractFactory *cf2 = new ConcreteFactory2();
    AbstractProductA *productA2 = cf2->createProductA();
    productA2->checkProduct();

    // **Fix Issue:** cf1->createProductB() is mistakenly called instead of cf2->createProductB()
    AbstractProductB *productB2 = cf2->createProductB(); // FIX: Use cf2 to create ProductB2
    productB2->checkProduct();

    // Clean up dynamically allocated memory (avoid memory leaks)
    delete cf1;
    delete cf2;
    delete productA1;
    delete productB1;
    delete productA2;
    delete productB2;

    return 0;
}
