#include <vector>

class Queue {

    struct Node {
        int value;
        Node* next;

        Node(int v) : value(v), next(nullptr) {}
    };

    private:
        Node* frontPtr;
        Node* backPtr;

    public:
        // Constructor
        Queue() : frontPtr(nullptr), backPtr(nullptr) {}

        // Misc
        bool Empty();
        int Front();

        // Data Manipulation
        void Push(int v);
        void Pop();

        // Traversals
        void DFS(int v, std::vector<std::vector<int>>& adj, std::vector<bool>& visited);
        void BFS(int start, std::vector<std::vector<int>>& adj, std::vector<bool>& visited);   
};

