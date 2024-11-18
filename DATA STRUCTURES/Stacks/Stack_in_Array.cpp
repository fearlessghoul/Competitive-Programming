#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Push an element on the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek at the top element of the stack
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Get the size of the stack
    int size() const {
        return top + 1;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;
    cout << "Stack size is: " << stack.size() << endl;

    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70); // This should trigger a stack overflow

    cout << "Top element is: " << stack.peek() << endl;
    cout << "Stack size is: " << stack.size() << endl;

    return 0;
}
