/*
 Step-by-Step Breakdown of Factory Pattern:

1. Define the Product Interface
The interface that all products will implement.

class Product {
public:
    virtual void use() = 0; // Abstract method that concrete products will implement
    virtual ~Product() {}
};

2. Define Concrete Products:
These classes implement the Product interface and provide specific functionality.

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

3. Create the Factory Class / Define the Creator Interface:
The factory class has a method to create the objects.

class ProductFactory {
public:
    // Factory method to create products
    static Product* createProduct(const std::string& type) {
        if (type == "A") {
            return new ConcreteProductA();
        } else if (type == "B") {
            return new ConcreteProductB();
        } else {
            return nullptr;
        }
    }
};

*/
/*
🔹 Explanation of the Code:
Product Interface: Product defines the use() method, which must be implemented by concrete products.
Concrete Products: ConcreteProductA and ConcreteProductB implement the use() method with their specific behavior.
Factory Class: ProductFactory::createProduct() decides which concrete product to create based on the
input string.
Client: The client uses the factory's createProduct() method to get an instance of a Product,
without worrying about the concrete class that will be instantiated.
*/

#include <iostream>
#include <memory>
#include <string>

// Abstract product class / Abstract base class for all products
class AbstractProduct
{
public:
    virtual void use() = 0;
    virtual ~AbstractProduct() {}
};

// Concrete products
class ProductA : public AbstractProduct
{
public:
    void use() override
    {
        std::cout << "Using ProductA" << std::endl;
    }
};

class ProductB : public AbstractProduct
{
public:
    void use() override
    {
        std::cout << "Using ProductB" << std::endl;
    }
};

// Abstract factory
class AbstractFactory
{
public:
    virtual AbstractProduct *createProduct() = 0;
};

// Concrete factories
class FactoryA : public AbstractFactory
{
public:
    AbstractProduct *createProduct() override
    {
        return new ProductA();
    }
};

class FactoryB : public AbstractFactory
{
public:
    AbstractProduct *createProduct() override
    {
        return new ProductB();
    }
};

// Try Another Approach:
/*
class Creater
{
public:
    virtual AbstractProduct *createProductA() = 0; // Factory method for creating ProductA
    virtual AbstractProduct *createProductB() = 0; // Factory method for creating ProductB
};

// Concrete creator class that implements the factory methods
class ConcreateCreater : public Creater
{
public:
    AbstractProduct *createProductA() override
    {
        return new ProductA();
    }

    AbstractProduct *createProductB() override
    {
        return new ProductB();
    }
};


//Alternatively, if you want to use the factory (FactoryA or FactoryB) to produce the products,
//you need to call the createProduct() method of the factories:

// Concrete creator class implementing the factory methods

class ConcreateCreater : public Creater
{
private:
    FactoryA factoryA;
    FactoryB factoryB;

public:
    // Use pre-initialized factories to create products
    AbstractProduct *createProductA() override
    {
        return factoryA.createProduct();
    }

    AbstractProduct *createProductB() override
    {
        return factoryB.createProduct();
    }
};
*/

// Client code
int main()
{
    AbstractFactory *factoryA = new FactoryA();
    AbstractProduct *productA = factoryA->createProduct();
    productA->use();

    AbstractFactory *factoryB = new FactoryB();
    AbstractProduct *productB = factoryB->createProduct();
    productB->use();

    delete productA;
    delete factoryA;
    delete productB;
    delete factoryB;

    return 0;
}
