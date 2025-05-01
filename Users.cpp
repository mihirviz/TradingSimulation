#include "Users.h"

Users::Users() {
    email = "";
    password = "";
    storedPassword = "";
    loginAttempts = 0;
    isLogin = false;
}

int Users::promptChoice() {
    cout<<"Enter 1 to switch to wallet:- \n";
    cout<<"Enter 2 to switch to portfolio:- \n";
    cout<<"Enter 3 to switch to stocklist:- \n";
    cout<<"Enter 4 to switch to sellstock:- \n";
    cout<<"Enter 5 to exit:- \n";
    cin>>choice;

    while (true)
    {
        if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
            return choice;
        }
        else if(choice == 5){
            return -1;
        }
        else{
            cout<<"Please enter a valid choice. Try Again... ";
            cin>>choice;
        }
        cout<<"Enter 1 to switch to wallet:- \n";
        cout<<"Enter 2 to switch to portfolio:- \n";
        cout<<"Enter 3 to switch to stocklist:- \n";
        cin>>choice;
    }
}

bool Users::getIsLogin() {
    return this->isLogin;
}

void Users::getLoginDetails() {
    getDatafromFile(users, "user.txt");
    cout << "Enter email:- ";
    cin >> email;
    email = validateEmail(email);
    email = isEmailPresent(email);
    cout << "Email = " << email << endl;

    cout << "Enter password:- ";
    cin >> password;
    password = isPasswordMatch(password);
    cout << "Password = " << password << endl;

    setIsLogin(isLogin);
}

string Users::isEmailPresent(string email) {
    bool emailFound = false;
    while(true){
        for(int i=0;i<currentUser;i++){
            if(email == users[i].email){
                emailFound = true;
                storedPassword = users[i].password;
            }
        }

        if(emailFound){
            return email;
        }
        else{
            cout << "No such email found. Try again:- ";
            cin >> email;
        }
    }
}

string Users::isPasswordMatch(string password) {
    while(true){
        if(password == storedPassword){
            return password;
        }
        else{
            cout << "Incorrect password. Try Again:- ";
            cin >> password;
        }
    }
}

void Users::setIsLogin(bool isLogin) {
    this->isLogin = true;
}