#include "account.h"
#include "menu.h"

using namespace std;

int main() {
	bool exitcall = 0;
	system("clear");

	cout << "Welcome to Dench Grading System..." << endl;

	//program verified account login
	Menu* menu = new Menu();
	while(!exitcall) {
		exitcall = menu->run();
	}


return 0;
}
