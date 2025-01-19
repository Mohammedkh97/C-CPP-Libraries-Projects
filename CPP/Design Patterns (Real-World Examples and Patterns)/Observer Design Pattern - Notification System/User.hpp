
#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include "Observer.hpp"

class User : public Observer
{
private:
    std::string name;

public:
    User(const std::string &userName) : name(userName) {}

    void update(const std::string &stockName, double price) override;
};

// User.hpp(Concrete Observer)

#endif // USER_HPP
