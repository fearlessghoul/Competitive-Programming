#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (array[j] < pivot) {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        // Separately sort elements before and after partition
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, size - 1);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
