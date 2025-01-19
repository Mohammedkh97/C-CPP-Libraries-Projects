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