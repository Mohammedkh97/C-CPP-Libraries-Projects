#ifndef STOCKMANAGER_HPP
#define STOCKMANAGER_HPP

#include "Subject.hpp"

class StockManager : public Subject
{
private:
    std::string stockName;
    double stockPrice;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    StockManager(const std::string &name, double price)
        : stockName(name), stockPrice(price) {}

    void registerObserver(std::shared_ptr<Observer> observer) override;
    void removeObserver(std::shared_ptr<Observer> observer) override;
    void notifyObservers() override;

    void setStockPrice(double price);
    const std::string &getStockName() const { return stockName; }
    double getStockPrice() const { return stockPrice; }
};

#endif // STOCKMANAGER_HPP
