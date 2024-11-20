#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node
    int count;   // Number of elements in the deque

public:
    Deque() : front(nullptr), rear(nullptr), count(0) {}

    ~Deque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

    // Add an element to the front of the deque
    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        count++;
    }

    // Add an element to the rear of the deque
    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    // Remove an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque underflow!" << endl;
            return;
        }

        Node* temp = front;
        if (front == rear) {
            // If there is only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        count--;
    }

    // Remove an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque underflow!" << endl;
            return;
        }

        Node* temp = rear;
        if (front == rear) {
            // If there is only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        count--;
    }

    // Get the front element
    int getFront() const {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get the rear element
    int getRear() const {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Check if the deque is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Get the size of the deque
    int size() const {
        return count;
    }
};

// Example usage
int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    cout << "Front element: " << dq.getFront() << endl; // 1
    cout << "Rear element: " << dq.getRear() << endl;   // 20
    cout << "Deque size: " << dq.size() << endl;        // 4

    dq.deleteFront();
    cout << "After deleting front, front element: " << dq.getFront() << endl; // 5

    dq.deleteRear();
    cout << "After deleting rear, rear element: " << dq.getRear() << endl;   // 10

    dq.deleteRear();
    dq.deleteRear();
    dq.deleteRear(); // Attempt to delete from an empty deque

    return 0;
}
