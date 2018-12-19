#include "account.h"
#include "menu.h"

using namespace std;

int main() {
	system("clear");

	cout << "Welcome to Dench Grading System..." << endl;

	//program verified account login
	Menu* menu = new Menu();
	menu->login();


return 0;
}
