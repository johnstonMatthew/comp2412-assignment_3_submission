#include <iostream>

class CircularQueue {
private:
    int front, rear, queueSize;
    int* array;

public:
    CircularQueue(int size) {
        this->queueSize = size;
        this->array = new int[queueSize];
        this->front = -1;
        this->rear = -1;
    }

    void Enqueue(int element) {
        if (this->CheckFull()) {
            std::cout << "Full Queue, cannot enqueue " << element << std::endl;
            return;
        }
        if (this->CheckEmpty()) {
            this->front = this->rear = 0;
        } else {
            this->rear = (this->rear + 1) % this->queueSize;
        }
        this->array[this->rear] = element;
    }

    int Dequeue() { 
        if (this->CheckEmpty()) {
            std::cout << "Queue is empty, cannot dequeue" << std::endl;
            return -1;
        }
        int temp = this->array[this->front];
        if (this->front == this->rear) {
            this->front = this->rear = -1;
        } else {
            this->front = (this->front + 1) % this->queueSize;
        }
        return temp;
    }

    int GetFront() {
        if (this->CheckEmpty()) {
            return -1;
        }
        return this->array[this->front];
    }

    bool CheckEmpty() {
        return this->front == -1;
    }

    bool CheckFull() { 
        return (this->front == (this->rear + 1) % this->queueSize);
    }
};

int main() {
    CircularQueue circularQueue(17);

    circularQueue.Enqueue(10);
    circularQueue.Enqueue(101);
    circularQueue.Enqueue(68);
    circularQueue.Enqueue(11);
    circularQueue.Enqueue(1);

    std::cout << "Dequeued: " << circularQueue.Dequeue() << std::endl;

    if (circularQueue.CheckEmpty()) {
        std::cout << "Circular Quere Is Empty" << std::endl;
    } else {
        std::cout << "Circular Quere Isn't Empty" << std::endl;
    }

    if (circularQueue.CheckEmpty()) {
        std::cout << "Circular Quere Is Full" << std::endl;
    } else {
        std::cout << "Circular Quere Isn't Full" << std::endl;
    }

    std::cout << "Get Front: " << circularQueue.GetFront() << std::endl;

    return 0;
}