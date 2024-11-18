#include <iostream>
#include <algorithm> // for std::max
using namespace std;

void countingSort(int array[], int size) {
    // Find the maximum element in the array
    int maxElement = *max_element(array, array + size);

    // Create a count array to store the count of each unique object
    int* count = new int[maxElement + 1]();

    // Store the count of each element in the count array
    for (int i = 0; i < size; i++)
        count[array[i]]++;

    // Store the cumulative count of each array
    for (int i = 1; i <= maxElement; i++)
        count[i] += count[i - 1];

    // Find the index of each element of the original array in the count array
    // and place the elements in the output array
    int* output = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];

    // Clean up dynamically allocated memory
    delete[] count;
    delete[] output;
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    countingSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
