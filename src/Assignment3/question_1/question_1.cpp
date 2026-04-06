#include <iostream>
// Helper Functions
void PrintArray (int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }// end for
}

// a) => See Complementary Answers

// b) => See Complementary Answers

// Function for an Insertion Sort
void InsertionSort(int array[], int arraySize) {
    // if the Array can be Sorted (i.e: Array has Elements)
    if (arraySize > 0) {
        // Iterate Through the Array
        for (int i = 1; i < arraySize; i++) {
            int x = array[i];// Set 'x' to the 'key'
            int j = i - 1;

            //Continue Looping While 'j' is Equal to or Greater to Zero and Greater Than the key
            while (j >= 0 && array[j] > x) {
                //Swap the Elements
                array[j + 1] = array[j];
                j = j - 1;// Decrement j
            }// end while

            array[j + 1] = x;
        }//end for
    }
}

// Function to Merge the Elements of 2 Arrays
int* MergeArray(int array[], int array2[], int arraySize, int array2Size) {
    int mergedSize = arraySize + array2Size;
    int* merged = new int[mergedSize];

    // Variables for Indexes and Iteration
    int arrayIndex = 0, array2Index = 0, k = 0;

    //While Either Index Isn't Out of Bounds
    while (arrayIndex < arraySize && array2Index < array2Size) {
        // If the Current Element of Array1 is Less or Equal to the Current Element of Array2. Add the Lesser Element First
        if (array[arrayIndex] <= array2[array2Index]) {
            // Add the Element of Array1 at the Current Iteration to the Merged Array, Increment k
            merged[k] = array[arrayIndex];
            arrayIndex++;
            k++;
        } else {
            // Add the Element of Array2 at the Current Iteration to the Merged Array, Increment k
            merged[k] = array2[array2Index];
            array2Index++;
            k++;
        }
    }// end while

    //Continue While the Index is Within the Bounds of Array1
    while (arrayIndex < arraySize) {
        // Add the Remaining Elements to the Merged Array
        merged[k] = array[arrayIndex];
        arrayIndex++;
        k++;
    }// end while

    //Continue While the Index is Within the Bounds of Array2
    while (array2Index < array2Size) {
        // Add the Remaining Elements to the Merged Array
        merged[k] = array2[array2Index];
        array2Index++;
        k++;
    }// end while

    return merged;
}

// Function to Merge Sort
void MergeSort(int array[], int arraySize) {
    // If the Array has Elements to Sort
    if (arraySize <= 1) {
        return;
    }

    // Variables for Array Size
    int leftSize = arraySize / 2;
    int rightSize = arraySize - leftSize;

    
    int* leftHalf = new int[leftSize];
    int* rightHalf = new int[rightSize];

    // Iterate Through Half of the Array Parameter
    for (int i = 0; i < leftSize; i++) {
        leftHalf[i] = array[i];
    }

    // Iterate Through the Other Half of the Array Parameter
    for (int i = 0; i < rightSize; i++) {
        rightHalf[i] = array[i + leftSize];
    }

    //Call the MergeSort() Function on Each Half to Repeat the Above Process
    MergeSort(leftHalf, leftSize);
    MergeSort(rightHalf, rightSize);

    // Merge the Half Arrays Into a Whole Array
    int* merged = MergeArray(leftHalf, rightHalf, leftSize, rightSize);

    // Iterate Through the Merged Array to put Them Back Into the Original Array
    for (int i = 0; i < arraySize; i++) {
        array[i] = merged[i];
    }
}

// Struct for AVLNode
struct AVLNode {
    int value;
    int bf;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};

// Function to Create a new AVLNode
AVLNode* createNode(int value) {
    AVLNode* newNode = new AVLNode();
    newNode->value = value;
    newNode->bf = 0;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to Update the Height and Balance Factor a an AVLNode
int updateHeightBF(AVLNode* node) {
    //If the AVLNode is Null, There is no Information to Update
    if (node == nullptr) {
        return 0;
    }

    node->bf = updateHeightBF(node->left) - updateHeightBF(node->right);
    node->height = std::max(updateHeightBF(node->left), updateHeightBF(node->right)) + 1;

    return node->height;
}

// Function to Update the AVL Information of a Node and a Temporary Pointer
void rotationUpdater(AVLNode* node, AVLNode* tp) {
    updateHeightBF(node);
    updateHeightBF(tp);
}

// Function to Output a PreOrder Traversal
void traversePreOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

// Function to Output an InOrder Traversal
void traverseInOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    std::cout << root->value << " ";
    traverseInOrder(root->right);
}

