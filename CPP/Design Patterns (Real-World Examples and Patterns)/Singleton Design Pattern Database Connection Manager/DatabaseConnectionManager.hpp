#ifndef DATABASE_CONNECTION_MANAGER_HPP
#define DATABASE_CONNECTION_MANAGER_HPP

#include <string>
#include <mutex>
#include <memory>
#include <iostream>

class DatabaseConnection
{
public:
    void connect()
    {
        // Simulate a database connection
        std::cout << "Database connected!" << std::endl;
    }

    void disconnect()
    {
        // Simulate closing the database connection
        std::cout << "Database disconnected!" << std::endl;
    }

    void executeQuery(const std::string &query)
    {
        // Simulate executing a query
        std::cout << "Executing query: " << query << std::endl;
    }
};

class DatabaseConnectionManager
{
private:
    static std::unique_ptr<DatabaseConnectionManager> instance; // Singleton instance
    static std::mutex mutex_;                                   // Mutex for thread safety
    DatabaseConnection connection;                              // Database connection object

    // Private constructor to prevent direct instantiation
    DatabaseConnectionManager() = default;

public:
    // Delete copy constructor and assignment operator
    DatabaseConnectionManager(const DatabaseConnectionManager &) = delete;
    DatabaseConnectionManager &operator=(const DatabaseConnectionManager &) = delete;

    // Static method to access the single instance
    static DatabaseConnectionManager &getInstance();

    // Methods to manage the database connection
    void connect();
    void disconnect();
    void executeQuery(const std::string &query);

    // Destructor
    ~DatabaseConnectionManager()
    {
        disconnect();
    }
};

#endif // DATABASE_CONNECTION_MANAGER_HPP
