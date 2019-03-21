#pragma once
#include "ListElem.h"
class List {
private:
	ListElem* head;
	ListElem* tail;
	unsigned size;
public:
	List();
	~List();
	void show();							//funkcja pokazuj�ca elementy listy w osobnych wierszach od pierwszego elementu
	void showBack();						//funkcja pokazuj�ca elementy listy w osobnych wierszach od ostatniego elementu
	void clearList();						//funkcja czyszcz�ca list�			
	void searchFirst(int val);				//funkcja szukaj�ca pierwsze wyst�pienie elementu val
	unsigned getSize();						//funkcja zwracaj�ca wielko�� listy
	void pushFront(int val);				//funkcja dodaj�ca element val na pocz�tek listy
	void popFront();						//funkcja usuwaj�ca element z pocz�tku listy
	void pushBack(int val);					//funkcja dodaj�ca element val na koniec listy
	void popBack();							//funkcja usuwaj�ca ostatni element
	void pushIdx(int val, int idx);			//funkcja dodaj�ca element val na pozycj� idx
	void popIdx(int idx);					//funkcja usuwaj�ca element z pozycji idx
	void readFromFile();					//funkcja wczytuj�ca dane z pliku do listy
};