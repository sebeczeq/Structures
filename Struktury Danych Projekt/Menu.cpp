#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>
Menu::Menu() {

}
Menu::~Menu() {

}
int Menu::value() {
	int value;
	std::cout << "Value: ";
	std::cin >> value;
	return value;
}
int Menu::index() {
	int value;
	std::cout << "Index: ";
	std::cin >> value;
	return value;
}
void Menu::mainMenu() {
	std::string temp;
	std::cout << "[1] -> Table \n[2] -> List \n[3] -> Heap \n[4] -> Generate Data \n[5] -> Close \nChoose task... \n";
	std::cin >> temp;
	option = atoi(temp.c_str());
	switch (option){
	case 1:
		system("cls");
		tabMenu();
		break;
	case 2:
		system("cls");
		listMenu();
		break;
	case 3:
		system("cls");
		heapMenu();
		break;
	case 4:
		system("cls");
		generateData();
		system("pause");
		system("cls");
		mainMenu();
	case 5:
		exit(0);
		break;
	default:
		std::cout << "Choose correct number. \n";
		system("pause");
		system("cls");
		mainMenu();
	}
}
void Menu::tabMenu() {
	std::string temp;
	std::cout << "Current table size: " << tab.getSize() << "\n\n";
	std::cout << "[1] -> Add new element at the front.\n";
	std::cout << "[2] -> Add new element at the end.\n";
	std::cout << "[3] -> Add new element at the choosen place.\n";
	std::cout << "[4] -> Remove element from the front.\n";
	std::cout << "[5] -> Remove element from the end.\n";
	std::cout << "[6] -> Remove element from the choosen place.\n";
	std::cout << "[7] -> Search element.\n";
	std::cout << "[8] -> Show table.\n";
	std::cout << "[9] -> Load data from file.\n";
	std::cout << "[10] -> Clear table.\n";
	std::cout << "[11] -> Return to main menu.\n";
	std::cout << "Choose task... \n ";
	std::cin >> temp;
	option = atoi(temp.c_str());
	switch (option)
	{
	case 1:
		system("cls");
		tab.pushFront(value());
		system("cls");
		tabMenu();
		break;
	case 2:
		system("cls");
		tab.pushBack(value());
		system("cls");
		tabMenu();
		break;
	case 3:
		system("cls");
		tab.pushIdx(value(), index());
		system("cls");
		tabMenu();
		break;
	case 4:
		system("cls");
		tab.popFront();
		system("cls");
		tabMenu();
		break;
	case 5:
		system("cls");
		tab.popBack();
		system("cls");
		tabMenu();
		break;
	case 6:
		system("cls");
		tab.popIdx(index());
		system("cls");
		tabMenu();
		break;
	case 7:
		system("cls");
		tab.searchFirst(value());
		system("pause");
		system("cls");
		tabMenu();
		break;
	case 8:
		system("cls");
		tab.show();
		system("pause");
		system("cls");
		tabMenu();
		break;
	case 9:
		system("cls");
		tab.readFromFile();
		system("pause");
		system("cls");
		tabMenu();
		break;
	case 10:
		tab.clearTab();
		system("cls");
		tabMenu();
		break;
	case 11:
		system("cls");
		mainMenu();
		break;
	default:
		std::cout << "Choose correct number. \n";
		system("pause");
		system("cls");
		tabMenu();
	}
}
void Menu::listMenu() {
	std::string temp;
	std::cout << "Current list size: " << list.getSize() << "\n\n";
	std::cout << "[1] -> Add new element at the front.\n";
	std::cout << "[2] -> Add new element at the end.\n";
	std::cout << "[3] -> Add new element at the choosen place.\n";
	std::cout << "[4] -> Remove element from the front.\n";
	std::cout << "[5] -> Remove element from the end.\n";
	std::cout << "[6] -> Remove element from the choosen place.\n";
	std::cout << "[7] -> Search element.\n";
	std::cout << "[8] -> Show list from the begining.\n";
	std::cout << "[9] -> Show list form the end.\n";
	std::cout << "[10] -> Load data from file.\n";
	std::cout << "[11] -> Clear list.\n";
	std::cout << "[12] -> Return to main menu.\n";
	std::cout << "Choose task...\n ";
	std::cin >> temp;
	option = atoi(temp.c_str());
	switch (option)
	{
	case 1:
		system("cls");
		list.pushFront(value());
		system("cls");
		listMenu();
		break;
	case 2:
		system("cls");
		list.pushBack(value());
		system("cls");
		listMenu();
		break;
	case 3:
		system("cls");
		list.pushIdx(value(), index());
		system("cls");
		listMenu();
		break;
	case 4:
		system("cls");
		list.popFront();
		system("cls");
		listMenu();
		break;
	case 5:
		system("cls");
		list.popBack();
		system("cls");
		listMenu();
		break;
	case 6:
		system("cls");
		list.popIdx(index());
		system("cls");
		listMenu();
		break;
	case 7:
		system("cls");
		list.searchFirst(value());
		system("pause");
		system("cls");
		listMenu();
		break;
	case 8:
		system("cls");
		list.show();
		system("pause");
		system("cls");
		listMenu();
		break;
	case 9:
		system("cls");
		list.showBack();
		system("pause");
		system("cls");
		listMenu();
		break;
	case 10:
		system("cls");
		list.readFromFile();
		system("pause");
		system("cls");
		listMenu();
		break;
	case 11:
		list.clearList();
		system("cls");
		listMenu();
		break;
	case 12:
		system("cls");
		mainMenu();
		break;
	default:
		std::cout << "Choose correct number. \n";
		system("pause");
		system("cls");
		listMenu();
	}
}
void Menu::heapMenu() {
	std::string temp;
	std::cout << "Current heap size: " << heap.getSize() << "\n\n";
	std::cout << "[1] -> Add new element.\n";
	std::cout << "[2] -> Remove root.\n";
	std::cout << "[3] -> Remove element from the choosen palce.\n";
	std::cout << "[4] -> Search element.\n";
	std::cout << "[5] -> Show heap.\n";
	std::cout << "[6] -> Load data from file.\n";
	std::cout << "[7] -> Clear heap.\n";
	std::cout << "[8] -> Return to main menu.\n";
	std::cout << "Choose task... \n ";
	std::cin >> temp;
	option = atoi(temp.c_str());
	switch (option)
	{
	case 1:
		system("cls");
		heap.push(value());
		system("cls");
		heapMenu();
		break;
	case 2:
		system("cls");
		heap.popRoot();
		system("cls");
		heapMenu();
		break;
	case 3:
		system("cls");
		heap.popIdx(index());
		system("cls");
		heapMenu();
		break;
	case 4:
		system("cls");
		heap.searchFirst(value());
		system("cls");
		heapMenu();
		break;
	case 5:
		system("cls");
		heap.show("", "", 0);
		system("pause");
		system("cls");
		heapMenu();
		break;
	case 6:
		system("cls");
		heap.readFromFile();
		system("pause");
		system("cls");
		heapMenu();
		break;
	case 7:
		heap.clearHeap();
		system("cls");
		heapMenu();
		break;
	case 8:
		system("cls");
		mainMenu();
		break;
	default:
		std::cout << "Choose correct number. \n";
		system("pause");
		system("cls");
		heapMenu();
	}
}
void Menu::generateData() {
	std::ofstream file;
	std::string fileName = "data.txt";
	int A, B, cnt;
	do {
		std::cout << "How big stucture is gotng to be: ";
		std::cin >> cnt;
	} while (cnt < 0);
	std::cout << "Choose range [A,B]. \n";
	std::cout << "A: ";
	std::cin >> A;
	std::cout << "B: ";
	std::cin >> B;

	file.open("data.txt", std::ios::out);
	if (file.is_open()) {
		file << cnt << std::endl;
		if (file.fail()) {
			std::cout << "ERR \n";
		}
		else {
			for (int i = 0; i < cnt; i++){
				if (file.fail()) {
					std::cout << "ERR \n";
					break;
				}
				else {
					if (i == cnt - 1){
						int val = rand() % (B - A + 1) + A;
						file << val;
					}
					else {
						int val = rand() % (B - A + 1) + A;
						file << val << std::endl;
					}
				}
				
			}
			std::cout << "Data was genereated to file: " << fileName << std::endl;	
			}
		file.close();
	}
	else
		std::cout << "ERR \n";
}