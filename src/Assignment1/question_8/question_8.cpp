#include <iostream>
#include <vector>
#include <chrono>
using std::vector;

struct node {
    int data;
    struct node* next;

    node(int newData) {
        data = newData;
        next = nullptr;
    }
};

node* newGoodTop = nullptr;
node* goodTop = nullptr;
node* goodBottom = nullptr;

node* newBadTop = nullptr;
node* badTop = nullptr;
node* badBottom = nullptr;

/* ----- Bad & Good Pop for Linked List ----- */
// Bad Pop has to Iterate Through the Whole List Before Popping From Stack
int LLPopBad() {
    // If the top is a nullptr, Then the Stack is Empty
    if (badTop == nullptr) {
        std::cout << "Bad Linked List Stack empty\n";
        return -1;
    }
    // If the top of the Stack is the Same as the Bottom, There is Only one Node, Then pop it
    if (badTop == badBottom) {
        int data = badTop->data;
        delete badTop;
        badTop, badBottom = nullptr;
        return data;
    }

    int data = badTop->data;
    node* tp = badBottom;
    //Iterate Through the Linked List to Find the top of the Stack
    while (tp->next != badTop) {
        tp = tp->next;
    }// end while

    //Pop the top From the Stack
    delete tp->next;
    badTop = tp;
    tp->next = nullptr;

    return data;
}

// Good pop Since, Iteration Isn't Needed
int LLPopGood() {
    // If the top is a nullptr, Then the Stack is Empty
    if (goodTop == nullptr) {
        std::cout << "Good Stack is empty. Cannot pop from an empty stack.\n";
        return -1;
    }

    // Pop the top From the Stack
    node* tp = goodTop;
    goodTop = tp->next;
    int data = tp->data;
    delete tp;

    //std::cout << "Popped LL Goodly: " << e << "\n";
    return data;
}

/* ----- Bad & Good Push for Linked List ----- */
// Bad pop Since, it Make Popping Linear Complexity
void LLPushBad(int data) {
    newBadTop = new node(data);
    // If the top is Null, Then set the Newly Created Node to the new top
    if (badTop == nullptr) {
        badTop = newBadTop;
        badBottom = newBadTop;
    // Set the top's Pointer to the Newly Created Node, Then set it to the new top
    } else {
        badTop->next = newBadTop;
        badTop = newBadTop;
    }
}

// Good Push Since it Pushed the new Nodes to the Start of the Linked Making the Complexity - Constant
void LLPushGood(int data) { //pushes new elements at the start of the linked list. Turns the good pop into constant time O(1) since the program will not have to traverse the whole list to pop
    newGoodTop = new node(data);
    newGoodTop->next = goodTop;
    goodTop = newGoodTop;
}

void outputSinglyLinkedList(node*& head) {
    node* tp = head;
    // Iterate Through the Head and Output its Data
    while (tp) {
        std::cout << tp->data << " -> ";
        tp = tp->next;
    }// end while
}

int main() {
    using namespace std::chrono;// Using the Chrono Module to Time the Pushes & Pops
    int sizes[] = { 10, 100, 1000, 10000, 100000 };

    //Iterate Through the sizes Array
    for (int size : sizes) {
        goodTop = nullptr;
        goodBottom = nullptr;
        newGoodTop = nullptr;

        newBadTop = nullptr;
        badTop = nullptr;
        badBottom = nullptr;

        // ---------- Bad Push Timing ----------
        std::cout << "Pushes" << std::endl;
        auto StartOfBadPush = steady_clock::now();
        // Use the Bad Push Method to Push 'size' Elements
        for (int i = 0; i < size; ++i) {
            LLPushBad(i);
        }//end for
        auto EndOfBadPush = steady_clock::now();
        auto TimeBadPush = duration_cast<microseconds>(EndOfBadPush - StartOfBadPush).count();
        std::cout << "Bad Push Duration for: " << size << " Elements is: " << TimeBadPush << " Microseconds" << std::endl;

        // ---------- Good Push Timing ----------
        auto StartOfGoodPush = steady_clock::now();
        // Use the Good Push Method to Push 'size' Elements
        for (int i = 0; i < size; ++i) {
            LLPushGood(i);
        }//end for
        auto EndOfGoodPush = steady_clock::now();
        auto TimeGoodPush = duration_cast<microseconds>(EndOfGoodPush - StartOfGoodPush).count();
        std::cout << "Good Push Duration for: " << size << " Elements is: " << TimeGoodPush << " Microseconds" << std::endl << std::endl;

        // ---------- Bad Pop Timing ----------
        std::cout << "Pops" << std::endl;
        auto StartOfBadPop = steady_clock::now();
        // Use the Bad pop Method to pop 'size' Elements
        for (int i = 0; i < size; ++i) {
            LLPopBad();
        }// end for
        auto EndOfBadPop = steady_clock::now();
        auto TimeBadPop = duration_cast<microseconds>(EndOfBadPop - StartOfBadPop).count();
        std::cout << "Bad Pop Duration for: " << size << " Elements is: " << TimeBadPop << " Microseconds" << std::endl;
        
        // ---------- Good Pop Timing ----------
        auto StartOfGoodPop = steady_clock::now();
        for (int i = 0; i < size; ++i) {
            LLPopGood();
        }// end for
        auto EndOfGoodPop = steady_clock::now();
        auto TimeGoodPop = duration_cast<microseconds>(EndOfGoodPop - StartOfGoodPop).count();
        std::cout << "Good Pop Duration for: " << size << " Elements is: " << TimeGoodPop << " Microseconds" << std::endl << std::endl << std::endl;

        newGoodTop = nullptr;
    }// end foreach
}
