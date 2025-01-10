#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class FenwickTree {
private:
    vector<int> BITree; // Binary Indexed Tree
    int size;           // Size of the original array

    // The function to be applied for updates and queries (prefix sum for this demo)
    int sum(int a, int b) {
        return a + b; // Replace this with other associative operations if needed
    }

    // Returns the cumulative result for range [0, index]
    int prefixQuery(int index) {
        int result = 0; // Identity for sum operation
        index++;        // 1-based indexing for BITree

        // Traverse the tree
        while (index > 0) {
            result = sum(result, BITree[index]);
            index -= index & (-index); // Move to the parent node
        }
        return result;
    }

public:
    // Constructor to initialize the Fenwick Tree with a given array
    FenwickTree(const vector<int>& arr) {
        size = arr.size();
        BITree.resize(size + 1, 0);

        // Build the BITree
        for (int i = 0; i < size;i++) {
            update(i, arr[i]);
        }
    }

    // Updates the value at index 'i' using the compare function
    void update(int index, int val) {
        index++; // 1-based indexing for BITree

        // Traverse the tree
        while (index <= size) {
            BITree[index] = sum(BITree[index], val);
            index += index & (-index); // Move to the next node
        }
    }

    // Queries the cumulative result for range [0, index]
    int query(int index) {
        return prefixQuery(index);
    }

    // Queries the cumulative result for range [left, right]
    int rangeQuery(int left, int right) {
        return prefixQuery(right) - (left > 0 ? prefixQuery(left - 1) : 0);
    }
};

// Driver program to test the Fenwick Tree
int main() {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    // Fenwick Tree for prefix sum
    FenwickTree fenwickTree(arr);

    cout << "Sum of elements in arr[0..5]: "
         << fenwickTree.query(5) << endl;

    fenwickTree.update(3, 6); // Add 6 to arr[3]

    cout << "Updated sum of elements in arr[0..5]: "
         << fenwickTree.query(5) << endl;

    cout << "Sum of elements in arr[2..6]: "
         << fenwickTree.rangeQuery(2, 6) << endl;

    return 0;
}
