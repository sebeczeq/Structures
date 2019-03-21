#pragma once
class Tab {
private:
	int *tab;
	unsigned size;
public:
	Tab();								
	~Tab();									
	void show();							//funkcja pokazuj�ca ca�� tabel� w osobnych wierszach
	void clearTab();						//funkcja czyszcz�ca tabel�
	void searchFirst(int val);				//funkcja zwracaj�ca pierwsze wyst�pienie warot�ci val
	unsigned getSize();						//funkcja zwracaj�ca wielko�� tabeli
	void pushFront(int val);				//funkcja dodaj�ca element val na pocz�tek tabeli
	void popFront();						//funkcja usuwaj�ca element z pocz�tku tabeli
	void pushBack(int val);					//funkcja dodaj�ca element val na koniec tabeli
	void popBack();							//funkcja usuwaj�ca element z ko�ca tabeli
	void pushIdx(int val, int idx);			//funkcja dodaj�ca element val na pozycj� idx
	void popIdx(int idx);					//funkcja usuwaj�ca element z pozycji idx
	void readFromFile();					//funkcja wczytuj�ca dane z pliku do tabeli
};