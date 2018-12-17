#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <sstream>
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
		    // Opening file stream for reading
			ifstream accts("src/accounts");
			string line;
			
			if (accts) {
                bool correctLogin = false;
				while (getline(accts, line)) {
					// Parsing each line with whitespace delim
					stringstream infos(line);
					string token;

                    // Get username and compare
					getline(infos, token, ' ');
					if (this->username.compare(token) == 0) correctLogin = true;

                    // Get password and compare
					getline(infos, token, '\r');
					if (this->password.compare(token) == 0 && correctLogin) return true;
				}
			} else cout << "Account file could not be opened" << endl;
            return false;
        }
    
};



#endif
