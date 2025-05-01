#include "Wallet.h"

Wallet::Wallet() {
    balance = 0;
    currencyName = "";

    if(this->choice == 1){
        promptChoice();
    }
    else{

    }
}

int Wallet::promptChoice() {
    int choice;

    cout<<"Enter 1 to add funds:- \n";
    cout<<"Enter 2 to withdraw funds:- \n";
    cout<<"Enter 3 to switch to portfolio:- \n";
    cout<<"Enter 4 to switch to stocklist:- \n";
    cin>>choice;

    while (true)
    {
        if(choice == 1){
            addFunds();
        }
        else if(choice == 2){
            withdrawFunds(this->balance);
        }
        else if(choice == 3){
            this->choice = 2;
            return this->choice;
        }
        else if(choice == 4){
            return 3;
        }
        else if(choice == 5){
            return 4;
        }
        else{
            cout<<"Please enter a valid choice. Try Again... ";
            cin>>choice;
        }
        cout<<"Enter 1 to add funds:- \n";
        cout<<"Enter 2 to withdraw funds:- \n";
        cout<<"Enter 3 to switch to portfolio:- \n";
        cout<<"Enter 4 to switch to stocklist:- \n";
        cout<<"Enter 5 to sell to stock:- \n";
        cin>>choice;
    }
    
}

void Wallet::addFunds() {
    int currencyCode = 0;
    cout<<"What currency from the following are you choosing:- "<<endl;
    cout<<"1. For american dollar enter USD"<<endl;
    cout<<"2. For United Kingdom Pound enter GBP"<<endl;
    cout<<"3. For Japanese Yen enter JPY"<<endl;
    cout<<"4. For European Euro enter EUR"<<endl;
    cout<<"5. For Australian Dollar enter AUD"<<endl;
    cin>>currencyName;

    cout<<currencyName<<endl;

    while (true)
    {
        if(currencyName == "USD" || currencyName == "GBP" || currencyName == "JPY" || currencyName == "EUR" || currencyName == "AUD"){
            cout<<"Enter the amount of money you want to enter."<<endl;
            cin>>this->balance;

            if(currencyName == "USD"){
                currencyCode = 1;
            }
            else if(currencyName == "GBP"){
                currencyCode = 2;
            }
            else if (currencyName == "JPY")
            {
                currencyCode = 3;
            }
            else if (currencyName == "EUR")
            {
                currencyCode = 4;
            }
            else if (currencyName == "AUD"){
                currencyCode = 5;
            }
            else{
                currencyCode = -1;
            }

            break;
        }
        else{
            cout<<"Please enter currency from the above list.";
            cin>>currencyName;
        }
    }

    this->balance = convertCurrency(currencyCode);
}

double Wallet::convertCurrency(int currencyCode) {
    switch (currencyCode)
    {
    case 1:
        this->balance = this->balance;
        break;
    case 2:
        this->balance = this->balance*1.31;
        break;
    case 3:
        this->balance = this->balance*0.0067;
        break;
    case 4:
        this->balance = this->balance*1.09;
        break;
    case 5:
        this->balance = this->balance*0.68;
        break;
    default:
        break;
    }

    cout<<"Updated balance:- "<<this->balance<<" USD"<<endl;
    return this->balance;
}

void Wallet::withdrawFunds(double balance) {
    double withdrawAmount;

    cout<<"Total funds:- "<<this->balance<<"USD"<<endl;
    cout<<"Enter the amount of USD you want to withdraw:- ";
    cin>>withdrawAmount;

    while (true)
    {
        if(withdrawAmount >= 0){
            if(withdrawAmount <= this->balance){
                this->balance -= withdrawAmount;
                cout<<"Updated balance:- "<<this->balance<<" USD"<<endl;
                break;
            }
            else{
                cout<<"Insufficient funds to Withdraw. Try again:- ";
                cin>>withdrawAmount;
            }
        }
        else{
            cout<<"Withdraw amount should be greater than 0. Try again:- ";
            cin>>withdrawAmount;
        }
    }
    
}

double Wallet::getBalance() {
    return this->balance;
}

void Wallet::setBalance(double balance) {
    this->balance = balance;
}

void Wallet::setStock(string stock, double value){
    
    for(int i=0;i<this->stocks.size();i++){
        if(stock == this->stocks[i]){
            this->stockvalue[i] += value;
            return;
        }
    }
    this->stocks.push_back(stock);
    this->stockvalue.push_back(value);
}

void Wallet::getPortfolio() {
    for(int i = 0;i<this->stocks.size();i++){
        cout<<this->stocks[i]<<": "<<this->stockvalue[i]<<endl;
    }
}

int Wallet::getStockQuantity(string stock) {
    for(int i = 0; i< this->stocks.size();i++){
        if(this->stocks[i] == stock){
            return this->stockvalue[i];
        }
    }

    return -1;
}

void Wallet::removeStockQuantity(string stock,int quantity) {
    for(int i = 0; i< this->stocks.size();i++){
        if(this->stocks[i] == stock){
            this->stockvalue[i] -= quantity;
        }
    }
}
