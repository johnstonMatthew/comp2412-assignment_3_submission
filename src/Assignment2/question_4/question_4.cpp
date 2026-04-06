#include <iostream>
#include <algorithm>
#include "question_4.hpp"

// ------ a) ------
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

int UpdateNode(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    root->bf = UpdateNode(root->left) - UpdateNode(root->right);
    root->height = std::max(UpdateNode(root->left), UpdateNode(root->right)) + 1;

    return root->height;
}

Node* LeftRotation(Node* root) {
    Node* tp = root->right;
    root->right = tp->left;
    tp->left = root;
    root = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return root;
}

Node* RightRotation(Node* root) {
    Node* tp = root->left;
    root->left = tp->right;
    tp->right = root;
    root = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return root;
}

Node* LeftRightRotation(Node* root) {
    Node* tp = root->right;
    root->right = tp->left;
    root->right->right = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return RightRotation(root);
}

Node* RightLeftRotation(Node* root) {
    Node* tp = root->left;
    root->left = tp->right;
    tp->left->left = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return LeftRotation(root);
} 

Node* Insert(int value, Node* root) {
    if (root == nullptr) {
        Node* tp = new Node(value);

        root = tp;

        std::cout << "BF at New Node - " << "Height: " << root->height << " BF: " << root->bf << std::endl;
        return root;
    }

    if (value < root->data) {
        root->left = Insert(value, root->left);
    } else if (value > root->data) {
        root->right = Insert(value, root->right);
    }

    UpdateNode(root);

    if (root->bf < -1 && root->right->bf <= 0) {
        std::cout << "Left Rotation: " << std::endl;
        root = LeftRotation(root);

    } else if (root->bf > 1 && root->left->bf >= 0) {
        std::cout << "Right Rotation: " << std::endl;
        root = RightRotation(root);

    } else if (root->bf > 1 && root->left->bf < 0) {
        std::cout << "Left-Right Rotation: " << std::endl;
        root = LeftRightRotation(root);

    } else if (root->bf < -1 && root->right->bf > 0) {
        std::cout << "Right-Left Rotation: " << std::endl;
        root = RightLeftRotation(root);
    }

    std::cout << "Balance Correction at Node(" << root->data << ") - " << "Height: " << root->height << " BF : " << root->bf << std::endl;

    return root;
}

// ------ c) ------
void InOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversal(root->left);
    std::cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    // ------ b) ------
    int sequenceOne[] = { 14, 17, 11, 7, 53, 4, 13 };
    int sequenceTwo[] = { 40, 20, 60, 10, 30, 50, 70 };

    Node* rootOne = nullptr;
    Node* rootTwo = nullptr;

    std::cout << "First Sequence of Numbers" << std::endl;
    for (int num : sequenceOne) {
        std::cout << "Inserted: " << num << std::endl;
        rootOne = Insert(num, rootOne);
        InOrderTraversal(rootOne);
        std::cout << std::endl << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Second Sequence of Numbers" << std::endl;
    for (int num : sequenceTwo) {
        std::cout << "Inserted: " << num << std::endl;
        rootTwo = Insert(num, rootTwo);
        InOrderTraversal(rootTwo);
        std::cout << std::endl << std::endl;
    }

    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    InOrderTraversal(rootOne);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    InOrderTraversal(rootTwo);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    PreOrderTraversal(rootOne);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    PreOrderTraversal(rootTwo);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    PostOrderTraversal(rootOne);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    PostOrderTraversal(rootTwo);
    std::cout << std::endl << std::endl;
}
