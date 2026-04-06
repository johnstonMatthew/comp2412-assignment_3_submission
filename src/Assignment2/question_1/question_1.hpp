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

#endif