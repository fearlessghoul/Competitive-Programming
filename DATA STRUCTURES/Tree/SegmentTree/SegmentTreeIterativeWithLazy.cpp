#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
private:
    vector<int> tree, lazy;
    int size;

    // Propagate pending updates to a node and its children
    void propagate(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node]; // Apply pending update
            if (l != r) { // If not a leaf node, propagate to children
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0; // Clear lazy value for the node
        }
    }

    // Build the segment tree iteratively
    void build(const vector<int>& arr) {
        for (int i = 0; i < size; ++i)
            tree[size + i] = arr[i]; // Initialize leaf nodes

        for (int i = size - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1]; // Combine child nodes
    }

public:
    // Constructor
    LazySegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(2 * size, 0);
        lazy.resize(2 * size, 0);
        build(arr);
    }

    // Update a range [l, r] by adding `value` iteratively
    void update(int l, int r, int value) {
        l += size; // Shift to leaf nodes
        r += size;

        int l_orig = l, r_orig = r; // Save original bounds for propagation

        // Apply updates to the tree lazily
        while (l <= r) {
            if (l % 2 == 1) { // If `l` is a right child
                lazy[l] += value;
                propagate(l, l - size, l - size);
                l++;
            }
            if (r % 2 == 0) { // If `r` is a left child
                lazy[r] += value;
                propagate(r, r - size, r - size);
                r--;
            }
            l /= 2;
            r /= 2;
        }

        // Update parent nodes
        for (l = l_orig / 2, r = r_orig / 2; l > 0; l /= 2, r /= 2) {
            if (lazy[l * 2] == 0 && lazy[l * 2 + 1] == 0)
                tree[l] = tree[l * 2] + tree[l * 2 + 1];
            if (lazy[r * 2] == 0 && lazy[r * 2 + 1] == 0)
                tree[r] = tree[r * 2] + tree[r * 2 + 1];
        }
    }

    // Query the sum of range [l, r]
    int query(int l, int r) {
        l += size; // Shift to leaf nodes
        r += size;

        int sum = 0;

        while (l <= r) {
            propagate(l, l - size, l - size);
            propagate(r, r - size, r - size);

            if (l % 2 == 1) {
                sum += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                sum += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return sum;
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
