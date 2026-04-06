#include <iostream>
#include <utility>
#include <random>

//Complexity: Θ(n) -- Linear
std::pair<int, int> findSum(int sum, int* arr, int size, int newRightIndex) {
    if (arr == nullptr || size == 0) {
        std::cout << "Invalid input: array is null or empty." << std::endl;
        return { -1, -1 };
    }

    int leftIndex = 0;
    if (leftIndex >= size || newRightIndex < 0) {
        return { -1, -1 };
    }

    while (leftIndex < newRightIndex) { //Θ(n) - Linear 
        if (arr[leftIndex] + arr[newRightIndex] == sum) {
            return { leftIndex, newRightIndex };
        } else if (arr[leftIndex] + arr[newRightIndex] < sum) {
            leftIndex++;
        } else {
            newRightIndex--;
        }
    }
    return { -1, -1 };// If no Index Pairs are Found Then Return a Null Pair
}

//Complexity: Θ(n^2) -- Quadratic
void insertionSort(int arr[], int arrSize) {
    for (int i = 1; i < arrSize; i++) {
        int currentValue = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currentValue) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = currentValue;
    }
}

int main() {
	srand(time(0));

	int sum;
    int numbers[100];
    int size = std::size(numbers);
    //Printing and Generating the Unsorted Array
    std::cout << "Generated array: [";
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % size;
		if (i < (size - 1)) {
		    std::cout << numbers[i] << ", ";
		}
        else {
            std::cout << numbers[i];
        }
    }// end for
    std::cout << "]" << " (" << size << " Elements)\n" << std::endl;

    insertionSort(numbers, size);

    // Printing the Sorted Array
	std::cout << "Sorted array: [";
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i];
        if (i < size - 1) {
            std::cout << ", ";
        }
    }// end for
	std::cout << "]" << std::endl;

	std::cout << "Enter Your Target Sum: ";
	std::cin >> sum;
    std::cout << "\n";

    auto result = findSum(sum, numbers, size, size-1);

    if (result.first == -1) {
        std::cout << "No Index Pair Found." << std::endl;
    }
    else {
        std::cout << "Pair With the Target Sum Found at Indices: (" << result.first << "," << result.second << "): " << numbers[result.first] << " + " << numbers[result.second] << " = " << sum << std::endl;
    }
}
