#include <string>

//Node for linked list (for the separate chaining)
struct Node {
    std::string key;
    int value;
    Node* next;

    Node(std::string k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {

    private:
        //Properties
	    Node** Table;
	    int m, n;

        // Functions Needed for HashTable Functionality
        int Hash(std::string key);
        float GetLoadFactor();
        bool Resize(int newM);

    public:
        // Constructor and Destructor
        HashTable(int initialM);
        ~HashTable();

        bool Insert(std::string key, int value);
        int Search(std::string key);
        void Remove(std::string key);
        void Display();
};

