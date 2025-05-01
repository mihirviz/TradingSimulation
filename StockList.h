#ifndef STOCKLIST_H
#define STOCKLIST_H

#include "Wallet.h"
#include <string>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
using namespace std;

class StockList : public Users{
    private:
    protected:
        struct stock
        {
            string stockName;
            double stockPrice;
        };
        stock stocks[8];
        string selectedStock;
        double selectedStockPrice;
        
    public:
        StockList();
        void viewAndSetStockList();
        double randomNumber(int min,int max);
        bool updatePrice();
        bool selectStock();
        string getSelectedStockName();
        double getSelectedStockPrice();
};

#endif