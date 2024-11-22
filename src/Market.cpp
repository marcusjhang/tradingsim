#include "../include/Market.h"
#include <iostream>

Market::Market() {}

void Market::addStock(const std::string& ticker, double price) {
    stocks[ticker] = Stock(ticker, price);
}

void Market::simulateDay() {
    for (auto& [ticker, stock] : stocks) {
        stock.fluctuatePrice();
    }
    std::cout << "\nMarket prices updated for the day.\n";
}

void Market::displayStocks() const {
    std::cout << "\n--- Stock Prices ---\n";
    for (const auto& [ticker, stock] : stocks) {
        stock.display();
    }
}

const std::unordered_map<std::string, Stock>& Market::getStocks() const {
    return stocks;
}