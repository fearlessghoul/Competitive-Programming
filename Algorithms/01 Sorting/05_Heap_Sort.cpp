#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int array[], int size, int rootIndex) {
    int largest = rootIndex; // Initialize largest as root
    int leftChild = 2 * rootIndex + 1; // left = 2*rootIndex + 1
    int rightChild = 2 * rootIndex + 2; // right = 2*rootIndex + 2

    // If left child is larger than root
    if (leftChild < size && array[leftChild] > array[largest])
        largest = leftChild;

    // If right child is larger than largest so far
    if (rightChild < size && array[rightChild] > array[largest])
        largest = rightChild;

    // If largest is not root
    if (largest != rootIndex) {
        swap(array[rootIndex], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, size, largest);
    }
}

void heapSort(int array[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    heapSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
