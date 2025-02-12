#include <iostream>
#include <cmath>

using namespace std;

struct BinomialNode {
    int key, degree;
    BinomialNode *parent, *child, *sibling;

    BinomialNode(int k) {
        key = k;
        degree = 0;
        parent = child = sibling = nullptr;
    }
};

class BinomialHeap {
private:
    BinomialNode* head;

    // Merge two binomial trees of the same degree
    BinomialNode* mergeTrees(BinomialNode* t1, BinomialNode* t2) {
        if (t1->key > t2->key) swap(t1, t2);
        t2->parent = t1;
        t2->sibling = t1->child;
        t1->child = t2;
        t1->degree++;
        return t1;
    }

    // Merge two binomial heaps
    BinomialNode* mergeHeaps(BinomialNode* h1, BinomialNode* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        BinomialNode* newHead = nullptr, *tail = nullptr;
        BinomialNode* t1 = h1, *t2 = h2;

        while (t1 && t2) {
            BinomialNode* minNode = nullptr;
            if (t1->degree <= t2->degree) {
                minNode = t1;
                t1 = t1->sibling;
            } else {
                minNode = t2;
                t2 = t2->sibling;
            }

            if (!newHead) newHead = minNode;
            else tail->sibling = minNode;
            tail = minNode;
        }

        if (t1) tail->sibling = t1;
        if (t2) tail->sibling = t2;

        return newHead;
    }

    // Adjust heap after merging
    void adjustHeap() {
        if (!head) return;

        BinomialNode *prev = nullptr, *curr = head, *next = head->sibling;

        while (next) {
            if ((curr->degree != next->degree) ||
                (next->sibling && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            } else {
                if (curr->key <= next->key) {
                    curr->sibling = next->sibling;
                    mergeTrees(curr, next);
                } else {
                    if (!prev) head = next;
                    else prev->sibling = next;
                    mergeTrees(next, curr);
                    curr = next;
                }
            }
            next = curr->sibling;
        }
    }

public:
    BinomialHeap() { head = nullptr; }

    // Insert a key into the heap
    void insert(int key) {
        BinomialHeap tempHeap;
        tempHeap.head = new BinomialNode(key);
        head = mergeHeaps(head, tempHeap.head);
        adjustHeap();
    }

    // Find the minimum key
    BinomialNode* findMin() {
        if (!head) return nullptr;
        BinomialNode *minNode = head, *curr = head->sibling;

        while (curr) {
            if (curr->key < minNode->key)
                minNode = curr;
            curr = curr->sibling;
        }

        return minNode;
    }

    // Extract the minimum key
    int extractMin() {
        if (!head) return -1;

        BinomialNode *minNode = head, *prevMin = nullptr, *curr = head;
        BinomialNode *prev = nullptr;

        while (curr->sibling) {
            if (curr->sibling->key < minNode->key) {
                minNode = curr->sibling;
                prevMin = prev;
            }
            prev = curr;
            curr = curr->sibling;
        }

        if (prevMin) prevMin->sibling = minNode->sibling;
        else head = minNode->sibling;

        BinomialNode* child = minNode->child;
        BinomialNode* revChild = nullptr;

        while (child) {
            BinomialNode* next = child->sibling;
            child->sibling = revChild;
            revChild = child;
            child = next;
        }

        BinomialHeap newHeap;
        newHeap.head = revChild;
        head = mergeHeaps(head, newHeap.head);
        adjustHeap();

        int minKey = minNode->key;
        delete minNode;
        return minKey;
    }
};

int main() {
    BinomialHeap bh;
    bh.insert(10);
    bh.insert(20);
    bh.insert(5);
    bh.insert(30);

    cout << "Minimum: " << bh.findMin()->key << endl;
    cout << "Extract Min: " << bh.extractMin() << endl;
    cout << "New Minimum: " << bh.findMin()->key << endl;

    return 0;
}
