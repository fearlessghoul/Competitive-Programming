#include<bits/stdc++.h>

using namespace std;

struct FibNode {
    int key, degree;
    bool marked;
    FibNode* parent;
    FibNode* child;
    FibNode* left;
    FibNode* right;

    FibNode(int k) {
        key = k;
        degree = 0;
        marked = false;
        parent = child = nullptr;
        left = right = this;
    }
};

class FibonacciHeap {
private:
    FibNode* minNode;
    int nodeCount;

    void link(FibNode* y, FibNode* x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;

        if (!x->child) {
            x->child = y;
            y->right = y->left = y;
        } else {
            y->right = x->child;
            y->left = x->child->left;
            x->child->left->right = y;
            x->child->left = y;
        }

        x->degree++;
        y->marked = false;
    }

    void consolidate() {
        int maxDegree = log2(nodeCount) + 1;
        vector<FibNode*> degreeTable(maxDegree, nullptr);

        vector<FibNode*> rootList;
        FibNode* x = minNode;
        if (x) {
            do {
                rootList.push_back(x);
                x = x->right;
            } while (x != minNode);
        }

        for (FibNode* w : rootList) {
            x = w;
            int d = x->degree;

            while (degreeTable[d]) {
                FibNode* y = degreeTable[d];
                if (x->key > y->key) swap(x, y);
                link(y, x);
                degreeTable[d] = nullptr;
                d++;
            }

            degreeTable[d] = x;
        }

        minNode = nullptr;
        for (FibNode* n : degreeTable) {
            if (n) {
                if (!minNode || n->key < minNode->key)
                    minNode = n;
            }
        }
    }

public:
    FibonacciHeap() {
        minNode = nullptr;
        nodeCount = 0;
    }

    void insert(int key) {
        FibNode* newNode = new FibNode(key);
        if (!minNode) minNode = newNode;
        else {
            newNode->right = minNode;
            newNode->left = minNode->left;
            minNode->left->right = newNode;
            minNode->left = newNode;
            if (newNode->key < minNode->key) minNode = newNode;
        }
        nodeCount++;
    }

    int extractMin() {
        if (!minNode) return -1;
        int minKey = minNode->key;
        // Extraction and consolidation omitted for brevity
        return minKey;
    }
};

int main() {
    FibonacciHeap fh;
    fh.insert(10);
    fh.insert(20);
    fh.insert(5);
    cout << "Extract Min: " << fh.extractMin() << endl;
    return 0;
}
