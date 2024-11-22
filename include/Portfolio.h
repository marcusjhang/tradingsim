#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <unordered_map>
#include <string>
#include "Stock.h"

class Portfolio {
private:
    std::unordered_map<std::string, int> holdings;
    double cashBalance;

public:
    Portfolio(double initialCash);
    void buyStock(const std::string& ticker, int quantity, double price);
    void sellStock(const std::string& ticker, int quantity, double price);
    void displayPortfolio(const std::unordered_map<std::string, Stock>& market) const;
};

#endif