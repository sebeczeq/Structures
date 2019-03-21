#pragma once
#include "Tab.h"
#include "List.h"
#include "Heap.h"
class Menu {
private:
	int option;
	Tab tab;
	List list;
	Heap heap;
public:
	Menu();
	~Menu();
	int value();
	int index();
	void mainMenu();
	void tabMenu();
	void listMenu();
	void heapMenu();
	void generateData();
};