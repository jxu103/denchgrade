#ifndef MENU_H
#define MENU_H

#include "account.h"
#include <iostream>
#include <string>

using namespace std;

class Menu {
    private:
        Account* account;

    public:
        bool run() {
            bool exitcall;

            this->loginMenu();
            exitcall = this->mainMenu();

            return exitcall;
        }

        void loginMenu() {
            this->account = new Account();	
	        bool userLogin = 0;
	        bool exitCall = 0;

            while(exitCall == 0) {
                cout << "Please choose an option from the menu" << endl;
                cout << "1. Login" << endl;
                cout << "2. Create Account" << endl;
                cout << "3. Exit" << endl;

                //Prompting User
                string userInput;
                cin >> userInput;
                

                if(userInput == "1") {
                    //calls login function	
                    bool status = account->login();
                    if(!status) {
                        // Should not end program here, loop to menu
                        cout << "The username or password you've entered is incorrect" << endl;
                    }
                    else {
                        // Unimplemented
                        cout << "Correct login!" << endl;
                        cout << "Welcome back: " << account->getUsername() << "!" << endl;
                        exitCall = 1;
                    }
                    
                }
                else if(userInput == "2") {
                    account->signup();
                    cout << "Signup successful!" << endl;
                    // Unimplemented
                    exitCall = 0;
                }
                else if(userInput == "3") {
                    cout <<"Thanking for using Dench Grading System" << endl;
                    exit(-1);
                }
                else {
                    cout <<"Invalid selection" << endl;
                }
            }
        }

        bool mainMenu() {
                return 1;
        }



};

#endif