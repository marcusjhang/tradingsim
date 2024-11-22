#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

class Stock {
public:
    std::string ticker;               // Stock symbol (e.g., AAPL, TSLA)
    double price;                     // Current stock price
    std::vector<double> priceHistory; // Historical prices
    Stock(); // Default constructor
    Stock(const std::string& t, double p);
    void fluctuatePrice();            // Simulate price fluctuation
    void display() const;             // Display stock details
};

#endif