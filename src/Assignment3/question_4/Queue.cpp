#include <iostream>
#include <vector>
#include "Queue.h"

// Function to Return Whether the Queue is Empty
bool Queue::Empty() {
    return frontPtr == nullptr;
}

// Function to add an Element to the Queue
void Queue::Push(int v) {
    Node* newNode = new Node(v);

    // If the Queue is Empty, add the new Node to the Start
    if (Empty()) {
        frontPtr = backPtr = newNode;
    // Add the new Node to the After the Back Pointer, Then Move the Back Pointer
    } else {
        backPtr->next = newNode;
        backPtr = newNode;
    }
}

// Function to Return the First Element of the Queue
int Queue::Front() {
    return frontPtr->value;
}

// Function to Remove an Element From the Queue
void Queue::Pop() {
    // If the Queue is Empty There is no Element to pop
    if (Empty()) return;

    // Prevent Memory Leak
    Node* temp = frontPtr;
    frontPtr = frontPtr->next;
    delete temp;

    // If the Front Pointer is Null, Then the Back is too. Since the Array is now Empty
    if (frontPtr == nullptr) {
        backPtr = nullptr;
    }
}

// Function That Performs a DFS Traversal
void Queue::DFS(int v, std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[v] = true;

    //Iterate Through Each Adjecent List Segment
    for (int node : adj[v]) {
        // If That Node Hasn't Been Visited, Call the DFS Traversal Method With Said Node
        if (!visited[node]) {
            DFS(node, adj, visited);
        }
    }// end for

    std::cout << char('a' + v) << " ";
}

// Function That Performs a BFS Traversal
void Queue::BFS(int start, std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    Queue bfsQueue;

    bfsQueue.Push(start);
    visited[start] = true;

    // Continue Looping While Queue Isn't Empty
    while (!bfsQueue.Empty()) {
        int v = bfsQueue.Front();
        bfsQueue.Pop();

        std::cout << char('a' + v) << " ";

        //Iterate Through Each Adjecent List Segment
        for (int node : adj[v]) {
            // If That Node Hasn't Been Visited, set it to Visited and Push it to the Queue
            if (!visited[node]) {
                visited[node] = true;
                bfsQueue.Push(node);
            }
        }// end for
    }// end while
}