#pragma once
#include <string>
class Heap {
private:
	int *heap;
	unsigned size;
	std::string cr, cp, cl;
	int leftChild(int parent);								//funkcja zwracaj�ca lewe dziecko elementu parent
	int rightChild(int parent);								//funkcja zwracaj�ca prawe dziecko elementu parent
	int parent(int child);									//funkcja zwracaj�ca rodzica elementu child
	void heapFixUp(int idx);								//funkcja naprawiaj�ca kopiec w g�re od pozycji idx
	void heapFixDown(int idx);								//funkcja naprawiaj�ca kopiec w d� od pozycji idx
	void heapFix(int idx);									//funkcja naprawiaj�ca kopiec w d� lub w g�r� od pozycji idx
public:
	Heap();
	~Heap();
	void show(std::string sp, std::string sn, int idx);		//funkcja wy�wietlaj�ca kopiec
	void clearHeap();										//funkcja czyszcz�ca kopiec
	void searchFirst(int val);								//funkcja wyszukuj�ca pierwsze wyst�pienie elementu val
	unsigned getSize();										//funkcja zwracaj�ca rozmiar kopca
	void push(int val);										//funkcja dodaj�ca nowy element val
	void popRoot();											//funkcja usuwaj�ca korze�
	void popIdx(int idx);									//funkcja usuwaj�ca element idx
	void readFromFile();									//funkcja wczytuj�ca dane z pliku do kopca
};