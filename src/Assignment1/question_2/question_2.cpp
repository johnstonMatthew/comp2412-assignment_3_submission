#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Node Structure
struct node {
    int data;
    struct node* next;

    node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Time Complexity: Linear - Θ(n) [Θ(1) + Θ(n) => Θ(n)]
void insertNode (node*& head, int newData) {

    if (head == nullptr) {// If the Head Parameter is null
        node* tp = new node(newData);// Create new Node, With the newData Parameter
        head = tp;// Set the Head Parameter to the Newly Created Node

        return;
    } 

    node* tp = head;// Set a Temporary Point to the Head Parameter, if Head isn't Null

    while (tp->next) {// While the Temporary Point, Pointer Towards Another Node, Continue Loop
        tp = tp->next;// Set tp to the Next Pointer in the Linked List
    }//end while

    tp->next = new node(newData);// Set the Pointer of the Last Node in the Linked List to a Newly Created Node Using newData

    return;
}

// Time Complexity: Θ(n): due to Loop
void outputSinglyLinkedList (node*& head) {
    node* tp = head;

    if (tp == nullptr) {//If tp is Null, Meaning There is no Linked List
        std::cout << "Linked List is Null" << std::endl;
    } else {//If There is a Minimum of 1 Node in the Linked List
        while (tp) {// Traverse to End of List
            std::cout << tp->data << " -> ";// Output the Node at the Current Iteration's Data
            tp = tp->next;// Set tp to its Next Pointer
        }//end while
    }
}

// Time Complexity: Θ(n): due to Loop
node* reverseLinkedList (node*& head) {
    // Set the Pointer Needed to Reverse the Linked List
    node* previous = nullptr;
    node* current = head;
    node* next = nullptr;


    while (current) {//While the Current Pointer has a Value to Point to
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }// end while

    return previous;
}

int main () {
    string input = "";
    
    node* head = nullptr;

    std::cout << " Enter elements to insert into the linked list (type 'done' to finish): " << std::endl;

    while (input != "done") {// While the User Doesn't Enter 'done'
        std::cin >> input;
        std::cout << std::endl;

        if (input == "done") {
            break;
        }

        insertNode(head, stoi(input) ); 
    }// end while

    outputSinglyLinkedList(head);

    std::cout << std::endl;

    head = reverseLinkedList(head);

    outputSinglyLinkedList(head);  
}

