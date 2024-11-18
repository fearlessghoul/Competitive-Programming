#include <iostream>
#include <algorithm> // for std::max
using namespace std;

void countingSortForRadix(int array[], int size, int place) {
    int* output = new int[size]; // output array
    int maxElement = 10; // The base is 10 for decimal numbers
    int* count = new int[maxElement]();

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < maxElement; i++)
        count[i] += count[i - 1];

    // Place the elements in the output array in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; i++)
        array[i] = output[i];

    // Clean up dynamically allocated memory
    delete[] output;
    delete[] count;
}

void radixSort(int array[], int size) {
    // Find the maximum number to know the number of digits
    int maxElement = *max_element(array, array + size);

    // Apply counting sort to sort elements based on place value
    for (int place = 1; maxElement / place > 0; place *= 10)
        countingSortForRadix(array, size, place);
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    radixSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
