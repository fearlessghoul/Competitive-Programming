#include <iostream>
#include <vector>
#include <stdexcept>

class PriorityQueue {
private:
    std::vector<int> heap;

    // Helper function to maintain heap property during insertion
    void heapifyUp(int index) {
        if (index == 0) return; // If the element is at the root, do nothing
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    // Helper function to maintain heap property during deletion
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Check if the priority queue is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Insert an element into the priority queue
    void enqueue(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the highest priority element
    int dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Peek at the highest priority element without removing it
    int peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return heap[0];
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(3);
    pq.enqueue(5);
    pq.enqueue(1);
    pq.enqueue(4);

    std::cout << "Peek: " << pq.peek() << std::endl; // Should output 5

    while (!pq.isEmpty()) {
        std::cout << pq.dequeue() << " "; // Should output 5 4 3 1
    }

    return 0;
}
