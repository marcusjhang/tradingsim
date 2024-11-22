#include "../include/Portfolio.h"
#include <iostream>
#include <iomanip>

Portfolio::Portfolio(double initialCash) : cashBalance(initialCash) {}

void Portfolio::buyStock(const std::string& ticker, int quantity, double price) {
    double totalCost = quantity * price;
    if (totalCost > cashBalance) {
        std::cout << "Not enough cash to complete the transaction.\n";
    } else {
        cashBalance -= totalCost;
        holdings[ticker] += quantity;
        std::cout << "Bought " << quantity << " shares of " << ticker
                  << " for $" << totalCost << ".\n";
    }
}

void Portfolio::sellStock(const std::string& ticker, int quantity, double price) {
    if (holdings[ticker] < quantity) {
        std::cout << "Not enough shares to sell.\n";
    } else {
        double totalEarnings = quantity * price;
        cashBalance += totalEarnings;
        holdings[ticker] -= quantity;
        if (holdings[ticker] == 0) {
            holdings.erase(ticker);
        }
        std::cout << "Sold " << quantity << " shares of " << ticker
                  << " for $" << totalEarnings << ".\n";
    }
}

void Portfolio::displayPortfolio(const std::unordered_map<std::string, Stock>& market) const {
    std::cout << "\n--- Portfolio ---\n";
    std::cout << "Cash Balance: $" << std::fixed << std::setprecision(2) << cashBalance << "\n";

    double totalValue = cashBalance;
    for (const auto& [ticker, quantity] : holdings) {
        double stockValue = quantity * market.at(ticker).price;
        totalValue += stockValue;
        std::cout << ticker << ": " << quantity << " shares ($" << stockValue << ")\n";
    }

    std::cout << "Total Portfolio Value: $" << totalValue << "\n";
}
