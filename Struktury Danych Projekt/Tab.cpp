#include "Tab.h"
#include <iostream>
#include <fstream>
Tab::Tab() {
	tab = nullptr;
	size = 0;
}
Tab::~Tab() {
	clearTab();
}
void Tab::show() {
	if (size == 0) {
		std::cout << "Table is empty! \n";
		system("pause");
		return;
	}
	else {
		for (int i = 0; i < size; i++) {
			std::cout << "[" << i << "]" << tab[i] << std::endl;
		}
	}
}
void Tab::clearTab() {
	if (size != 0) {
		delete[] tab;
		tab = nullptr;
		size = 0;
	}
}
void Tab::searchFirst(int val) {
	if (size == 0) {
		std::cout << "Table is empty! \n";
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++) {
		if (tab[i] == val)
			std::cout << "Found " << val << " on " << i << " position.\n";
		return;
	}
	std::cout << "Could not find " << val << std::endl;
}
unsigned Tab::getSize() {
	return size;
}
void Tab::pushFront(int val) {
	int *newTab = new int[size + 1];
	newTab[0] = val;
	for (int i = 0; i < size; i++)
		newTab[i + 1] = tab[i];
	delete[]tab;
	tab = newTab;
	size++;
}
void Tab::popFront() {
	if (size == 0) {
		std::cout << "Table is empty! \n";
		system("pause");
		return;
	}
	int *newTab = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
		newTab[i] = tab[i + 1];
	delete[] tab;
	tab = newTab;
	size--;
}
void Tab::pushBack(int val) {
	int *newTab = new int[size + 1];
	newTab[size] = val;
	for (int i = 0; i < size; i++)
		newTab[i] = tab[i];
	delete[]tab;
	tab = newTab;
	size++;
}
void Tab::popBack() {
	if (size == 0) {
		std::cout << "Table is empty! \n";
		system("pause");
		return;
	}
	int *newTab = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
		newTab[i] = tab[i];
	delete[] tab;
	tab = newTab;
	size--;
}
void Tab::pushIdx(int val, int idx) {
	if (idx<0 || idx>size) {
		std::cout << "Index cannot be lower than 0 or greater than size of table. \n";
		system("pause");
		return;
	}
	if (idx < size && idx>0) {
		int *newTab = new int[size + 1];
		for (int i = 0; i < size; i++)
			newTab[i] = tab[i];
		newTab[idx] = val;
		for (int i = idx + 1; i < size + 1; i++)
			newTab[i] = tab[i - 1];
		delete[] tab;
		tab = newTab;
		size++;
	}
	else if (idx == 0) {
		pushFront(val);
	}
	else if (idx == size) {
		pushBack(val);
	}
}
void Tab::popIdx(int idx) {
	if (size == 0) {
		std::cout << "Table is empty! \n";
		system("pause");
		return;
	}
	if (idx < size && idx>0) {
		int *newTab = new int[size - 1];
		for (int i = 0; i < idx; i++)
			newTab[i] = tab[i];
		for (int i = idx; i < size - 1; i++)
			newTab[i] = tab[i + 1];
		delete[] tab;
		tab = newTab;
		size++;
	}
	else if (idx == 0) {
		popFront();
	}
	else if (idx == size) {
		popBack();
	}
}
void Tab::readFromFile() {
	std::ifstream file;
	file.open("data.txt", std::ios::in);
	clearTab();
	unsigned cnt;
	int data;
	if (file.is_open()) {
		file >> cnt;
		if (file.fail()) {
			std::cout << "FILE ERROR: cannot read size. \n";
		}
		else {
			for (int i = 0; i < cnt; i++) {
				file >> data;
				if (file.fail()) {
					std::cout << "FILE ERROR: cannot read data. \n";
					break;
				}
				else {
					pushBack(data);
				}
			}
			file.close();
		}
	}
	else
		std::cout << "FILE ERROR: cannot be opened. \n";
}