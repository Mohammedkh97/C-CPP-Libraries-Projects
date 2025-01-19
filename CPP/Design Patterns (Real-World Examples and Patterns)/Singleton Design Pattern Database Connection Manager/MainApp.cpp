#include <iostream>
#include "DatabaseConnectionManager.hpp"

int main()
{
    // Access the Singleton instance
    DatabaseConnectionManager &dbManager = DatabaseConnectionManager::getInstance();

    // Connect to the database
    dbManager.connect();

    // Execute a query
    dbManager.executeQuery("SELECT * FROM users");

    // Disconnect from the database
    dbManager.disconnect();

    return 0;
}

/*
Explanation
Header File (.hpp):

DatabaseConnectionManager class contains:
A private static std::unique_ptr<DatabaseConnectionManager> instance to hold the singleton instance.
A std::mutex to ensure thread safety during initialization.
A private constructor to prevent direct instantiation.
Static getInstance() method for accessing the singleton instance.
Methods to connect, disconnect, and execute queries.
A destructor to ensure proper cleanup when the singleton is destroyed.
Source File (.cpp):

The static instance is initialized as nullptr, and the getInstance() method is implemented with lazy initialization and thread-safety using std::mutex.
The connection methods (connect(), disconnect(), executeQuery()) are implemented to simulate database operations.
Main File (main.cpp):

The main() function demonstrates how to access the DatabaseConnectionManager singleton, establish a connection, execute a query, and disconnect from the database.
Key Features of Modern C++ Design
Smart Pointers: The std::unique_ptr is used for automatic memory management, ensuring no memory leaks.
Thread Safety: Thread safety is achieved by using std::mutex to lock the instance initialization process, preventing race conditions.
Encapsulation and Single Responsibility Principle (SRP): The database connection logic is encapsulated in the DatabaseConnection class, and the connection manager handles only the instantiation of the connection.
Resource Management: The destructor ensures that the database connection is closed when the instance is destroyed.

*/