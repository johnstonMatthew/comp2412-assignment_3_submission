#include <iostream>
#include <algorithm>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    int height;
    int bf;

    Node(int newData) {
        data = newData;
        left = nullptr;
        right = nullptr;
        height = 0;
        bf = 0;
    }
};

int UpdateNode(Node* root);
Node* LeftRotation(Node* root);
Node* RightRotation(Node* root);
Node* LeftRightRotation(Node* root);
Node* RightLeftRotation(Node* root);
Node* Insert(int value, Node* root);
void InOrderTraversal(Node* root);
void PreOrderTraversal(Node* root);
void PostOrderTraversal(Node* root);