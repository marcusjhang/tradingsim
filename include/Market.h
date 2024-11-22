#ifndef MARKET_H
#define MARKET_H

#include <unordered_map>
#include <string>
#include "Stock.h"

class Market {
private:
    std::unordered_map<std::string, Stock> stocks;

public:
    Market();
    void addStock(const std::string& ticker, double price);
    void simulateDay();
    void displayStocks() const;
    const std::unordered_map<std::string, Stock>& getStocks() const;
};

#endif