#ifndef WALLET_H
#define WALLET_H

#include "Users.h"
#include <vector>
// #include "StockList.h"

class Wallet : public Users{
    private:
    protected:
        double balance;
        string currencyName;
        vector<string> stocks;
        vector<double> stockvalue;
    public:
        Wallet();
        int promptChoice();
        void addFunds();
        double convertCurrency(int currencyCode);
        void withdrawFunds(double balance);
        void setBalance(double balance);
        void setStock (string stock,double value);
        double getBalance();
        void getPortfolio();
        int getStockQuantity(string stock);
        void removeStockQuantity(string stock,int quantity);
};

#endif