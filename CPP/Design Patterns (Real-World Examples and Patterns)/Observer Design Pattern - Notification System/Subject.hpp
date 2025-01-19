#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>
#include <memory>
#include "Observer.hpp"

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif // SUBJECT_HPP
