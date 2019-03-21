#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
int Heap::leftChild(int parent) {
	int leftChild = 2 * parent + 1;
	if (leftChild < size)
		return leftChild;
	else
		return -1;
}
int Heap::rightChild(int parent) {
	int rightChild = 2 * parent + 2;
	if (rightChild < size)
		return rightChild;
	else
		return -1;
}
int Heap::parent(int child) {
	int parent = (child - 1) / 2;
	if (child == 0)
		return -1;
	else
		return parent;
}
void Heap::heapFixUp(int idx) {
	if (idx >= 0 && parent(idx) >= 0 && heap[parent(idx)] < heap[idx]) {
		int temp = heap[idx];
		heap[idx] = heap[parent(idx)];
		heap[parent(idx)] = temp;
		heapFixUp(parent(idx));
	}
}
void Heap::heapFixDown(int idx) {
	int lChild = leftChild(idx);
	int rChild = rightChild(idx);
	int biggerChild;
	if (lChild > 0 && rChild > 0 && heap[lChild] < heap[rChild]) 
		biggerChild = rChild;
	else
		biggerChild = lChild;
	if (biggerChild > 0 && heap[biggerChild] > heap[idx]){
		int temp = heap[biggerChild];
		heap[biggerChild] = heap[idx];
		heap[idx] = temp;
		heapFixDown(biggerChild);
	}
}
void Heap::heapFix(int idx) {
	if (heap[idx] > heap[parent(idx)])
		heapFixUp(idx);
	else
		heapFixDown(idx);
}
Heap::Heap() {
	cr = cl = cp = "  ";	
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	size = 0;
	heap = nullptr;
}
Heap::~Heap() {
	clearHeap();
}
void Heap::show(std::string sp, std::string sn, int idx) {
	std::string s;
	if (idx < size)	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
			show(s + cp, cr, 2 * idx + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << heap[idx] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
			show(s + cp, cl, 2 * idx + 1);
	}
}
void Heap::clearHeap() {
	if (size != 0) {
		delete[]heap;
		heap = nullptr;
		size = 0;
	}
}
void Heap::searchFirst(int val) {
	if (size == 0) {
		std::cout << "Heap is empty! \n";
		system("pause");
		return;
	}
	for (int i = 0; i < size; i++) {
		if (heap[i] == val)
			//std::cout << "Found " << val << " on " << i << " position.\n";
			return;
	}
	//std::cout << "Could not find " << val << std::endl;
}
unsigned Heap::getSize() {
	return size;
}
void Heap::push(int val) {
	int *newHeap = new int[size + 1];		
	for (int i = 0; i < size; i++)
	{
		newHeap[i] = heap[i];
	}
	newHeap[size] = val;
	size++;
	delete heap;
	heap = newHeap;
	heapFixUp(size - 1);
}
void Heap::popRoot() {
	if (size == 0) {
		std::cout << "Heap is empty! \n";
		system("pause");
		return;
	}
	heap[0] = heap[size - 1];		
	size--;
	int *newHeap = new int[size];
	for (int i = 0; i < size; i++) {
		newHeap[i] = heap[i];
	}
	delete heap;
	heap = newHeap;
	heapFixDown(0);		
}
void Heap::popIdx(int idx) {
	if (size == 0) {
		std::cout << "Heap is empty! \n";
		system("pause");
		return;
	}
	if (idx<0 || idx>=size) {
		std::cout << "Index cannot be lower than 0 or greater than size of heap. \n";
		system("pause");
	}
	else if (idx == 0) {
		popRoot();
	}
	else if (idx == size - 1) {
		size--;
		int *newHeap = new int[size];
		for (int i = 0; i < size; i++)
			newHeap[i] = heap[i];
		delete heap;
		heap = newHeap;
	}
	else {
		heap[idx] = heap[size - 1];
		size--;
		int *newHeap = new int[size];
		for (int i = 0; i < size; i++)
			newHeap[i] = heap[i];
		delete heap;
		heap = newHeap;
		heapFix(idx);
	}
}
void Heap::readFromFile() {
	std::ifstream file;
	file.open("data.txt", std::ios::in);
	clearHeap();
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
					push(data);
				}
			}
			file.close();
		}
	}
	else
		std::cout << "FILE ERROR: cannot be opened. \n";
}