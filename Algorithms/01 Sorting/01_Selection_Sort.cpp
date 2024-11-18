#include <iostream>
using namespace std;

void selectionSort(int array[], int size) {
    int currentIndex, comparisonIndex, minIndex;
    for (currentIndex = 0; currentIndex < size - 1; currentIndex++) {
        minIndex = currentIndex;
        for (comparisonIndex = currentIndex + 1; comparisonIndex < size; comparisonIndex++) {
            if (array[comparisonIndex] < array[minIndex])
                minIndex = comparisonIndex;
        }
        if (minIndex != currentIndex)
            swap(array[minIndex], array[currentIndex]);
    }
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
