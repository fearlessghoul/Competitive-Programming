#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(const vector<int>& arr, int x) {
    int n = arr.size();

    // Initialize Fibonacci numbers
    int fibMMm2 = 0;  // (m-2)'th Fibonacci number
    int fibMMm1 = 1;  // (m-1)'th Fibonacci number
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci number

    // fibM is the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to be inspected
    while (fibM > 1) {
        // Check if fibMMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);

        // If x is greater than the value at index fibMMm2, cut the subarray from offset to i
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > x) {
            // If x is less than the value at index fibMMm2, cut the subarray after i+1
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            // Element found. Return index
            return i;
        }
    }

    // Compare the last element with x
    if (fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // Element not found. Return -1
    return -1;
}

int main() {
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int x = 100;
    int index = fibonacciSearch(arr, x);
    
    if (index != -1) {
        cout << "Found at index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
