#include <iostream>

using namespace std;

int main() {
	bool userLogin = 0;
	bool exitCall = 0;

	while(exitCall = 0) {
		cout << "Welcome to Dench Grading System..." << endl;
		cout << "Please choose an option from the menu" << endl;
		cout << "1. Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Exit" << endl;
		
		Account* currentUser;
		string userInput;
		cin << userInput;
		if(userInput ==  "1") {
			//sets currentUser to login user		
			currentUser = login();
		}
		else if(userInput == "2") {
			createAccount();
		}
		else if(userInput == "3") {
			cout <<"Thanking for using Dench Grading System" << endl;
			return 0;
		}
		else {
			cout <<"Invalid input" << endl;
		}

	}
	




return 0;
}
