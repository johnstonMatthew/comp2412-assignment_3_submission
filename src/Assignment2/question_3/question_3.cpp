#include <iostream>
#include <algorithm>
#include "question_3.hpp"

// ------ a) ------
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

void InOrderTraversalPrinting (Node* root) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversalPrinting(root->left);
    std::cout << root->data << " ";
    InOrderTraversalPrinting(root->right);
}

int UpdateNode(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    root->bf = UpdateNode(root->left) - UpdateNode(root->right);
    root->height = std::max(UpdateNode(root->left), UpdateNode(root->right)) + 1;

    return root->height;
}

Node* LeftRotation (Node* root) {
    Node* tp = root->right;
    root->right = tp->left;
    tp->left = root;
    root = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return root;
}

Node* RightRotation (Node* root) {
    Node* tp = root->left;
    root->left = tp->right;
    tp->right = root;
    root = tp;

    UpdateNode(tp);
    UpdateNode(root);

    return root;
}

Node* LeftRightRotation (Node* root) {
    root->left = LeftRotation(root->left);

    UpdateNode(root);

    return RightRotation(root);
}

Node* RightLeftRotation (Node* root) {
    root->right = RightRotation(root->right);

    UpdateNode(root);

    return LeftRotation(root);
}

void TraverseBalanceFactors(Node* root) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversalPrinting(root->left);
    UpdateNode(root);
    InOrderTraversalPrinting(root->right);
}

Node* Insert (int value, Node* root) {
    if (root == nullptr) {
        Node* tp = new Node(value);

        root = tp;

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

    return root;
}

int main(){
// ------ b) ------
    int numbers[] = {10, 20, 30, 40, 50, 25};

    Node* root = nullptr;

    for (int num : numbers) {
        root = Insert(num, root);
        InOrderTraversalPrinting(root);
        std::cout << std::endl;
    }
}
