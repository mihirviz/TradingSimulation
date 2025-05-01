#ifndef QUANTITY_H
#define QUANTITY_H

#include "StockList.h"
#include "Wallet.h"

class Quantity : public StockList{
private:
    int id;
    int maxQuantity;
    int minQuantity;
    double currentQuantity;
    double leverage;  // Store leverage here

public:
    // constructor
    Quantity();  // Added leverage as a default argument

    // function to calculate leverage based on funds and stock price

    void buyStock(StockList& stockList, Wallet& wlt);
    void sellStock(string stock, Wallet& wlt,int sellQuantity);

    // function to validate if the quantity purchased is between min and max thresholds
    // bool validateQuantity(int quantity);

    // setters and getters
    int getId() const;
    int getMaxQuantity() const;
    int getMinQuantity() const;
    int getCurrentQuantity() const;
    double getLeverage() const;
};

#endif
