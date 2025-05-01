#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "Quantity.h"

// Base class for LimitOrder
class LimitOrder : public Quantity {
public:
    virtual void execute() = 0;  // Virtual function to be implemented by subclasses
    virtual ~LimitOrder() {}  // Virtual destructor
};

// Subclass for Strategy
class Strategy : public LimitOrder {
public:
    void execute() override;

private:
    void applyEMAStrategy();
    void applySupertrendStrategy();
    void generateAutoOrders(const std::string& strategy);
    double calculateEMA(const std::vector<double>& prices, int period);
    bool checkSupertrend(const std::vector<double>& highs, const std::vector<double>& lows, const std::vector<double>& closes, int period);
};

// Subclass for SelectPrice
class SelectPrice : public LimitOrder {
public:
    void execute() override;

private:
    void placeOrderAtPrice(double price);
};

// Function to handle user interface
void userInterface();

#endif // LIMIT_ORDER_H
