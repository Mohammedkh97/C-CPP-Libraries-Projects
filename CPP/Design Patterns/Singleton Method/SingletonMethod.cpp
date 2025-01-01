#include <iostream>
#include <string>

// Singleton class definition
class Singleton
{
public:
    // Delete copy constructor to prevent copying of Singleton instance
    Singleton(const Singleton &) = delete;

    // Delete assignment operator to avoid duplication through assignment
    Singleton &operator=(const Singleton &) = delete;

    // Static method to get the Singleton instance
    static Singleton *instance()
    {
        // Check if the instance already exists (Lazy Initialization)
        if (!instance_)
        {
            instance_ = new Singleton(); // Create the instance if not created yet
        }
        return instance_; // Return the existing instance
    }

    // Method to demonstrate Singleton functionality
    void checkSingleton() { std::cout << "Singleton has been created" << std::endl; }

private:
    // Private constructor to prevent instantiation from outside the class
    Singleton() { std::cout << "Singleton" << std::endl; }

    // Static pointer to hold the Singleton instance (initialized to nullptr)
    static Singleton *instance_;
};

// Initialize the static instance pointer to nullptr (no instance initially)
Singleton *Singleton::instance_ = nullptr;

// Main function demonstrating Singleton usage
int main(int argc, char *argv[])
{
    // Get the Singleton instance (first call creates the instance)
    Singleton *singleton = Singleton::instance();

    // Call method to verify instance creation
    singleton->checkSingleton();

    // Additional calls to instance() will return the same instance
    Singleton *singleton2 = Singleton::instance();
    singleton2->checkSingleton();

    // The output will show that the Singleton instance is reused
}
