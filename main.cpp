#include "account.h"
#include "Users.h"
#include "Wallet.h"
#include "StockList.h"
#include "Quantity.h"

int main(){

    int choice;
    bool login;

    cout<<"Enter 1 for a new account else enter 2:- ";
    cin>>choice;

    while(true){
        if(choice == 1){
            Account acc;

            acc.getUserDetails();

            if(acc.isAccountCreated()){
                choice = 2;
            }
        }
        else if(choice == 2){
            Users user;

            user.getLoginDetails();

            login = user.getIsLogin();
            if(login){
                int choice = user.promptChoice();
                Wallet wlt;
                StockList stk;
                Quantity qun;

                while (true)
                {
                    if(choice == 1){
                        choice = wlt.promptChoice();
                    }
                    else if(choice == 2){
                        wlt.getPortfolio();
                    }
                    else if(choice == 3){
                        stk.viewAndSetStockList();

                        qun.buyStock(stk,wlt);
                    }
                    else if(choice == 4){
                        string sellOwnedStock;
                        int sellQuantity;
                        cout<<"Enter the name of the stock you want to sell:- ";
                        cin>>sellOwnedStock;
                        cout<<"Enter the quantity of stock you want to sell:- ";
                        cin>>sellQuantity;

                        qun.sellStock(sellOwnedStock,wlt,sellQuantity);
                    }
                    else if(choice == -1){
                        break;
                    }
                    choice = 0;
                    choice = user.promptChoice();
                }
            }
            break;
        }
        else{
            cout<<"Enter a valid choice:- ";
            cin>>choice;
        }
    }

    return 0;
}