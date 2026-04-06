#include <iostream>

// Time Complexity: Linear - Θ(n) - [Θ(1) + Θ(n) => Θ(n)]
int recursiveFactorial(int number) {
    //Base Case: if the Current Number is 1
    if (number == 1) {
        return 1;
    } else {// Multiply the Current Number, by the Result of recursiveFactorial(number - 1)
        return (number * recursiveFactorial(number - 1) );
    }
}

int main () {
    int baseNumber = 6;
    std::cout << "Finding the Factorial of: " << baseNumber << std::endl;
    std::cout << recursiveFactorial(baseNumber)<< std::endl;
}