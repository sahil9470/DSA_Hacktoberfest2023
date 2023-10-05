#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int front;            // Index of the front element
    int rear;             // Index of the rear element
    int arr[MAX_SIZE];    // Array to store queue elements

public:
    Queue() {
        front = -1;        // Initialize front and rear indices
        rear = -1;
    }

    // Function to enqueue (insert) an element at the rear of the queue
    void enqueue(int value) {
        if (rear >= MAX_SIZE - 1) {
            std::cout << "Queue Overflow! Cannot enqueue element " << value << ".\n";
            return;
        }
        if (isEmpty()) {
            front = 0; // If the queue is empty, set front to 0
        }
        arr[++rear] = value; // Increment rear and insert the value
        std::cout << "Enqueued element " << value << " into the queue.\n";
    }

    // Function to dequeue (remove) an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow! The queue is empty.\n";
            return -1; // Return a sentinel value to indicate an empty queue
        }
        int value = arr[front++]; // Get the front element and increment front
        if (front > rear) {
            // If front has passed rear, the queue is now empty
            front = rear = -1;
        }
        return value;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to get the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "The queue is empty.\n";
            return -1; // Return a sentinel value to indicate an empty queue
        }
        return arr[front];
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << std::endl;

    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << myQueue.dequeue() << std::endl;

    std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
