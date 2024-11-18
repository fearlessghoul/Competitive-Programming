#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    bool swapped;
    for (int pass = 0; pass < size - 1; pass++) {
        swapped = false;
        for (int comparisonIndex = 0; comparisonIndex < size - pass - 1; comparisonIndex++) {
            if (array[comparisonIndex] > array[comparisonIndex + 1]) {
                swap(array[comparisonIndex], array[comparisonIndex + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
