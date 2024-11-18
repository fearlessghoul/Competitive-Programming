#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    // Add an element to the end of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    // Get the front element
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int rearElement() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is full
    bool isFull() const {
        return count == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Front element is: " << queue.peek() << endl;
    cout << "Rear element is: " << queue.rearElement() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "After dequeuing two elements, front element is: " << queue.peek() << endl;
    cout << "After dequeuing two elements, rear element is: " << queue.rearElement() << endl;

    if (queue.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70); // This should trigger a queue overflow

    cout << "After enqueueing three more elements, front element is: " << queue.peek() << endl;
    cout << "After enqueueing three more elements, rear element is: " << queue.rearElement() << endl;

    return 0;
}
