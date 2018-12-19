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
            system("clear");
            cout << "\t---Login---" << endl << endl;
            cout << "Please enter your username, Press Enter when finished: ";
            cin >> this->username;
            cout << endl;

            cout << "Please enter your password, Press Enter when finished: ";
            cin >> this->password;
            cout << endl;

            return checkLogin();
        }

        /*
            Prompts the user for a desired username and password to be added to the database.
            Adds to database if username is not already in use.
        */
        void signup() {
            bool confirmed = false;
            bool usernameConfirm = false;

            system("clear");
            cout << "\t---Sign Up---" << endl << endl;
            
            while(!usernameConfirm) {
                cout << "Please enter a desired username, Press Enter when finished: ";
                cin.ignore();
                getline(cin,username);

                // Checks if spaces are present
                if(username.find(" ") != string::npos) cout << "Spaces are not allowed" << endl;
                else if (userExists(username)) cout << "Username already in use" << endl;
                else usernameConfirm = true;
            }
            

            cout << endl;

            // Password confirmation
            while (!confirmed) {
                cout << "Please enter a desired password, Press Enter when finished: ";
                getline(cin,password);
                cout << endl;

                string pwConfirm;
                cout << "Enter your password again to confirm, Press Enter when finished: ";
                getline(cin,pwConfirm);
                cout << endl;

                if (pwConfirm.compare(password) == 0) confirmed = true;
                else cout << "Passwords does not match! Please try again." << endl;
            }

            // Opening file stream for writing
            ofstream accts("src/accounts", ios_base::app);

            // Appending username and password to accounts file
            accts << username << " " << password << "\r";
        }


        /*
            Scans the given username in the database of created accounts.
            Returns true if found and false otherwise
        */
        bool userExists(string user) {
            // Opening file stream for reading
			ifstream accts("src/accounts");
			string line;

            while (getline(accts, line, '\r')) {
                // Parsing each line with whitespace delim
                stringstream infos(line);
                string token;

                // Get username and compare
                getline(infos, token, ' ');
                if (user.compare(token) == 0) return true;
            }
            cout << "over" << endl;
            return false;
        }

        /*
            Checks if the current user's username and password matches any login data in the database.
            Returns true if found and false otherwise
        */
        bool checkLogin() {
		    // Opening file stream for reading
			ifstream accts("src/accounts");
			string line;
			
			if (accts) {
                bool correctLogin = false;
				while (getline(accts, line, '\r')) {
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
			} else {cout << "Account file could not be opened" << endl; exit(-1);}
            return false;
        }

        string getUsername() {
            return this->username;
        }
    
};



#endif
