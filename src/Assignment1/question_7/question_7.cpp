#include <iostream> 
#include <stack> 
#include <string> 

// Structure of a Node
struct node {
    char data;
    struct node* next;

    node(char newData) {
        data = newData;
        next = nullptr;
    }
};

// Complexity: Θ(n) -- Linear
void outputSinglyLinkedList(node*& head) {
    node* tp = head;
    // While tp Pointer to Another Node, Continue Iterating Through the Linked List
    while (tp) {
        std::cout << tp->data << " -> ";
        tp = tp->next;
    }// end while
}

//Complexity: Θ(n) -- Linear
bool isBalanced(const std::string& str) {
    char oldTop;
    node* newTop = nullptr;
    node* top = nullptr;

    node* tp = nullptr;

    int length = str.length();

    // If the Length of the String is Less or not Even is Length, The Parentheses Cannot Be Balanced
    if (length < 2 || length % 2 != 0) {
        return false;
    }

    //Iterate Through the str Parameter
    for (char i = 0; i < length; i++) { //Θ(n)
        // If the Current Iteration's Character is '(', Then Push Character to the top of the Stack
        if (str[i] == '(') {
            newTop = new node(str[i]);
            newTop->next = top;
            top = newTop;
        // If the Current Iteration's Character is ')', Then Pop the top '(' From the Stack
        } else if (str[i] == ')') {
            //If the top of the Stack is a nullptr, the Stack is Null Meaning Each '( has a Matching ')'
            if (top == nullptr) {
                return true;
            }

            tp = top;
            top = top->next;
            oldTop = tp->data;
            delete tp;
        // Return False if There are any Other Characters Besides ( or )
        } else {
            std::cout << "A Character Besides '(' and ')' has Been Found! " << std::endl;
            return false;
        }
    }// end for
    std::cout << "\n";
    outputSinglyLinkedList(top);

    return true;
}


int main() {
    std::string input;
    std::cout << "Enter a String of Parentheses: ";
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "The Parentheses are Balanced.\n";
    } else {
        std::cout << "The Parentheses are not Balanced.\n";
    }

    return 0;
}
