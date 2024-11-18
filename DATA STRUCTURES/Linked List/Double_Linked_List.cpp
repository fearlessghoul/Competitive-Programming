#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // Pointer to the previous node
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    
    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr && position > 1) {
            cout << "Position out of bounds!" << endl;
            delete newNode; // Free the memory allocated for newNode
            return;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
        Node *temp = nullptr;
        Node *current = head;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtPosition(4, 2); // Insert 4 at position 2
    list.display(); // Output: 2 -> 1 -> 4 -> 3 -> NULL
    list.reverseList();
    list.display(); // Output: 3 -> 4 -> 1 -> 2 -> NULL

    return 0;
}
