// #include <iostream>

// // Strategy interface: Defines a common interface for all strategies
// class Strategy
// {
// public:
//     virtual ~Strategy() {}                       // Virtual destructor for proper cleanup
//     virtual void algorithmInterface() const = 0; // Pure virtual method for strategy's implementation
// };

// // ConcreteStrategyA: A specific implementation of the Strategy interface
// class ConcreteStrategyA : public Strategy
// {
// public:
//     ~ConcreteStrategyA() override {} // Destructor (virtual inheritance cleanup)

//     void algorithmInterface() const override
//     {
//         std::cout << "Concrete Strategy A" << std::endl; // Concrete implementation of the algorithm
//     }
// };

// // ConcreteStrategyB: Another specific implementation of the Strategy interface
// class ConcreteStrategyB : public Strategy
// {
// public:
//     ~ConcreteStrategyB() override {} // Destructor (virtual inheritance cleanup)

//     void algorithmInterface() const override
//     {
//         std::cout << "Concrete Strategy B" << std::endl; // Concrete implementation of the algorithm
//     }
// };

// // ConcreteStrategyC: Another specific implementation of the Strategy interface
// class ConcreteStrategyC : public Strategy
// {
// public:
//     ~ConcreteStrategyC() override {} // Destructor (virtual inheritance cleanup)

//     void algorithmInterface() const override
//     {
//         std::cout << "Concrete Strategy C" << std::endl; // Concrete implementation of the algorithm
//     }
// };

// // Context: Maintains a reference to a Strategy and invokes its method
// class Context
// {
// public:
//     // Constructor initializes with a specific strategy
//     Context(Strategy *s) : strategy(s) {}

//     // Destructor to ensure the strategy is deleted to avoid memory leaks
//     ~Context()
//     {
//         delete strategy; // Clean up the strategy object to avoid memory leak
//     }

//     // Method to execute the current strategy
//     void contextInterface() const
//     {
//         strategy->algorithmInterface(); // Delegates the call to the strategy's method
//     }

// private:
//     Strategy *strategy; // A pointer to the current strategy (strategy pattern)
// };

// int main()
// {
//     // Create a Context with ConcreteStrategyA and execute its method
//     Context context(new ConcreteStrategyA()); // Pass the strategy (A) to the context
//     context.contextInterface();               // Output: "Concrete Strategy A"

//     // You can change the strategy dynamically at runtime if needed:
//     //    delete &context;                            // Clean up the old context

//     /*
//     This is incorrect because context is a stack-allocated object, and you cannot delete
//     a stack object in C++. delete is only used for heap-allocated objects created with new.

//     Instead, you should directly create a new Context object with a different strategy without
//     needing to delete the previous one. The Context destructor will automatically clean up
//     the old strategy (since delete strategy; is used inside the Context destructor).
//     */
//     context = Context(new ConcreteStrategyB()); // Switch to strategy B
//     context.contextInterface();                 // Output: "Concrete Strategy B"


//     return 0;
// }



#include <iostream>

// Strategy interface: Defines a common interface for all strategies
class Strategy
{
public:
    virtual ~Strategy() {}                       // Virtual destructor for proper cleanup
    virtual void algorithmInterface() const = 0; // Pure virtual method for strategy's implementation
};

// ConcreteStrategyA: A specific implementation of the Strategy interface
class ConcreteStrategyA : public Strategy
{
public:
    ~ConcreteStrategyA() override {} // Destructor (virtual inheritance cleanup)

    void algorithmInterface() const override
    {
        std::cout << "Concrete Strategy A" << std::endl; // Concrete implementation of the algorithm
    }
};

// ConcreteStrategyB: Another specific implementation of the Strategy interface
class ConcreteStrategyB : public Strategy
{
public:
    ~ConcreteStrategyB() override {} // Destructor (virtual inheritance cleanup)

    void algorithmInterface() const override
    {
        std::cout << "Concrete Strategy B" << std::endl; // Concrete implementation of the algorithm
    }
};

// ConcreteStrategyC: Another specific implementation of the Strategy interface
class ConcreteStrategyC : public Strategy
{
public:
    ~ConcreteStrategyC() override {} // Destructor (virtual inheritance cleanup)

    void algorithmInterface() const override
    {
        std::cout << "Concrete Strategy C" << std::endl; // Concrete implementation of the algorithm
    }
};

// Context: Maintains a reference to a Strategy and invokes its method
class Context
{
public:
    // Constructor initializes with a specific strategy
    Context(Strategy *s) : strategy(s) {}

    // Destructor to ensure the strategy is deleted to avoid memory leaks
    ~Context()
    {
        delete strategy; // Clean up the strategy object to avoid memory leak
    }

    // Method to execute the current strategy
    void contextInterface() const
    {
        strategy->algorithmInterface(); // Delegates the call to the strategy's method
    }

    // Method to change the strategy dynamically
    void setStrategy(Strategy *newStrategy)
    {
        delete strategy;        // Clean up the old strategy
        strategy = newStrategy; // Assign the new strategy
    }
    
private:
    Strategy *strategy; // A pointer to the current strategy (strategy pattern)
};

int main()
{
    // Create a Context with ConcreteStrategyA and execute its method
    Context context(new ConcreteStrategyA()); // Pass the strategy (A) to the context
    context.contextInterface();               // Output: "Concrete Strategy A"

    // Change the strategy to ConcreteStrategyB and execute its method
    context.setStrategy(new ConcreteStrategyB()); // Switch to strategy B
    context.contextInterface();                   // Output: "Concrete Strategy B"

    // Change the strategy to ConcreteStrategyC and execute its method
    context.setStrategy(new ConcreteStrategyC()); // Switch to strategy C
    context.contextInterface();                   // Output: "Concrete Strategy C"

    return 0;
}
