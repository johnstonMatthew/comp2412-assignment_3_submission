#include <iostream>
#include <cmath>
#include <random>
#include <array>
#include <vector>
#include "Heap.h"

// Helper Functions
void PrintArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            std::cout << array[i] << " ";
        } else {
            std::cout << array[i] << std::endl;
        }
    }
}

// b)
int main() {
    srand(time(0));

    const int size = 1000;
    int randomNum = 0;

    int heapValues[size] = {};
 
    for (int i = 0; i < size; i++) {
        randomNum = rand() % 1000;

        if (i != 0) {
           heapValues[i] = randomNum; 
        } else {
           heapValues[i] = 0;
        }
    }// end for

    Heap heap = Heap(heapValues, size);

    std::cout << "Heap Array" << std::endl;
    heap.PrintValues();

    std::cout << std::endl;

    std::cout << "Minimum: " << heap.ExtractMin() << std::endl;
    heap.PrintValues();

    std::cout << std::endl;

    std::cout << "Heap Sorted: " << std::endl;
    heap.HeapSort();
    heap.PrintValues();

    std::cout << std::endl;
}