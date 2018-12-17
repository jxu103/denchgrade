#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    private:
        string username;
        string password;

    public:
        Account() {};

        bool login() {
            bool status;

            cout << "Please enter your username, Press Enter when finished: ";
            cin << this->username;
            cout << endl;

            cout << "Please enter your password, Press Enter when finished: ";
            cin << this->password
            cout << endl;

            status = checkUsername();
            status = checkPassword();

            return status;
        }

        bool checkUsername() {

        }

        bool checkPassword() {

        }
    
};



#endif
