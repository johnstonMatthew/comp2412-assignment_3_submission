#include "question_1.hpp"

Node* Insert (int data, Node* root) {
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
// ----- b) -----
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

int main() {
    int firstSequence[7] = {15, 10, 20, 8, 12, 17, 25};
    int secondSequence[7] = {50, 30, 70, 20, 40, 60, 80};

    Node* firstRoot = nullptr;
    Node* secondRoot = nullptr;

    for (int num : firstSequence) {
        firstRoot = Insert(num, firstRoot);
    }//end foreach

    for (int num : secondSequence) {
        secondRoot = Insert(num, secondRoot);
    }//end foreach


    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    InOrderTraversal(firstRoot);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    InOrderTraversal(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    PreOrderTraversal(firstRoot);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    PreOrderTraversal(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    PostOrderTraversal(firstRoot);
    std::cout << std::endl << std::endl;
    std::cout << "Second Sequence: ";
    PostOrderTraversal(secondRoot);
    std::cout << std::endl << std::endl;
}
