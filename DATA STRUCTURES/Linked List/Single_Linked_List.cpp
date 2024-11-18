#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val): data(val),next(nullptr){}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
        LinkedList(int *arr, int size){
        this->fromArray(arr, size);
    }
    // From array
    void fromArray(int *arr, int size){
        if (head == nullptr){
            if (size > 0){
                head = new Node(arr[0]);
                Node *temp = head;
                for (int i = 1; i < size; i++){
                    temp = temp->next = new Node(arr[i]);
                }
            }
            else{
                cout << "Invalid size!" << endl;
            }
        }
        else{
            cout << "Linked List must be Empty." << endl;
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode; // Free the memory allocated for newNode
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // Reverse the list
    void reverseList() {
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move pointers one position ahead
            current = next;
        }
        head = prev; // Update head to point to the new first node
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtPosition(4, 2); // Insert 4 at position 2
    list.display(); // Output: 2 -> 1 -> 4 -> 3 -> NULL
    list.reverseList();
    list.display();
    return 0;
}
