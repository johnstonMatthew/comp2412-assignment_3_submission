#include <iostream>
#include <string>
using namespace std;

// Structure for the ListNode
class ListNode{
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

// Time Complexity: Linear - Θ(n) [Θ(1) + Θ(n) => Θ(n)]
int Sum(ListNode* head, int num) {
    if (head == nullptr) {
        // Base case: If the Passed Node is Null, Return the num Parameter
        return num;
    } else {
        // Call the Sum Method, but With Pointer to the Next Node and the Sum of the Current Sum and the Current Nodes Value
        return Sum(head->next, num + head->value);
    }
}

// Time Complexity: Linear - Θ(n) [Θ(n) + Θ(1) => Θ(n)]
int Search(ListNode* head, int searchValue) {
    // If the Search Value Hasn't Been Found
    if (head->value != searchValue && head->next != nullptr) {
        // Call the Search Method, but With Pointer to the Next Node and the Search Value
        return Search(head->next, searchValue);
    } else {
        // Base case: if the Element was Found, Return it
        return head->value;
    }

}

// Time Complexity: Linear - Θ(n) [Θ(1) + Θ(n) => Θ(n)]
void insertNode(ListNode*& head, int newData) {
    // Time Complexity: Constant - Θ(1)
    // If the Head is a nullptr, Create a new Node and Make it the Head
    if (head == nullptr) {
        ListNode* tp = new ListNode(newData);
        head = tp;

        return;
    }

    ListNode* tp = head;

    // Time Complexity: Linear - Θ(n)
    // While tp Points to Another Node, set tp to What the Current Iteration Points to
    while (tp->next) { // Θ(n)
        tp = tp->next;
    }

    tp->next = new ListNode(newData);// Set the Current Iteration of tp's Pointer to a Newly Created Node

    return;
}

// Time Complexity: Linear - Θ(n)
void outputSinglyLinkedList(ListNode*& head) {
    ListNode* tp = head;
    while (tp) {// While tp Points to Another Node, Output its Data
        std::cout << tp->value << " -> ";
        tp = tp->next;
    }
}

int main() {
    string input = "";

    ListNode* head = nullptr;

    int searchValue = 1;

    bool keepLooping = true;

    std::cout << "Enter Elements to Insert Into the Linked List (Enter 'done' to Finish): " << std::endl;

    // Time Complexity: Linear - Θ(n)
    while (input != "done") {
        std::cin >> input;

        if (input == "done") {
            break;
        }

        insertNode(head, stoi(input));
    }

    outputSinglyLinkedList(head);
    std::cout << std::endl;

    std::cout << "What Value Would you Like to Search for " << std::endl;
    std::cin >> searchValue;
    
    std::cout << std::endl;
    std::cout << "Sum: " << Sum(head, 0) << std::endl;
    std::cout << "Searching for " << searchValue << " Results: " << Search(head, searchValue) << std::endl;
}

