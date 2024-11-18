#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class Stack{
private:
    Node *head;
    int size;
public:
    Stack(){
        head = nullptr;
        size=0;
    }

    ~Stack(){
        if (!isEmpty()){
            Node *temp = head;
            while (temp!=nullptr){
                head=temp->next;
                delete temp;
                temp=head;
            }
            
        }
    }

    // Push an element on the stack
    void push(int value){
        if (isEmpty()){
            head = new Node(value);
        }
        else{
            Node *temp = new Node(value);
            temp->next = head;
            head = temp;
        }
        size++;
    }

    // Pop an element from the stack
    int pop(){
        if (isEmpty()){
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node *temp = head;
        head=head->next;
        int val= temp->data;
        delete temp;
        size--;
        return val;
    }

    // Peek at the top element of the stack
    int peek() const{
        if (isEmpty()){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    // Check if the stack is empty
    bool isEmpty() const{
        return head == nullptr;
    }
    int length() const{
        return size;
    }
};

int main(){
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element is: " << myStack.peek() << endl;
    cout << "Stack size is: " << myStack.length() << endl;

    myStack.pop();

    if (myStack.isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70); // This should trigger a stack overflow

    cout << "Top element is: " << myStack.peek() << endl;
    cout << "Stack size is: " << myStack.length() << endl;

    return 0;
}
