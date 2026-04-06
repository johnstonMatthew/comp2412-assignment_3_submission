#include <iostream>
#include <vector>
#include "Queue.h"

void DisplayGraph1(Queue queue) {
    std::cout << "Graph 1 Pop Sequence: " << std::endl;

    std::vector<std::vector<int>> adj(10);
    std::vector<bool> visited(10, false);

    adj[0] = { 2, 3, 4 };
    adj[1] = { 4, 5 };
    adj[2] = { 0, 3, 5 };
    adj[3] = { 0, 2 };
    adj[4] = { 0, 1, 5 };
    adj[5] = { 1, 2, 4 };
    adj[6] = { 7, 9 };
    adj[7] = { 6, 8 };
    adj[8] = { 7, 9 };
    adj[9] = { 6, 9 };

    std::cout << "Graph 1 Pop Sequence (DFS): ";
    queue.DFS(0, adj, visited);
    std::cout << std::endl;

    std::vector<bool> visitedDequeue(10, false);
    std::cout << "Graph 1 Dequeue Sequence (BFS): ";
    queue.BFS(0, adj, visitedDequeue);
    std::cout << std::endl << std::endl; 
}

void DisplayGraph2(Queue queue) {
    std::cout << "Graph 2 Pop Sequence: " << std::endl;

    std::vector<std::vector<int>> adj(8);
    std::vector<bool> visited(8, false);

    adj[0] = { 1, 4 };
    adj[1] = { 0, 2, 5 };
    adj[2] = { 1, 3, 6 };
    adj[3] = { 2, 7 };
    adj[4] = { 0, 5 };
    adj[5] = { 1, 4, 6 };
    adj[6] = { 2, 5, 7 };
    adj[7] = { 3, 6 };

    std::cout << "Graph 2 Pop Sequence (DFS): ";
    queue.DFS(0, adj, visited);
    std::cout << std::endl;

    std::vector<bool> visitedDequeue(8, false);
    std::cout << "Graph 2 Dequeue Sequence (BFS): ";
    queue.BFS(0, adj, visitedDequeue);
    std::cout << std::endl << std::endl;
}

void DisplayGraph3(Queue queue) {
    std::cout << "Graph 3 Pop Sequence: " << std::endl;

    std::vector<std::vector<int>> adj(7);
    std::vector<bool> visited(7, false);

    adj[0] = { 1, 2, 3, 4 };
    adj[1] = { 0, 3, 5 };
    adj[2] = { 0, 6 };
    adj[3] = { 0, 1, 5 };
    adj[4] = { 0, 6 };
    adj[5] = { 1, 3 };
    adj[6] = { 2, 4 };

    std::cout << "Graph 3 Pop Sequence (dfs): ";
    queue.DFS(0, adj, visited);
    std::cout << std::endl;

    std::vector<bool> visitedDequeue(7, false);
    std::cout << "Graph 3 Dequeue Sequence (BFS): ";
    queue.BFS(0, adj, visitedDequeue);
    std::cout << std::endl << std::endl;
}

void DisplayGraph4(Queue queue) {
    std::cout << "Graph 4 Pop Sequence: " << std::endl;

    std::vector<std::vector<int>> adj(4);
    std::vector<bool> visited(4, false);

    adj[0] = { 2 };
    adj[1] = { 0 };
    adj[2] = { 1, 3 };
    adj[3] = { 0 };

    std::cout << "Graph 4 Pop Sequence (DFS): ";
    queue.DFS(0, adj, visited);
    std::cout << std::endl;

    std::vector<bool> visitedDequeue(4, false);
    std::cout << "Graph 4 Dequeue Sequence (BFS): ";
    queue.BFS(0, adj, visitedDequeue);
    std::cout << std::endl << std::endl;
}

int main() {
    Queue queue = Queue();

    DisplayGraph1(queue);
    DisplayGraph2(queue);
    DisplayGraph3(queue);
    DisplayGraph4(queue);
}