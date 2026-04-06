#ifndef QUESTION_1_HPP
#define QUESTION_1_HPP

#include <iostream>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
}Node;

// Function prototypes
Node* Insert(int value, Node* root);
Node* Search(int value, Node* root);

void PreOrderTraversal(Node* root);
void InOrderTraversal(Node* root);
void PostOrderTraversal(Node* root);

Node* ReturnParent(int searchValue, Node* parentNode, Node* currentNode);
bool IsChildValueGreater(int parentValue, int childValue);
int Delete(int value, Node* root);
Node* InsertNodes(Node* root);
Node* FindMinimum(Node* root);
Node* FindMaximum(Node* root);

#endif