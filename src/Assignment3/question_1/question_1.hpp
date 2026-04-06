#ifndef QUESTION_1_HPP
#define QUESTION_1_HPP

#include <iostream>

typedef struct AVLNode {
    int value;
    struct Node* left;
    struct Node* right;
} AVLNode;

// Function prototypes
void InsertionSort(int array[], int arraySize);
int* MergeArray(int array[], int array2[], int arraySize, int array2Size);
void MergeSort(int array[], int arraySize);
AVLNode* createNode(int value);
int updateHeightBF(AVLNode* node);
void rotationUpdater(AVLNode* node, AVLNode* tp);

void PreOrderTraversal(Node* root);
void InOrderTraversal(Node* root);
void PostOrderTraversal(Node* root);

AVLNode* leftRotation(AVLNode* node);
AVLNode* rightRotation(AVLNode* node);
AVLNode* leftRightRotation(AVLNode* node);
AVLNode* rightLeftRotation(AVLNode* node);
AVLNode* rotationHelper(AVLNode* node);
AVLNode* AVLInsert(AVLNode* root, int value);
void AVLSort(int arr[], int size);

#endif