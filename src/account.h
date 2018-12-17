#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account {
    private:
        string username;
        string password;

    public:
        Account() {};

        bool login() {
            cout << "Please enter your username, Press Enter when finished: ";
            cin >> this->username;
            cout << endl;

            cout << "Please enter your password, Press Enter when finished: ";
            cin >> this->password;
            cout << endl;

            return checkLogin();
        }

        bool checkLogin() {
            ifstream ifs('./accounts');
        }
    
};



#endif
