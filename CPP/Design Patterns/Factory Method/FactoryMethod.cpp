#include <iostream>
#include <memory>
#include <string>

// Abstract base class for all products
class Product
{
public:
    Product()
    {
        std::cout << "Product" << std::endl;
    }
    virtual ~Product() {} // Virtual destructor for proper cleanup of derived classes

    virtual void checkProduct() = 0; // Pure virtual function - must be implemented by derived classes
};

// Concrete product class A - inherits from Product
class ConcreateProductA : public Product
{
public:
    void checkProduct() override
    {
        std::cout << "Concrete Product A Checked" << std::endl;
    }
};

// Concrete product class B - inherits from Product
class ConcreateProductB : public Product
{
public:
    void checkProduct() override
    {
        std::cout << "Concrete Product B Checked" << std::endl;
    }
};

// Abstract creator class
class Creater
{
public:
    virtual Product *createProductA() = 0; // Factory method for creating ProductA
    virtual Product *createProductB() = 0; // Factory method for creating ProductB
};

// Concrete creator class that implements the factory methods
class ConcreateCreater : public Creater
{
public:
    Product *createProductA() override
    {
        return new ConcreateProductA();
    }

    Product *createProductB() override
    {
        return new ConcreateProductB();
    }
};

/******************************************************************************/
//  Example : Shape Factory

// Abstract base class
class Shape
{
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Shape() {}
};

// Concrete classes
class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};

// Factory class
class ShapeFactory
{
public:
    static std::unique_ptr<Shape> createShape(const std::string &shapeType)
    {
        if (shapeType == "Circle")
        {
            return std::make_unique<Circle>();
        }
        else if (shapeType == "Rectangle")
        {
            return std::make_unique<Rectangle>();
        }
        else if (shapeType == "Triangle")
        {
            return std::make_unique<Triangle>();
        }
        else
        {
            throw std::invalid_argument("Unknown shape type");
        }
    }
};

int main(int argc, char *argv[])
{
    Creater *creater = new ConcreateCreater; // Instantiate concrete creator

    // Create Product A using the factory method
    Product *productA = creater->createProductA();
    productA->checkProduct();
    delete productA; // Clean up allocated memory

    // Create Product B using the factory method
    Product *productB = creater->createProductB();
    productB->checkProduct();
    delete productB; // Clean up allocated memory

    delete creater; // Clean up the creator object

    /****************************************************/
    // Shape Factory Pattern:
    try
    {
        // Create shapes using the factory
        auto circle = ShapeFactory::createShape("Circle");
        auto rectangle = ShapeFactory::createShape("Rectangle");
        auto triangle = ShapeFactory::createShape("Triangle");

        // Draw shapes
        circle->draw();
        rectangle->draw();
        triangle->draw();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
