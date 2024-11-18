#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = array[mid + 1 + i];

    // Merge the temporary arrays back into array[left..right]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = left; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main() {
    int array[] = {2, 4, 67, 23, 9, 4, 9, 5, 7, 2, 4, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
