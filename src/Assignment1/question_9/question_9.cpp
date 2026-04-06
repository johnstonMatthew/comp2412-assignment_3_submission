#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Structure for a Doubly Linked List (Dequeue) Node
struct node {
	int data;
	struct node* next = nullptr;
	struct node* prev = nullptr;

	node(int new_data) {
		data = new_data;
		next = nullptr;
		prev = nullptr;
	}
};

// Structure for a Doubly Linked List (Dequeue)
struct DoublyLinkedList {
	node* head;
	node* tail;
	DoublyLinkedList(node* implicitHead, node* implicitTail) {
		head = implicitHead;
		tail = implicitTail;
	}
};

DoublyLinkedList createDoubleLinkedList(const std::string& str) {
	node* head = nullptr;
	node* tail = nullptr;

	for (char character : str) {//Iterate Through the String Parameter
		if (!(std::isalnum(character))){
			continue;
		}

		node* newNode = new node(std::tolower(character));// Ensure the Capitals Don't Matter

		// If the Head of the DoublyLinkedList is Null, Both the Head and Tail are the Newly Created Node
		if (head == nullptr) {
			head = tail = newNode;
		// If not, add Create a new Node and Point the Tail to it.
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}// end foreach
	return DoublyLinkedList(head, tail);
}

bool isPalindrome(const std::string& str) {
	node* head = nullptr;
	node* tail = nullptr;
	DoublyLinkedList dll = createDoubleLinkedList(str);

	// Set a Pointer to the Head and Tail
	node* currentLeft = dll.head;
	node* currentRight = dll.tail;

	// If Either Pointers are nullptr, Then the String Cannot be a Palindrome
	if (currentLeft == nullptr || currentRight == nullptr) {
		return false;
	}

	//While currentLeft can be Iterated Trough (i.e: currentLeft->next != null)
	while (currentLeft) {
		// Since Palindromes Need to Have the Same on Each Side if They Don't, Then Return False
		if (currentLeft->data != currentRight->data) {
			return false;
		}

		// Iterate to the Next Pointer of the Current Pointers
		currentLeft = currentLeft->next;
		currentRight = currentRight->prev;
	}// end while

	return true;
}

int main() {
	std::string input;
	std::cout << "Enter a string: ";
	std::getline(std::cin, input);

	if (isPalindrome(input)) {
		std::cout << "The Entered String is a Palindrome.\n";
	} else {
		std::cout << "The Entered String is not a Palindrome.\n";
	}

	return 0;
}