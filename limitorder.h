#ifndef LIMITORDER.H
#define LIMITORDER.H

#include <iostream>
#include <string>
#include "Quantity.h"
using namespace std;

class SelectingPrice;
class Strategy;

class LimitOrder : public Quantity{
public:
    // Enum for order types
    enum class OrderType { BUY, SELL };

    // Constructor
    LimitOrder(OrderType type, const std::string& stockSymbol, int quantity, double limitPrice);

    // Destructor
    ~LimitOrder();

    // Getters
    OrderType getType() const;
    std::string getStockSymbol() const;
    int getQuantity() const;
    double getLimitPrice() const;
    bool isExecuted() const;

    // Setters
    void setQuantity(int quantity);
    void setLimitPrice(double price);
    void executeOrder();

    // Helper function to print order details
    void printOrder() const;

    // Strategy related function
    void applyStrategy(Strategy* strategy);

    // Function to get price recommendation from SelectingPrice
    double recommendPrice(SelectingPrice* priceSelector) const;

private:
    OrderType type;
    std::string stockSymbol;
    int quantity;
    double limitPrice;
    bool executed;
};

#endif