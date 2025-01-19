#include "StockManager.hpp"
#include <algorithm> // For std::remove

void StockManager::registerObserver(std::shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void StockManager::removeObserver(std::shared_ptr<Observer> observer)
{
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end());
}

void StockManager::notifyObservers()
{
    for (const auto &observer : observers)
    {
        observer->update(stockName, stockPrice);
    }
}

void StockManager::setStockPrice(double price)
{
    stockPrice = price;
    notifyObservers();
}