// Function to Perform a Left Rotation on a Subtree
AVLNode* leftRotation(AVLNode* node) {
    std::cout << "Before Left Rotation: ";
    traversePreOrder(node);
    std::cout << std::endl;

    AVLNode* tp = node->right;
    node->right = tp->left;
    tp->left = node;

    rotationUpdater(node, tp);

    std::cout << "After Left Rotation: ";
    traversePreOrder(tp);
    std::cout << std::endl << std::endl;

    return tp;
}

// Function to Perform a Right Rotation on a Subtree
AVLNode* rightRotation(AVLNode* node) {
    std::cout << "Before Right Rotation: ";
    traversePreOrder(node);
    std::cout << std::endl;

    AVLNode* tp = node->left;
    node->left = tp->right;
    tp->right = node;

    rotationUpdater(node, tp);

    std::cout << "After Right Rotation: ";
    traversePreOrder(tp);
    std::cout << std::endl << std::endl;

    return tp;
}

// Function to Perform a LeftRight Rotation on a Subtree
AVLNode* leftRightRotation(AVLNode* node) {
    node->left = leftRotation(node->left);
    return rightRotation(node);
}

// Function to Perform a RightLeft Rotation on a Subtree
AVLNode* rightLeftRotation(AVLNode* node) {
    node->right = rightRotation(node->right);
    return leftRotation(node);
}

// Function That Decides What Rotation to Perform
AVLNode* rotationHelper(AVLNode* node) {
    // Left Rotation
    if (node->bf < -1 && node->right->bf <= 0) {
        return leftRotation(node);
    }

    // LeftRight Rotation
    if (node->bf > 1 && node->left->bf < 0) {
        return leftRightRotation(node);
    }

    // RightLeft Rotation
    if (node->bf < -1 && node->right->bf > 0) {
        return rightLeftRotation(node);
    }

    // Right Rotation
    if (node->bf > 1 && node->left->bf >= 0) {
        return rightRotation(node);
    }

    return node;
}

// Function to Insert a new Node Into an AVLTree
AVLNode* AVLInsert(AVLNode* root, int value) {
    // If the Current Root is Null, Meaning There is Further Node, Create a new Node
    if (root == nullptr) {
        return createNode(value);
    }

    // If the Value Attempting to be Inserted is Already Within the Tree. Return the Root of the Tree
    if (root->value == value) {
        return root;
    }

    // If the Value Being Inserted is Less Than the Current Roots Value, Iterate to the Right 
    if (value > root->value) {
        root->right = AVLInsert(root->right, value);
    // If the Value Being Inserted is Less Than the Current Roots Value, Iterate to the Left 
    } else if (value < root->value) {
        root->left = AVLInsert(root->left, value);
    }

    updateHeightBF(root);
    return rotationHelper(root);
}

// Function to Perform an AVLSort
void AVLSort(int arr[], int size) {
    AVLNode* root = nullptr;

    // Iterate Through the Array Parameter
    for (int i = 0; i < size; i++) {
        root = AVLInsert(root, arr[i]);
    }// end for

    traverseInOrder(root);
}

int main() {
    int array[] = { 38, 27, 43, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Array Before: " << std::endl;
    PrintArray(array, size);
    std::cout << std::endl;

    std::cout << "Insertion Sorted Array: " << std::endl;
    InsertionSort(array, size);
    PrintArray(array, size);

    std::cout << std::endl << std::endl;

    int array2[] = { 50, 76, 1, 3, 65, 9 };
    int size2 = sizeof(array2) / sizeof(array2[0]);

    std::cout << "Array Before: " << std::endl;
    PrintArray(array2, size2);
        std::cout << std::endl;

    std::cout << "Merge Sorted Array: " << std::endl;
    MergeSort(array2, size2);
    PrintArray(array2, size2);

    std::cout << std::endl << std::endl;

    int array3[] = { 7, 0, 1, 54, 13, 78, 43 };
    int size3 = sizeof(array3) / sizeof(array3[0]);

    std::cout << "Array Before: " << std::endl;
    PrintArray(array3, size3);
    std::cout << std::endl;

    std::cout << "AVL Sorted Array: " << std::endl;
    InsertionSort(array3, size3);
    PrintArray(array3, size3);

    std::cout << std::endl << std::endl;
}