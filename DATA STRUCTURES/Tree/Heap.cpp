#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> heap;  // Dynamic array to store the heap elements
    bool isMinHeap;    // True for Min-Heap, False for Max-Heap

    // Helper function to get the index of the parent node
    int parent(int i) { return (i - 1) / 2; }

    // Helper function to get the index of the left child
    int leftChild(int i) { return (2 * i + 1); }

    // Helper function to get the index of the right child
    int rightChild(int i) { return (2 * i + 2); }

    // Comparison function to check heap property based on the type of heap
    bool compare(int a, int b) {
        if (isMinHeap) return a < b;  // Min-Heap condition
        else return a > b;            // Max-Heap condition
    }

    // Heapify down from the given index to maintain the heap property
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int extremum = i;

        // Find the smallest (or largest in case of Max-Heap) among parent and children
        if (left < heap.size() && compare(heap[left], heap[extremum])) {
            extremum = left;
        }

        if (right < heap.size() && compare(heap[right], heap[extremum])) {
            extremum = right;
        }

        // If the smallest/largest is not the parent, swap and heapify down
        if (extremum != i) {
            swap(heap[i], heap[extremum]);
            heapifyDown(extremum);
        }
    }

    // Heapify up from the given index to maintain the heap property
    void heapifyUp(int i) {
        while (i != 0 && compare(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
public:
    // Constructor to specify if the heap is a Min-Heap or Max-Heap
    Heap(bool minHeap = true) {
        isMinHeap = minHeap;
    }

    // Insert a new element into the heap
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);  // Heapify up from the last inserted node
    }

    // Get the minimum (or maximum) element in the heap
    int getTop() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Delete the top (minimum or maximum) element from the heap
    void deleteTop() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        // Move the last element to the root and remove the last element
        heap[0] = heap.back();
        heap.pop_back();

        // Heapify down from the root to restore the heap property
        if (heap.size() > 0) {
            heapifyDown(0);
        }
    }
    
    // Delete the element using index
    void deleteElement(int i){
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[i] = isMinHeap ? INT_MIN : INT_MAX;
        heapifyUp(i);
        deleteTop();
    }
    // Display the elements of the heap
    void display() {
        if (heap.size() == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Min-Heap Example
    cout << "Min-Heap Example:" << endl;
    Heap minHeap(true);  // Creating a Min-Heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Heap elements: ";
    minHeap.display();

    cout << "Top element: " << minHeap.getTop() << endl;  // Get the minimum element

    minHeap.deleteTop();  // Delete the top (minimum) element
    cout << "After deleting top, heap elements: ";
    minHeap.display();

    // Max-Heap Example
    cout << "\nMax-Heap Example:" << endl;
    Heap maxHeap(false);  // Creating a Max-Heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);

    cout << "Heap elements: ";
    maxHeap.display();

    cout << "Top element: " << maxHeap.getTop() << endl;  // Get the maximum element

    maxHeap.deleteTop();  // Delete the top (maximum) element
    cout << "After deleting top, heap elements: ";
    maxHeap.display();

    maxHeap.deleteElement(1);  // Delete the top (maximum) element
    cout << "After deleting 0, heap elements: ";
    maxHeap.display();

    return 0;
}
