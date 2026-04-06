#include <iostream>
#include <string>
#include "HashTable.h"

// Function That Takes a Value and Hashes it to a Slot
int HashTable::Hash(std::string key) {
    int hashValue = 0;

    for (char c : key) {
        hashValue += c;
    }//end for

    return hashValue % m;
}

// Function That Returns the Load Factor
float HashTable::GetLoadFactor() {
    return (float) n / m;
}

// Function That Resizes the Linked Lists Within the HashTable
bool HashTable::Resize(int newM) {
    Node** oldTable = this->Table;
    int oldM = this->m;

    this->Table = new Node * [newM];

    // Iterate Through the Table a set Each Value to an Empty One
    for (int i = 0; i < newM; i++) {
        this->Table[i] = nullptr;
    }// end for

    this->m = newM;// Resize Table
    this->n = 0;

    // Iterate Through the Table and set Each Value Back to its old Value
    for (int i = 0; i < oldM; i++) {
        Node* current = oldTable[i];

        while (current) {
            this->Insert(current->key, current->value);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }// end for

    delete[] oldTable;
    return true;
}

// Constructor
HashTable::HashTable(int initialM = 8) {
    m = initialM;
    n = 0;

    Table = new Node * [m];

    for (int i = 0; i < m; i++) {
        Table[i] = nullptr;
    }// end for
}

//Destructor
HashTable::~HashTable() {
    // Iterate Through the Table, Delete Each Node From Memory.
    for (int i = 0; i < m; i++) {
        Node* current = Table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }// end for
    delete[] Table;// Delete Table Property From Memory
}

// Function to Insert a new Value Within the HashTable
bool HashTable::Insert(std::string key, int value) {
    int index = Hash(key);// Hash the new key

    Node* head = this->Table[index];
    Node* current = head;

    // Iterate Through the Linked List
    while (current) {
        if (current->key == key) {
            current->value = value;
            return true;
        }
        current = current->next;
    }// end while

    Node* newNode = new Node(key, value);
    newNode->next = head;
    this->Table[index] = newNode;
    this->n++;

    // If the Insertion Causes the Load Factor to Exceed our Limit Resize the Table
    if (GetLoadFactor() > 0.75) {
        this->Resize(this->m * 2);
        return this->Search(key) != -1 ? true : false;
    }

    return true;
}

// Function That Finds a key Within the Table and Returns the Value
int HashTable::Search(std::string key) {
    int index = this->Hash(key);

    // If the Hash is Found Within the Table, Continue Looking for Value
    if (this->Table[index] != nullptr) {
        Node* current = this->Table[index];// Set Current to the Head of the Linked List

        do {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;// Iterate
        } while (current);// end while

    }
    return -1;// If Not Found
}

// Function That Removes a key From the HashTable
void HashTable::Remove(std::string key) {
    int index = this->Hash(key);

    // If Hashed Slot Doesn't Exist
    if (Table[index] == nullptr) {
        return;
    }

    // If Hashed Slot/Key Exists Within the Head
    if (this->Table[index]->key == key) {
        Node* ptrnode = this->Table[index]->next;

        // Prevent Memory Leak
        delete this->Table[index];
        this->Table[index] = ptrnode;
        this->n--;

        // If Removable Cause Load Factor to Exceed Limit. Resize
        if (this->GetLoadFactor() < 0.25) {
            this->Resize(this->m / 2);
        }

        return;
    }

    Node* ptrnode = this->Table[index]->next;

    do {// Iterate Through Linked Link to Find Value

        if (ptrnode->next != nullptr && ptrnode->next->key == key) {
            // Prevent Memory Leak
            Node* tp = ptrnode->next;
            ptrnode->next = tp->next;
            delete tp;
            this->n--;

            // If Removable Cause Load Factor to Exceed Limit. Resize
            if (this->GetLoadFactor() < 0.25) {
                this->Resize(this->m / 2);
            }

            return;
        }
        ptrnode = ptrnode->next;
    } while (ptrnode != nullptr);//end while

    return;
}

//Function That Outputs the Content of the HashTable
void HashTable::Display() {
    //Iterate Through Table
    for (int i = 0; i < this->m; i++) {
        std::cout << "Slot " << i << ": ";
        Node* current = this->Table[i];

        if (!current) {
            std::cout << "NULL";
        } else {
            while (current) {// Iterate Through Slot
                std::cout << "(" << current->key << ", " << current->value << ") -> ";
                current = current->next;
            }// end while

            std::cout << "NULL";
        }
        std::cout << std::endl;
    }
}

