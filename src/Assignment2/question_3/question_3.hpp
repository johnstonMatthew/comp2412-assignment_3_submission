#include <iostream>
#include <algorithm>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    int height;
    int bf;

    Node (int newData) {
        data = newData;
        left = nullptr;
        right = nullptr;
        height = 0;
        bf = 0;
    }
};

void InOrderTraversalPrinting (Node* root);
int UpdateNode(Node* root);
Node* LeftRotation (Node* root);
Node* RightRotation (Node* root);
Node* LeftRightRotation (Node* root);
Node* RightLeftRotation (Node* root);
void TraverseBalanceFactors(Node* root);
Node* Insert (int value, Node* root);