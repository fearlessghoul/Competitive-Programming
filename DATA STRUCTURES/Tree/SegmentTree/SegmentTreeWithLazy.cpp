#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
private:
    vector<int> tree, lazy;
    int size;

    // Function to build the segment tree
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);        // Left child
            buildTree(arr, 2 * node + 2, mid + 1, end);      // Right child
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Combine
        }
    }

    // Function to propagate pending updates
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply the pending update
            tree[node] += (end - start + 1) * lazy[node]; // Update range

            // If not a leaf node, propagate to children
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Clear the lazy value for this node
            lazy[node] = 0;
        }
    }

    // Function to update a range of values
    void updateRange(int node, int start, int end, int l, int r, int value) {
        propagate(node, start, end);

        // Out of range
        if (start > r || end < l) return;

        // Fully in range
        if (start >= l && end <= r) {
            lazy[node] += value;
            propagate(node, start, end);
            return;
        }

        // Partially in range
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, value);       // Left child
        updateRange(2 * node + 2, mid + 1, end, l, r, value);     // Right child
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];     // Combine
    }

    // Function to query the sum in a range
    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        // Out of range
        if (start > r || end < l) return 0;

        // Fully in range
        if (start >= l && end <= r) return tree[node];

        // Partially in range
        int mid = (start + end) / 2;
        int leftSum = queryRange(2 * node + 1, start, mid, l, r);
        int rightSum = queryRange(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

public:
    // Constructor to initialize the segment tree
    LazySegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size, 0);
        lazy.resize(4 * size, 0);
        buildTree(arr, 0, 0, size - 1);
    }

    // Public method to update a range
    void update(int l, int r, int value) {
        updateRange(0, 0, size - 1, l, r, value);
    }

    // Public method to query a range
    int query(int l, int r) {
        return queryRange(0, 0, size - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    LazySegmentTree segTree(arr);

    // Initial range sum queries
    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    // Update range [1, 4] by adding 10
    segTree.update(1, 4, 10);

    // Query after update
    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    // Update range [2, 5] by adding 5
    segTree.update(2, 5, 5);

    // Query after second update
    cout << "Sum of range [3, 5]: " << segTree.query(3, 5) << endl;

    return 0;
}
