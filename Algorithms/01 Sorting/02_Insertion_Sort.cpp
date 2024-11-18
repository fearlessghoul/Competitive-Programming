#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
    int currentIndex, key, comparisonIndex;
    for (currentIndex = 1; currentIndex < size; currentIndex++) {
        key = array[currentIndex];
        comparisonIndex = currentIndex - 1;

        while (comparisonIndex >= 0 && array[comparisonIndex] > key) {
            array[comparisonIndex + 1] = array[comparisonIndex];
            comparisonIndex = comparisonIndex - 1;
        }
        array[comparisonIndex + 1] = key;
    }
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
