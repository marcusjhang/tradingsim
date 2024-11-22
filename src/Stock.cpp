#include "../include/Stock.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Stock::Stock(const std::string& t, double p) : ticker(t), price(p) {
    priceHistory.push_back(p);
}

Stock::Stock() : ticker("UNKNOWN"), price(0.0) {
    priceHistory.push_back(price);
}

void Stock::fluctuatePrice() {
    double change = (rand() % 21 - 10) / 100.0; // Random change between -10% to +10%
    price += price * change;
    if (price < 1.0) price = 1.0;               // Minimum price
    priceHistory.push_back(price);
}

void Stock::display() const {
    std::cout << ticker << ": $" << std::fixed << std::setprecision(2) << price << std::endl;
}