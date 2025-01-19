#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const std::string &stockName, double price) = 0;
};

// Observer.hpp (Abstract Observer)

#endif // OBSERVER_HPP
