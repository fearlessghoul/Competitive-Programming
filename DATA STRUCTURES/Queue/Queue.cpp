#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
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
        if(isEmpty()) front=0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return;
        }
        if(front==rear){
            front=rear=-1;
            return;
        }
        front = (front + 1) % capacity;
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
        return (front == 0 && ((rear+1) == capacity)) || ((rear+1) % capacity == front);
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front==-1;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(45);

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
