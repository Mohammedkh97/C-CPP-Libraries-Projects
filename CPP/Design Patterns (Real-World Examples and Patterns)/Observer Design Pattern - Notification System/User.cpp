#include "User.hpp"
#include <iostream>

void User::update(const std::string &stockName, double price)
{
    std::cout << "User " << name << " notified: "
              << stockName << " price changed to " << price << std::endl;
}
