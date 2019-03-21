#include "Menu.h"
#include <Windows.h>
#include <ctime>

int main() {
	srand(time(NULL));
	Menu menu;
	menu.mainMenu();
	system("pause");
	return 0;
}