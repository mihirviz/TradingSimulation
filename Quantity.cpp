#include "Quantity.h"
#include "StockList.h" // Include StockList to access stock data
#include "Wallet.h"
#include <iostream>

Quantity::Quantity() {
    this->minQuantity = 1;
    this->maxQuantity = 10;
    this->currentQuantity = 0; // Initialize currentQuantity
}

void Quantity::buyStock(StockList& stockList, Wallet& wlt) {
    // Retrieve selected stock information from StockList
    string selectedStockName = stockList.getSelectedStockName();
    double selectedStockPrice = stockList.getSelectedStockPrice();

    double amtOfMoneyToBuyStock;

    std::cout << "Enter the amount of money you want to use to buy the stock: ";
    std::cin >> amtOfMoneyToBuyStock;
    
    // cout<<wlt.getBalance()<<endl;
    while(amtOfMoneyToBuyStock > wlt.getBalance()){
        std::cout << "Total funds available " << wlt.getBalance() << ". Not enough funds in the wallet(To cancel transaction enter -1):- ";
        std::cin >> amtOfMoneyToBuyStock;

        if(amtOfMoneyToBuyStock == -1){
            return;
        }
    }


    cout<<selectedStockPrice<<endl;
    cout<<amtOfMoneyToBuyStock<<endl;
    currentQuantity = amtOfMoneyToBuyStock / selectedStockPrice;

    wlt.setStock(selectedStockName,amtOfMoneyToBuyStock);
    wlt.setBalance(wlt.getBalance() - amtOfMoneyToBuyStock);
    cout<<"Enter leverage:- "<<endl;
    cin>>this->leverage;

    while(!(leverage >= minQuantity && leverage <= maxQuantity)){
        cout<<"Please enter leverage between 1 and 10:- "<<endl;
        cin>>this->leverage;
    }

    std::cout << "You can buy " << currentQuantity << " shares of " << selectedStockName << " at " << selectedStockPrice << " each.\n";
    // Additional logic for updating quantities, etc., can be added here
}

void Quantity::sellStock(string stock, Wallet& wlt,int sellQuantity) {
    int value = wlt.getStockQuantity(stock);

    if(value == -1){
        cout<<"No such stock found."<<endl;
        return;
    }
    else if(value < sellQuantity){
        cout<<"You don't have the quantity of stocks to sell."<<endl;
        return;
    }
    else{
        wlt.removeStockQuantity(stock,sellQuantity);
        return;
    }
}

// Getters
int Quantity::getId() const { return id; }
int Quantity::getMaxQuantity() const { return maxQuantity; }
int Quantity::getMinQuantity() const { return minQuantity; }
int Quantity::getCurrentQuantity() const { return currentQuantity; }
double Quantity::getLeverage() const { return leverage; }