#include <iostream>
#include <string>

//Structure of the ListNode
class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

// Time Complexity: Linear - Θ(n) [Θ(1) + Θ(n) => Θ(n)]
ListNode* createSortedLinkedList() {
    ListNode* head = nullptr;
    std::string input = "";

    while (true) {// While the User Wants to Continue
        std::cout << "Please enter a number to insert into the list (enter 'done' to stop): ";
        std::cin >> input;

        if (input == "done") {// If the Users Wants to Stop Adding Numbers
            break;
        }

        try {// Try the Code Within,
            ListNode* newNode = new ListNode(stoi(input));

        } catch (...) {// If any Exceptions are Found, Perform Code Within
            std::cout << "Input Must be a Numerical Value" << std::endl;
            continue;
        }

        ListNode* newNode = new ListNode(stoi(input));

        //If the head is hull or the Current Input is Smaller Than the Head's Value
        if (head == nullptr || stoi(input) < head->value) {
            // Put the Newly Created Node Before the Head
            newNode->next = head;
            head = newNode;
        } else {
            ListNode* tp = head;

            /* Continue While There is Another Pointer is the Current Iteration AND 
            if the Current Iteration's Value is Less Than the Input */
            while (tp->next != nullptr && tp->next->value < stoi(input)) {
                tp = tp->next;// Set tp to What it Points to
            }//end while
            // Add newNode at the End
            newNode->next = tp->next;// Set the Next Point to What tp Currently Points to
            tp->next = newNode;// Set tp's Current Pointer to the Newly Created Node
        }
    }// end while

    return head;
}

// Time Complexity: Linear - Θ(n)
void printLinkedList(ListNode* head) {
    ListNode* tp = head;
    while (tp != nullptr) {
        std::cout << tp->value << " ";
        tp = tp->next;
    }//end while
}

// Time Complexity: Quadratic - Θ(n^2) [Θ(n^2) + Θ(n^2) => Θ(n^2)]
ListNode* mergeSortedLists(ListNode* list1, ListNode* list2) {
    ListNode* head = nullptr;

    // Continue While the list1 Parameter Hasn't Been Iterated to a nullptr
    while (list1 != nullptr) {
        ListNode* newNode = new ListNode(list1->value);

        //If the head is hull or the Current Input is Smaller Than the Head's Value
        if (head == nullptr || newNode->value < head->value) {
            // Put the Newly Created Node Before the Head
            newNode->next = head;
            head = newNode;
        } else {
            ListNode* tp = head;// Set the Head to a Temporary Pointer

            /* Continue While tp Hasn't Been Iterted to a nullptr AND
               While what tp Points to's Value is Less Than the Newly Created Node's Value*/
            while (tp->next != nullptr && tp->next->value < newNode->value) {
                tp = tp->next;
            }// end while

            // Add newNode at the End
            newNode->next = tp->next;
            tp->next = newNode;
        }

        list1 = list1->next;
    }// end while

    //Same Steps as Above but With the list2 Parameter
    while (list2 != nullptr) {
        ListNode* newNode = new ListNode(list2->value);

        if (head == nullptr || newNode->value < head->value) {
            newNode->next = head;
            head = newNode;
        } else {
            ListNode* tp = head;

            while (tp->next != nullptr && tp->next->value < newNode->value) {
                tp = tp->next;
            }// end while

            newNode->next = tp->next;
            tp->next = newNode;
        }

        list2 = list2->next;
    }//end while
    return head;
}

int main() {
    std::cout << "Create first Linked List:" << std::endl;
    ListNode* list1 = createSortedLinkedList();
    std::cout << std::endl;

    std::cout << "Create second Linked List:" << std::endl;
    ListNode* list2 = createSortedLinkedList();
    std::cout << std::endl;

    std::cout << "Sorted Merged List:" << std::endl;
    ListNode* sortedMergedList = mergeSortedLists(list1, list2);
    printLinkedList(sortedMergedList);
}