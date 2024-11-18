#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    
    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if (head == nullptr) {
            newNode->next = newNode; // Point to itself
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    
    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            newNode->next = newNode; // Point to itself
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
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
            if (head == nullptr) {
                newNode->next = newNode; // Point to itself
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                newNode->next = head;
                temp->next = newNode;
                head = newNode;
            }
            return;
        }

        Node* temp = head;
        for (int i = 0; temp->next != head && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp->next == head && position > 1) {
            cout << "Position out of bounds!" << endl;
            delete newNode; // Free the memory allocated for newNode
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }

    // Reverse the list
    void reverseList() {
        if (head == nullptr || head->next == head) {
            return;
        }

        Node *prev = nullptr, *current = head, *next = nullptr;
        Node *temp = head;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtEnd(3);
    list.insertAtPosition(4, 2); // Insert 4 at position 2
    list.display(); // Output: 2 -> 1 -> 4 -> 3 -> HEAD
    list.reverseList();
    list.display(); // Output: 3 -> 4 -> 1 -> 2 -> HEAD
    
    return 0;
}
