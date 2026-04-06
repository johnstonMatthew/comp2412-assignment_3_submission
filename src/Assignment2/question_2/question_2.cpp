#include <iostream>
#include "question_2.hpp"

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// ----- Insert, Search and Traversals From question_1 -----
Node* Insert(int data, Node* root) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->value = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        root = newNode;
        return root;
    }

    if (data < root->value) {
        root->left = Insert(data, root->left);
    } else if (data > root->value) {
        root->right = Insert(data, root->right);
    }

    return root;
}

Node* Search(int searchValue, Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (searchValue == root->value) {
        return root;
    } else if (searchValue < root->value) {
        return Search(searchValue, root->left);
    } else if (searchValue > root->value) {
        return Search(searchValue, root->right);
    }

    return nullptr;
}

void InOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    InOrderTraversal(root->left);
    std::cout << root->value << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    std::cout << root->value << " ";
}


// Helper Functions
Node* ReturnParent(int searchValue, Node* parentNode, Node* currentNode) {
    if (searchValue == currentNode->value) {
        return parentNode;
    } else if (searchValue < currentNode->value) {
        return ReturnParent(searchValue, currentNode, currentNode->left);
    } else if (searchValue > currentNode->value) {
        return ReturnParent(searchValue, currentNode, currentNode->right);
    }

    return nullptr;
}

bool IsChildValueGreater(int parentValue, int childValue) {
    if (parentValue < childValue) {
        return true;
    } else {
        return false;
    }
}

// ----- a) -----
int Delete(int value, Node* root) {
    if (root == nullptr || Search(value, root) == nullptr) {
        return -1;
    }

    Node* toBeDeletedNode = Search(value, root);
    Node* parentNode = ReturnParent(value, root, root);

    //If the Node is a Leaf Node
    if (toBeDeletedNode->left == nullptr && toBeDeletedNode->right == nullptr) {
        std::cout << "Node is a Leaf Node" << std::endl;
        if (IsChildValueGreater(parentNode->value, toBeDeletedNode->value) ) {
            parentNode->right = nullptr; 
        } else {
            parentNode->left = nullptr;
        }

        delete toBeDeletedNode;
        return value;
    } 
    //If the Node has 2 Children
    if (toBeDeletedNode->left != nullptr && toBeDeletedNode->right != nullptr) {
        std::cout << "Node has 2 Children" << std::endl;
        Node* newRoot = toBeDeletedNode->left; 

        newRoot->right = toBeDeletedNode->right;

        if (IsChildValueGreater(parentNode->value, toBeDeletedNode->value)) {
            parentNode->right = newRoot;
        } else {
            parentNode->left = newRoot;
        }

        delete toBeDeletedNode;
        return value;
    }
    //If the Node has 1 Child
    if (toBeDeletedNode->left != nullptr) {
        std::cout << "Node has 1 Children" << std::endl;
        if (IsChildValueGreater(parentNode->value, toBeDeletedNode->value)) {
            parentNode->right = toBeDeletedNode->left;
        } else {
            parentNode->left = toBeDeletedNode->left;
        }
        delete toBeDeletedNode;
        return value;
    } else if (toBeDeletedNode->right != nullptr) {
        std::cout << "Node has 1 Children" << std::endl;
        if (IsChildValueGreater(parentNode->value, toBeDeletedNode->value)) {
            parentNode->right = toBeDeletedNode->right;
        } else {
            parentNode->left = toBeDeletedNode->right;
        }

        delete toBeDeletedNode;
        return value;
    }
}

// ----- b) -----
// --- i ---
Node* InsertNodes(Node* root) {
    int numbers[] = {55, 40, 65, 30, 45, 60, 70, 42, 50, 58, 62};

    for (int num : numbers) {
        root = Insert(num, root);
    }

    return root;
}

// ----- c) -----
// --- i ---
Node* FindMinimum(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// --- ii ---
Node* FindMaximum(Node* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

int main() {
    Node* root = nullptr;

    root = InsertNodes(root);

    InOrderTraversal(root);

    std::cout << std::endl << std::endl;

    Delete(40, root);

    InOrderTraversal(root);

    std::cout << std::endl << std::endl;

    Delete(45, root);

    InOrderTraversal(root);

    std::cout << std::endl << std::endl;

    Delete(30, root);

    InOrderTraversal(root);

    std::cout << std::endl << std::endl;
}
