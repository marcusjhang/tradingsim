#include "Market.h"
#include "Portfolio.h"
#include <iostream>

void displayMenu() {
    std::cout << "\n--- Trading Simulator ---\n";
    std::cout << "1. View Stock Prices\n";
    std::cout << "2. Buy Stock\n";
    std::cout << "3. Sell Stock\n";
    std::cout << "4. View Portfolio\n";
    std::cout << "5. Simulate Next Day\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Market market;
    market.addStock("AAPL", 150.0);
    market.addStock("TSLA", 700.0);
    market.addStock("GOOGL", 2800.0);
    market.addStock("AMZN", 3500.0);
    market.addStock("MSFT", 300.0);

    Portfolio portfolio(10000.0); // Initial cash balance

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            market.displayStocks();
        } else if (choice == 2) {
            std::string ticker;
            int quantity;
            std::cout << "Enter ticker: ";
            std::cin >> ticker;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            if (market.getStocks().find(ticker) != market.getStocks().end()) {
                portfolio.buyStock(ticker, quantity, market.getStocks().at(ticker).price);
            } else {
                std::cout << "Invalid ticker.\n";
            }
        } else if (choice == 3) {
            std::string ticker;
            int quantity;
            std::cout << "Enter ticker: ";
            std::cin >> ticker;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            if (market.getStocks().find(ticker) != market.getStocks().end()) {
                portfolio.sellStock(ticker, quantity, market.getStocks().at(ticker).price);
            } else {
                std::cout << "Invalid ticker.\n";
            }
        } else if (choice == 4) {
            portfolio.displayPortfolio(market.getStocks());
        } else if (choice == 5) {
            market.simulateDay();
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}