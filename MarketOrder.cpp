#include "MarketOrder.h"
#include <iostream> 

// this constructor initializes MarketOrder with stock details and the initial order status
MarketOrder::MarketOrder(int id, std::string nameOfStock, int quantity, std::string orderStatus)
    : Quantity(), nameOfStock(nameOfStock), orderStatus(orderStatus) {}

// open a position if the stock price reaches the target price
void MarketOrder::openPosition(double stockPrice, double targetPrice) {
    if (stockPrice <= targetPrice) {
        std::cout << "The stock price has reached the target. Order has been executed.\n";
        orderStatus = "Executed";
    } else {
        std::cout << "Stock price has not reached target. Order is still pending.\n";
        orderStatus = "Pending";
    }
}

//cancel an order if it hasn't been executed
void MarketOrder::cancelOrder() {
    if (orderStatus == "Pending") {
        std::cout << "The order has been cancelled.\n";
        orderStatus = "Cancelled";
    } else {
        std::cout << "Order cannot be cancelled now as it is has already executed.\n";
    }
}

// check the current order status
std::string MarketOrder::checkOrderStatus() const {
    return orderStatus;
}

// get the market order's ID, stock name, quantity and order status
// this allows access to the details of the order for further processing and output

int MarketOrder::getId() const {
    return id;
}

std::string MarketOrder::getNameOfStock() const {
    return nameOfStock;
}

int MarketOrder::getQuantity() const {
    return quantity;
}

std::string MarketOrder::getOrderStatus() const {
    return orderStatus;
}

// set the order status with basic validation
void MarketOrder::setOrderStatus(std::string status) {
    if (status == "Pending" || status == "Executed" || status == "Cancelled") {
        orderStatus = status;
    } else {
        std::cout << "Invalid order status. Status remains unchanged.\n";
    }
}

// Print all details of the order for easy debugging
// code to print the details i.e. if pending, executed, cancelle,d etc.