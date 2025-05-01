#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <fstream>
#include "account.h"
using namespace std;

class Users : public Account{
    private:
    protected:
        string email, password, storedPassword;
        bool isLogin;
        int loginAttempts, choice;
    public:
        Users();
        void getLoginDetails();
        string isEmailPresent(string email);
        string isPasswordMatch(string password);
        void setIsLogin(bool isLogin);
        int promptChoice();
        bool getIsLogin();
};

#endif