#include "StockList.h"

StockList::StockList() {}

void StockList::viewAndSetStockList() {
    stocks[0].stockName = "Apple";
    stocks[1].stockName = "Nvidia";
    stocks[2].stockName = "Alphabet";
    stocks[3].stockName = "Metta";
    stocks[4].stockName = "Amazon";
    stocks[5].stockName = "Microsoft";
    stocks[6].stockName = "Oracle";
    stocks[7].stockName = "Tesla";

    stocks[0].stockPrice = 336.98;
    stocks[1].stockPrice = 199.63;
    stocks[2].stockPrice = 243.64;
    stocks[3].stockPrice = 873.66;
    stocks[4].stockPrice = 279.62;
    stocks[5].stockPrice = 616.53;
    stocks[6].stockPrice = 175.77;
    stocks[7].stockPrice = 322.53;

    while (true)
    {
        this_thread::sleep_for(chrono::seconds(1));
        if(updatePrice()){
            break;
        }
    }
}

double StockList::randomNumber(int min, int max) {
    random_device randomNumber;
    mt19937 eng(randomNumber());

    uniform_real_distribution<> distr(min,max);

    return distr(eng);
}

bool StockList::updatePrice() {
    double update = randomNumber(-10,10);
    cout<<stocks[0].stockName<<":- \t"<<stocks[0].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[1].stockName<<":- \t"<<stocks[1].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[2].stockName<<":- \t"<<stocks[2].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[3].stockName<<":- \t"<<stocks[3].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[4].stockName<<":- \t"<<stocks[4].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[5].stockName<<":- \t"<<stocks[5].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[6].stockName<<":- \t"<<stocks[6].stockPrice + update<<"\n";
    update = randomNumber(-10,10);
    cout<<stocks[7].stockName<<":- \t"<<stocks[7].stockPrice + update<<"\n";
    cout<<"If you want to buy a stock enter stock name else enter r to see the updated stock value"<<endl;
    cin>>selectedStock;

    if(selectedStock.length() != 1){
        if(selectStock()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool StockList::selectStock() {
    while(true){
        selectedStockPrice = 0;
        while(true){
            for(int i = 0;i<8;i++){
                if(selectedStock == stocks[i].stockName){
                    selectedStockPrice = stocks[i].stockPrice;
                    break;
                }
            }
            if(selectedStockPrice != 0){
                break;
            }
            cout<<"No such stock found. Try again(To exit enter -1):- "<<endl;
            cin>>selectedStock;
            if(selectedStock == "-1"){
                break;
            }
        }

        if(selectedStockPrice){
            return true;
        }
    }
}

string StockList::getSelectedStockName() {
    return this->selectedStock;
}

double StockList::getSelectedStockPrice() {
    return this->selectedStockPrice;
}
