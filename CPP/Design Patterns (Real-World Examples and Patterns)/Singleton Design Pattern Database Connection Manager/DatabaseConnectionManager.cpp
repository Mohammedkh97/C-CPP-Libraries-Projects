#include "DatabaseConnectionManager.hpp"

// Initialize the static instance pointer to nullptr
std::unique_ptr<DatabaseConnectionManager> DatabaseConnectionManager::instance = nullptr;
std::mutex DatabaseConnectionManager::mutex_; // Mutex initialization

// Static method to get the singleton instance
DatabaseConnectionManager &DatabaseConnectionManager::getInstance()
{
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mutex_); // Lock for thread safety
        if (instance == nullptr)
        {
            instance.reset(new DatabaseConnectionManager()); // Lazy initialization
        }
    }
    return *instance;
}

// Connect to the database
void DatabaseConnectionManager::connect()
{
    connection.connect();
}

// Disconnect from the database
void DatabaseConnectionManager::disconnect()
{
    connection.disconnect();
}

// Execute a query on the database
void DatabaseConnectionManager::executeQuery(const std::string &query)
{
    connection.executeQuery(query);
}
