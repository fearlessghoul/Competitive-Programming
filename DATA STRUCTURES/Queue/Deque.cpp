#include <iostream>
using namespace std;

class Deque{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Deque(int size){
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = 0;
        count = 0;
    }

    ~Deque(){
        delete[] arr;
    }

    // Add an element to the front of the deque
    void insertFront(int value){
        if (isFull()){
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()){
            front = 0;
            rear = 0;
        }
        else if (front == 0){
            front = capacity - 1;
        }
        else{
            front = front - 1;
        }
        arr[front] = value;
        count++;
    }

    // Add an element to the rear of the deque
    void insertRear(int value){
        if (isFull()){
            cout << "Deque overflow!" << endl;
            return;
        }
        if (isEmpty()){
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
        arr[rear] = value;
        count++;
    }

    // Remove an element from the front of the deque
    void deleteFront(){
        if (isEmpty()){
            cout << "Deque underflow!" << endl;
            return;
        }
        if (front == rear){
            front = -1;
            rear = 0;
        }
        else{
            front = (front + 1) % capacity;
        }
        count--;
    }

    // Remove an element from the rear of the deque
    void deleteRear(){
        if (isEmpty()){
            cout << "Deque underflow!" << endl;
            return;
        }
        if (front == rear){
            front = -1;
            rear = 0;
        }
        else{
            rear = (capacity + rear - 1) % capacity;
        }
        count--;
    }

    // Get the front element
    int getFront() const{
        if (isEmpty()){
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() const{
        if (isEmpty()){
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if the deque is full
    bool isFull() const{
        return count == capacity;
    }

    // Check if the deque is empty
    bool isEmpty() const{
        return count == 0;
    }

    // Get the size of the deque
    int size() const{
        return count;
    }
};

int main(){
    Deque deque(5);

    deque.insertRear(10);
    deque.insertRear(20);
    deque.insertFront(30);
    deque.insertFront(40);

    cout << "Front element is: " << deque.getFront() << endl; // Output: 40
    cout << "Rear element is: " << deque.getRear() << endl;   // Output: 20

    deque.deleteFront();
    cout << "After deleting front, front element is: " << deque.getFront() << endl; // Output: 30

    deque.deleteRear();
    cout << "After deleting rear, rear element is: " << deque.getRear() << endl; // Output: 10

    cout << "Size of deque is: " << deque.size() << endl; // Output: 2

    return 0;
}
