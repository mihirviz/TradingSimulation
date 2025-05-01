#include "account.h"

Account::Account() {
    currentUser = 0;
    User users[100];

    getDatafromFile(users, "user.txt");
}

void Account::getUserDetails() {
    int i = currentUser;
    users[i].id = currentUser + 1;
    cout << "Enter first name:- ";
    cin >> users[i].fName;
    users[i].fName = validateName(users[i].fName);
    cout << "Name = " << users[i].fName << endl;

    cout << "Enter last name:- ";
    cin >> users[i].lName;
    users[i].lName = validateName(users[i].lName);
    cout << "Name = " << users[i].lName << endl;

    cout << "Enter email:- ";
    cin >> users[i].email;
    users[i].email = validateEmail(users[i].email);
    cout << "Email = " << users[i].email << endl;

    cout << "Enter contact number:- ";
    cin >> users[i].contact;
    users[i].contact = validateContact(users[i].contact);
    cout << "Contact = " << users[i].contact << endl;

    cout << "Enter password:- ";
    cin >> users[i].password;
    users[i].password = validatePassword(users[i].password);
    cout << "Password = " << users[i].password << endl;

    cout << "Enter confirm password:- ";
    cin >> users[i].confirmPassword;
    users[i].confirmPassword =
    passwordMatch(users[i].password, users[i].confirmPassword);
    cout << "confirmPassword = " << users[i].confirmPassword << endl;

    cout << "Here are some security questions for backup:- " << endl;
    cout << "What is the name of your favourite teacher:- ";
    cin >> users[i].securityQuestions[0];
    users[i].securityQuestions[0] = validateName(users[i].securityQuestions[0]);
    cout << "What is the name of the first street you lived in:- ";
    cin >> users[i].securityQuestions[1];
    users[i].securityQuestions[1] = validateName(users[i].securityQuestions[1]);
    cout << "What is the name of your favourite food:-  ";
    cin >> users[i].securityQuestions[2];
    users[i].securityQuestions[2] = validateName(users[i].securityQuestions[2]);

    users[i].status = "active";

    currentUser++;
    this->accountCreated = isAccountCreated();
    saveAccount(users, "user.txt");
}

string Account::validateName(string name) {
    while (true)
    {
        if(name.length() < 2){
            cout<<"Name is too short. Try Again:- ";
            cin>>name;
        }
        else if(name.length() > 10){
            cout<<"Name is too long. Try Again:- ";
            cin>>name;
        }
        else{
            bool digit = false,special = false;
            string specialCharacter = "`~!@#$%^&*()-_+=[]{}|':;.,<>/?*";

            for(char ch : name){
                if(isdigit(ch)){
                    digit = true;
                }
                else if(specialCharacter.find(ch) != string::npos){
                    special = true;
                }
            }

            if(!digit && !special){
                return name;
            }
            else{
                cout<<"Please enter a valid Name:- ";
                cin>>name;
            }
        }
    }
}

std::string Account::validateEmail(std::string email) {
    const std::string validGmail = "@gmail.com";
    const std::string validOutlook = "@outlook.com";

    while (true) {
        if (email.size() <= validGmail.size() && email.size() <= validOutlook.size()) {
            std::cout << "Email too short. Try again: ";
            std::cin >> email;
            continue;
        }

        bool isValid = false;
        if (email.size() >= validGmail.size() && email.compare(email.size() - validGmail.size(), validGmail.size(), validGmail) == 0) {
            isValid = true;
        } 
        else if (email.size() >= validOutlook.size() && email.compare(email.size() - validOutlook.size(), validOutlook.size(), validOutlook) == 0) {
            isValid = true;
        }

        if (isValid) {
            return email;
        } else {
            std::cout << "Enter a valid email: ";
            std::cin >> email;
        }
    }
}

string Account::validateContact(string contact) {
    while (true)
    {
        if(contact.length() != 10){
            cout<<"Enter a valid number. Try Again"<<endl;
            cin>>contact;
        }
        else if(contact[0] != '0'){
            cout<<"Contact should start with 0. Try Again"<<endl;
            cin>>contact;
        }
        else{
            bool digit = false;

            for(char ch : contact){
                if(!isdigit(ch)){
                    digit = true;
                }
            }

            if(!digit){
                return contact;
            }
            else{
                cout<<"Please enter a valid Contact:- ";
                cin>>contact;
            }
        }
    }
}

string Account::validatePassword(string password) {
    while (true)
    {
        if(password.length() < 5){
            cout<<"Name is too short. Try Again"<<endl;
            cin>>password;
        }
        else if(password.length() > 15){
            cout<<"Name is too long. Try Again"<<endl;
            cin>>password;
        }
        else{
            bool upper = false,lower = false,digit = false,special = false;
            string specialCharacter = "`~!@#$%^&*()-_+=[]{}|':;.,<>/?*";

            for(char ch : password){
                if(isupper(ch)){
                    upper = true;
                }
                else if(islower(ch)){
                    lower = true;
                }
                else if(isdigit(ch)){
                    digit = true;
                }
                else if (specialCharacter.find(ch) != string::npos) {
                    special = true;
                }
            }

            if(upper && lower && digit && special){
                return password;
            }
            else{
                cout<<"Try a stronger passwrod..."<<endl;
                cin>>password;
            }
        }
    }
}

string Account::passwordMatch(string password, string confirmPassword) {
    while (true)
    {
        if(password != confirmPassword){
            cout<<"Password and confirm password should be same. Try again"<<endl;
            cin>>confirmPassword;
        }
        else{
            return confirmPassword;
        }        
    }
}

void Account::saveAccount(User users[100], string fileName) {
    ofstream file(fileName);

    if(file.is_open()){
        for(int i=0;i<currentUser;i++){
            file << "User" << i+1 << "\n" << users[i].id << "\n" << users[i].fName << "\n" << users[i].lName << "\n" << users[i].email << "\n" << users[i].contact << "\n" << users[i].password << "\n" << users[i].securityQuestions[0] << "\n" << users[i].securityQuestions[1] << "\n" << users[i].securityQuestions[2] << "\n" << users[i].status << "\n";
        }

        file.close();
    }
    else{
        cout<<"File not opening"<<endl;
    }
}

void Account::getDatafromFile(User users[100], string fileName) {
    ifstream file(fileName);
    string userCount;
    int i = 0;
    string strId;
    string fileEmpty = "";

    while(true){
        getline(file,userCount) &&
        getline(file, strId) &&
        getline(file, this->users[i].fName) &&
        getline(file, this->users[i].lName) &&
        getline(file, this->users[i].email) &&
        getline(file, this->users[i].contact) &&
        getline(file, this->users[i].password) &&
        getline(file, this->users[i].securityQuestions[0]) &&
        getline(file, this->users[i].securityQuestions[1]) &&
        getline(file, this->users[i].securityQuestions[2]) &&
        getline(file, this->users[i].status);
        
        if(file.eof()){
            break;
        }
        else{
            this->currentUser++;
            this->users[i].id = this->currentUser;
            i++;
        }
    }
}

bool Account::isAccountCreated() {
    return true; 
}
