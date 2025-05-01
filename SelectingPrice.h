#ifndef SELECTINGPRICE.H
#define SELECTINGPRICE.H

#include <iostream>
#include <string>
// #include "Lim"

class SelectingPrice{
public:
    // Constructor
    SelectingPrice();

    // Destructor
    ~SelectingPrice();

    // Function to recommend a price based on some criteria
    double getRecommendedPrice(const std::string& stockSymbol, int quantity) const;
};

#endif