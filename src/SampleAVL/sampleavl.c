#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int bf;
    int count;
    struct node* left;
    struct node* right;
} node;

node * new_node (int data) {
    node *n = (node *) malloc(sizeof(node));
    n->data = data;
    n->bf = 0;
    n->count = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void InOrderTraversal (node* root) {
    if (root != NULL) {
        InOrderTraversal(root->left);
        printf(" %d:%d", root->data, root->bf);
        InOrderTraversal(root->right);
    }
}

node* InsertAVL (node* root, int data) {
    if (root == NULL) {
        node* nn = newNode(data);
        return nn;
    }

    if (root->data == data) {
        root->count++;
        return root;
    }

    if (root->data < data) {
        root->left = InsertAVL(root->left, data);
        return root;
    } else if (root->data > data) {
        root->right = InsertAVL(root->right, data);
        return root;
    }

}

int main () {
    node* root = NULL;

    root = newNode(7);
    node* rightOne = newNode(8);
    node* leftOne = newNode(6);

    InOrderTraversal(root);
    printf(" %s ", '\n');
}
