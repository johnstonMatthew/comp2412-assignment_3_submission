#include <iostream>

// Exponential - Θ(2^n)
int recursiveFibonacci(int number) {
    //Base Case: if the Current Term of the Fibbonacci Sequence is 1 or Less
    if (number <= 1) {
        return number; 
    } else {
        //Return the Result of the Sum of the Current Term of the Fibbonacci Sequence - 1 and - 2
        return (recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2)  );
    }
}

int main () {
    int fibbonacciTerm = 8;
    std::cout << "Finding all Fibbonacci Terms Up and Until: " << fibbonacciTerm << std::endl;
    for (int i = 0; i < fibbonacciTerm; i++) {//Iterate up and Until the Value at fibbonacciTerm
        if (i != fibbonacciTerm - 1) {
            std::cout << recursiveFibonacci(i) << ", ";
        } else {
            std::cout << recursiveFibonacci(i) << std::endl;
        }
    }
}
