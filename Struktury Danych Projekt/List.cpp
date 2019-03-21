#include "List.h"
#include <iostream>
#include <fstream>
List::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}
List::~List() {
	while (head) {
		popFront();
	}
}
void List::show() {
	if (size == 0) {
		std::cout << "List is empty! \n";	
		system("pause");
		return;
	}
	else {
		ListElem *p = new ListElem;
		p = head;
		int i = 0;
		while (p) {
			std::cout << "[" << i << "] " << p->val << std::endl;
			p = p->next;
			i++;
		}
	}
}
void List::showBack() {
	if (size == 0) {
		std::cout << "List is empty! \n";	
		system("pause");
		return;
	}
	else {
		ListElem *p = new ListElem;
		p = tail;
		int i = 0;
		while (p) {
			std::cout << "[" << i << "] " << p->val << std::endl;
			p = p->prev;
			i++;
		}
	}
}
void List::clearList() {
	while (head)
	{
		popFront();
	}
	size = 0;
}
void List::searchFirst(int val){
	ListElem *p = head;
	int cnt = 0;
	if (size == 0) {
		std::cout << "List is empty! \n";
		system("pause");
		return;
	}
	while (p) {
		if (p->val == val) {
			std::cout << "First " << val << " is on " << cnt << " position. \n";
			system("pause");
			return;
		}
		cnt++;
		p = p->next;
	}
	std::cout << "There is no " << val << std::endl;
}
unsigned List::getSize() {
	return size;
}
void List::pushFront(int val)
{
	ListElem *p = new ListElem;
	if (size == 0) {
		p->next = nullptr;
		p->prev = nullptr;
		p->val = val;
		head = p;
		tail = p;
		size++;
	}
	else {
		p->next = head;
		p->prev = nullptr;
		p->val = val;
		head->prev = p;
		head = p;
		size++;
	}
}
void List::popFront() {
	if (head == nullptr) {
		std::cout << "List is empty! \n"; 
		system("pause");
		return;
	}
	else if (head->next == nullptr) {
		ListElem* p = head;
		tail = nullptr;
		head = nullptr;
		size--;
		delete p;
	}
	else {
		ListElem* p = head;
		head = head->next;
		size--;
		delete p;
	}
}
void List::pushBack(int val) {
	ListElem *p = new ListElem;
	if (size == 0) {
		p->next = nullptr;
		p->prev = nullptr;
		p->val = val;
		head = p;
		tail = p;
		size++;
	}
	else {
		p->next = nullptr;
		p->prev = tail;
		p->val = val;
		tail->next = p;
		tail = p;
		size++;
	}
}
void List::popBack() {
	if (head == nullptr) {
		std::cout << "List is empty! \n";    
		system("pause");
		return;
	}
	else {
		ListElem *p = tail;
		tail = p->prev;
		if (tail != nullptr)
			tail->next = nullptr;
		else 
			head = p->prev;
		delete p;
		size--;
	}
}
void List::pushIdx(int val, int idx) {
	if (size == idx) {
		pushBack(val);
	}
	else if (idx == 0) {
		pushFront(val);
	}
	else if (size < idx || idx < 0) {
		std::cout << "Index cannot be lower than 0 or greater than size of list. \n";
		system("pause");
	}
	else {
		int cnt = 0;
		ListElem *p = new ListElem;
		ListElem *r = head;
		while (cnt != idx) {
			r = r->next;
			cnt++;
		}
		p->val = val;
		p->next = r;
		p->prev = r->prev;
		r->prev->next = p;
		r->prev = p;
		size++;
	}
}
void List::popIdx(int idx) {
	if (size == idx) {
		popBack();
	}
	else if (idx == 0) {
		popFront();
	}
	else if (size < idx || idx < 0) {
		std::cout << "Index cannot be lower than 0 or greater than size of list. \n";		
		system("pause");
	}
	else {
		int cnt = 0;
		ListElem *p = new ListElem;
		ListElem *r = head;
		while (cnt != idx) {
			r = r->next;
			cnt++;
		}
		p = r;
		r->next->prev = r->prev;
		r->prev->next = r->next;
		delete p;
		size--;
	}
}
void List::readFromFile(){
	std::ifstream file;
	file.open("data.txt", std::ios::in);
	clearList();
	unsigned cnt;
	int data;
	if (file.is_open()) {
		file >> cnt;
		if (file.good()) {
			for (int i = 0; i < cnt; i++) {
				file >> data;
				pushBack(data);
				if (file.fail()) {
					std::cout << "FILE ERROR: cannot read data. \n";
					clearList();
					break;
				}	
			}
		}
		else {
			std::cout << "FILE ERROR: cannot read size. \n";
			clearList();
		}
		file.close();
	}
	else
		std::cout << "FILE ERROR: cannot be opened. \n";
}
