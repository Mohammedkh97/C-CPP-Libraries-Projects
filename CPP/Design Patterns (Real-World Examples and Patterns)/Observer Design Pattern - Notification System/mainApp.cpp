#include <iostream>
#include <memory>
#include "StockManager.hpp"
#include "User.hpp"

int main()
{
    // Create a StockManager instance for the stock "XYZ"
    StockManager xyzStock("XYZ", 100.50);

    // Create users (observers)
    std::shared_ptr<User> user1 = std::make_shared<User>("Alice");
    std::shared_ptr<User> user2 = std::make_shared<User>("Bob");

    // Register users to receive updates
    xyzStock.registerObserver(user1);
    xyzStock.registerObserver(user2);

    // Simulate a change in stock price
    std::cout << "Changing stock price of XYZ...\n";
    xyzStock.setStockPrice(105.75); // Both users will be notified

    // Remove user1 from the observers list
    xyzStock.removeObserver(user1);

    // Simulate another change in stock price
    std::cout << "\nChanging stock price of XYZ again...\n";
    xyzStock.setStockPrice(110.00); // Only user2 will be notified

    return 0;
}
