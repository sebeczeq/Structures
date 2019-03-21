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
	void show();							//funkcja pokazuj¹ca elementy listy w osobnych wierszach od pierwszego elementu
	void showBack();						//funkcja pokazuj¹ca elementy listy w osobnych wierszach od ostatniego elementu
	void clearList();						//funkcja czyszcz¹ca listê			
	void searchFirst(int val);				//funkcja szukaj¹ca pierwsze wyst¹pienie elementu val
	unsigned getSize();						//funkcja zwracaj¹ca wielkoœæ listy
	void pushFront(int val);				//funkcja dodaj¹ca element val na pocz¹tek listy
	void popFront();						//funkcja usuwaj¹ca element z pocz¹tku listy
	void pushBack(int val);					//funkcja dodaj¹ca element val na koniec listy
	void popBack();							//funkcja usuwaj¹ca ostatni element
	void pushIdx(int val, int idx);			//funkcja dodaj¹ca element val na pozycjê idx
	void popIdx(int idx);					//funkcja usuwaj¹ca element z pozycji idx
	void readFromFile();					//funkcja wczytuj¹ca dane z pliku do listy
};