#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Account{
    private:
    protected:
        struct User
        {
            string fName,lName,confirmPassword,contact,email,password,securityQuestions[3],status;
            int id = 0;
        };
        int currentUser = 0;
        User users[100];
        bool accountCreated;
        // string name,confirmPassword,contact,email,password,securityQuestions[3],status;
        // int id = 0;
    public:
        Account();
        void getUserDetails();
        string validateName(string name);
        string validateEmail(string email);
        string validateContact(string contact);
        string validatePassword(string password);
        string passwordMatch(string password, string confirmPassword);
        // void addAccount(int id,string name,string email,string contact,string password,string confirmPassword,string securityQuestions[3],string status);
        void saveAccount(User users[100], string fileName);
        void getDatafromFile(User users[100], string fileName);
        bool isAccountCreated();
};

#endif