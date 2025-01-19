# Singleton Design Pattern - Database Connection Manager

## Overview
This project demonstrates the **Singleton Design Pattern** in C++ by implementing a `DatabaseConnectionManager` class. The pattern ensures that there is only one instance of the `DatabaseConnectionManager` throughout the application. It provides a global point of access to manage a single database connection, ensuring thread safety and efficient resource usage.

## Features
- **Single Instance**: Guarantees that only one `DatabaseConnectionManager` instance exists.
- **Thread-Safe**: The Singleton instance creation is thread-safe using `std::mutex`.
- **Lazy Initialization**: The connection is only established when needed.
- **Resource Management**: The database connection is managed efficiently using RAII (Resource Acquisition Is Initialization).

## Structure

- `DatabaseConnectionManager.hpp`: The header file declaring the `DatabaseConnectionManager` class and related methods.
- `DatabaseConnectionManager.cpp`: The source file implementing the `DatabaseConnectionManager` methods.
- `main.cpp`: A sample usage of the `DatabaseConnectionManager` to demonstrate how to connect, query, and disconnect from a database.

## Installation

### Prerequisites
- C++17 or higher
- A C++ compiler (e.g., `g++`)

### Building the Project

1. Clone or download this repository.
2. Navigate to the project folder.
3. Use the following command to compile the project:

```bash
g++ -std=c++17 -o db_manager main.cpp DatabaseConnectionManager.cpp
```

4. Run the executable:

```bash
./db_manager
```

## Usage

The `DatabaseConnectionManager` class ensures a single point of access to the database connection. The following operations can be performed:

1. **Connect to Database**: `connect()`
2. **Disconnect from Database**: `disconnect()`
3. **Execute a Query**: `executeQuery(query)`

### Example Usage:

```cpp
#include <iostream>
#include "DatabaseConnectionManager.hpp"

int main() {
    // Access the Singleton instance
    DatabaseConnectionManager& dbManager = DatabaseConnectionManager::getInstance();

    // Connect to the database
    dbManager.connect();

    // Execute a query
    dbManager.executeQuery("SELECT * FROM users");

    // Disconnect from the database
    dbManager.disconnect();

    return 0;
}
```

## Design Patterns
This project demonstrates the **Singleton** design pattern, which:
- Ensures that only one instance of the class exists.
- Provides a global point of access to that instance.
- Controls access to resources (in this case, the database connection).

## Benefits of Singleton:
- **Resource Efficiency**: Only one instance of the database connection is created.
- **Thread Safety**: The use of `std::mutex` ensures that the instance creation is thread-safe.
- **Global Access**: The instance is globally accessible via the `getInstance()` method.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```

### Key Sections:

- **Overview**: Briefly describes the purpose and benefits of using the Singleton pattern for managing a database connection.
- **Features**: Lists the key features of the project, such as thread safety and lazy initialization.
- **Structure**: Explains the organization of the code files.
- **Installation**: Describes how to compile and build the project.
- **Usage**: Shows how to use the `DatabaseConnectionManager` to connect, execute queries, and disconnect from the database.
- **Design Patterns**: Brief explanation of the Singleton pattern used.
- **License**: Add a section for the project license if applicable.

This `README.md` will help users understand the purpose and how to use your code effectively. Let me know if you need any additional modifications or improvements!