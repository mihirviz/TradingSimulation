#ifndef MARKETORDER_H
#define MARKETORDER_H

#include "Quantity.h"  
#include <string>      

class MarketOrder : public Quantity {
private:
    int id;
    std::string nameOfStock;
    int quantity;

    // order status to show if pending, executed or cancelled
    std::string orderStatus;  

public:
    // constructor
    MarketOrder(int id, std::string nameOfStock, int quantity, string orderStatus);

    // function to place the order and check the stock price for execution
    void openPosition(double stockPrice, double targetPrice);

    // function to cancel an order if it hasn't been executed
    void cancelOrder();

    // function to check order status
    std::string checkOrderStatus() const;

    // getters and setters
    int getId() const;
    std::string getNameOfStock() const;
    int getQuantity() const;
    std::string getOrderStatus() const;

    void setOrderStatus(std::string status);

    // New function to print all details of the order
    void printDetails() const;
};

#endif
