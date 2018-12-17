#include "account.h"
#include <iostream>


using namespace std;

int main() {
	bool userLogin = 0;
	bool exitCall = 0;

	cout << "Welcome to Dench Grading System..." << endl;
		
	while(exitCall == 0) {
		cout << "Please choose an option from the menu" << endl;
		cout << "1. Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Exit" << endl;

		//Account* currentUser;
		//Prompting User
		string userInput;
		cin >> userInput;
		Account* account = new Account();

		if(userInput ==  "1") {
			//calls login function	
			bool status = account->login();
			if(!status) {
				cout << "The username or password you've entered is incorrect" << endl;
			}
			else {
				exitCall = 1;
			}
		}
		else if(userInput == "2") {
			cout << "User prompted 2, unimplemented. Exiting" << endl;
			exit(-1);

			//createAccount();
		}
		else if(userInput == "3") {
			cout <<"Thanking for using Dench Grading System" << endl;
			exitCall = -1;
		}
		else {
			cout <<"Invalid input" << endl;
		}
	}

return 0;
}
