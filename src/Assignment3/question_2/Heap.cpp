#include "Heap.h"
#include <iostream>
#include <cmath>
#include <algorithm>

// --- Constructors ---
// Default Constructor
Heap::Heap() {
	SetSize(0);
	SetNumOfElements(0);
	SetValues({ 0 });
}

// Parameter Constructor
Heap::Heap(int heap[], int size) {
	SetSize(size);
	SetNumOfElements(GetSize() - 1);
	Values = new int[size]();
	SetValues(heap);

	BuildHeap();
}

// --- Helper Functions ---
// Function to Output the Values Array Into the Console
void Heap::PrintValues() {
	for (int i = 0; i <= GetNumOfElements(); i++) {
		std::cout << Values[i] << " ";
	}
	std::cout << std::endl;
}

// --- Getters ---
int Heap::GetSize() {
	return Size;
}

int Heap::GetNumOfElements() {
	return NumOfElements;
}

int* Heap::GetValues() {
	return Values;
}

// --- Setters ---
void Heap::SetSize(int size) {
	Size = size;
}

void Heap::SetNumOfElements(int numOfElements) {
	NumOfElements = numOfElements;
}

void Heap::SetValues(int heap[]) {
	Values[0] = 0;
	for (int i = 1; i < GetSize(); i++) {
		Values[i] = heap[i];
	}
}

// --- Parent and Child Index Getters ---
// Function That Returns the Parent Index of a Node
int Heap::Parent(int index) {
	return std::floor(index / 2);
}
// Function That Returns the Left Child's Index of a Node
int Heap::LeftChild(int index) {
	return index * 2;
}
// Function That Returns the Right Child's Index of a Node
int Heap::RightChild(int index) {
	return (index * 2) + 1;
}

// --- Min Getters ---
// Function That Returns the Min of the MinHeap
int Heap::GetMin() {
	return Values[1];
}

// Function That Returns the Min and Removes it From the Values Array
int Heap::ExtractMin() {
	int minValue = GetMin();// Get Minimum

	// Check if the MinHeap has Child Elements
	Values[1] = Values[GetNumOfElements()];

	SetNumOfElements(GetNumOfElements() - 1);

	FixMinNode(1);
	
	return minValue;
}

void Heap::FixMinNode(int index) {
	int leftChildIndex = LeftChild(index);
	int rightChildIndex = RightChild(index);
	int rootIndex = index;

	if (leftChildIndex <= GetNumOfElements() && Values[leftChildIndex] < Values[rootIndex])
		rootIndex = leftChildIndex;

	if (rightChildIndex <= GetNumOfElements() && Values[rightChildIndex] < Values[rootIndex])
		rootIndex = rightChildIndex;

	if (rootIndex != index) {
		int temp = Values[index];

		Values[index] = Values[rootIndex];
		Values[rootIndex] = temp;
		FixMinNode(rootIndex);
	}
}

void Heap::BuildHeap() {
	for (int i = std::floor(GetNumOfElements() / 2); i >= 1; i--) {
		FixMinNode(i);
	}//end for
}

void Heap::HeapSort() {
	const int oldSize = GetSize();

	int* sorted = new int[oldSize];
	sorted[0] = 0;
	int i = 1;
	
	for (int i = 1; i < oldSize; i++) {
		sorted[i] = ExtractMin();
	}

	delete[] Values;
	Values = sorted;
	SetNumOfElements(oldSize - 2);
}

void Heap::Insert(int value) {
	int oldSize = GetSize();
	int newSize = oldSize + 1;

	int* newValues = new int[newSize]();
	newValues[0] = 0;

	for (int i = 1; i <= GetNumOfElements(); i++) {
		newValues[i] = Values[i];
	}

	newValues[GetNumOfElements() + 1] = value;

	delete[] Values;

	Values = newValues;

	SetSize(newSize);
	SetNumOfElements(GetNumOfElements() + 1);

	BuildHeap();

}