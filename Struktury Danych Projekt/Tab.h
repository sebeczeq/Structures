#pragma once
class Tab {
private:
	int *tab;
	unsigned size;
public:
	Tab();								
	~Tab();									
	void show();							//funkcja pokazuj¹ca ca³¹ tabelê w osobnych wierszach
	void clearTab();						//funkcja czyszcz¹ca tabelê
	void searchFirst(int val);				//funkcja zwracaj¹ca pierwsze wyst¹pienie warotœci val
	unsigned getSize();						//funkcja zwracaj¹ca wielkoœæ tabeli
	void pushFront(int val);				//funkcja dodaj¹ca element val na pocz¹tek tabeli
	void popFront();						//funkcja usuwaj¹ca element z pocz¹tku tabeli
	void pushBack(int val);					//funkcja dodaj¹ca element val na koniec tabeli
	void popBack();							//funkcja usuwaj¹ca element z koñca tabeli
	void pushIdx(int val, int idx);			//funkcja dodaj¹ca element val na pozycjê idx
	void popIdx(int idx);					//funkcja usuwaj¹ca element z pozycji idx
	void readFromFile();					//funkcja wczytuj¹ca dane z pliku do tabeli
};