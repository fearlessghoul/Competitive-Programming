#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int low, int high){
    int pivot = array[high]; // pivot
    int i = (low - 1);       // Index of smaller element

    for (int j = low; j <= high - 1; j++){
        // If current element is smaller than the pivot
        if (array[j] < pivot){
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high){
    if (low < high){
        int pivotIndex = partition(array, low, high);

        // Separately sort elements before and after partition
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

void printSub(int arr[], int index, std::vector<int> &subarr, int n, int target, int commutativesum){
    if (commutativesum > target && arr[index] >= 0){
        return;
    }
    else if (index == n){
        if (subarr.size() != 0 && commutativesum == target){
            for (auto it : subarr){
                cout << it << " ";
            }
            cout << endl;
        }
    }
    else{
        subarr.push_back(arr[index]);
        printSub(arr, index + 1, subarr, n, target, commutativesum + arr[index]);
        subarr.pop_back();
        printSub(arr, index + 1, subarr, n, target, commutativesum);
    }
}
int main(){
    int sum = 10;
    int *arr = new int[10]{1, 2, 3, 4, 5, 7, 9, 10, 11, 13};
    quickSort(arr, 0, 9);
    vector<int> vec;
    printSub(arr, 0, vec, 10, sum, 0);
    return 0;
}