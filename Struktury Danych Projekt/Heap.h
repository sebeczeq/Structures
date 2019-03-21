#pragma once
#include <string>
class Heap {
private:
	int *heap;
	unsigned size;
	std::string cr, cp, cl;
	int leftChild(int parent);								//funkcja zwracaj¹ca lewe dziecko elementu parent
	int rightChild(int parent);								//funkcja zwracaj¹ca prawe dziecko elementu parent
	int parent(int child);									//funkcja zwracaj¹ca rodzica elementu child
	void heapFixUp(int idx);								//funkcja naprawiaj¹ca kopiec w góre od pozycji idx
	void heapFixDown(int idx);								//funkcja naprawiaj¹ca kopiec w dó³ od pozycji idx
	void heapFix(int idx);									//funkcja naprawiaj¹ca kopiec w dó³ lub w górê od pozycji idx
public:
	Heap();
	~Heap();
	void show(std::string sp, std::string sn, int idx);		//funkcja wyœwietlaj¹ca kopiec
	void clearHeap();										//funkcja czyszcz¹ca kopiec
	void searchFirst(int val);								//funkcja wyszukuj¹ca pierwsze wyst¹pienie elementu val
	unsigned getSize();										//funkcja zwracaj¹ca rozmiar kopca
	void push(int val);										//funkcja dodaj¹ca nowy element val
	void popRoot();											//funkcja usuwaj¹ca korzeñ
	void popIdx(int idx);									//funkcja usuwaj¹ca element idx
	void readFromFile();									//funkcja wczytuj¹ca dane z pliku do kopca
};