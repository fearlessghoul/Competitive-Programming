#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// A class-based implementation for modularity
class SegmentTree {
private:
    vector<int> tree;
    int size;

    // A utility function to combine two nodes
    int combine(int left, int right) {
        return max(left, right); // Replaceable for other operations like sum or min
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(2 * size);
        build(arr);
    }

    // Build the segment tree from the input array
    void build(const vector<int>& arr) {
        // Fill leaves of the tree
        for (int i = 0; i < size; i++) {
            tree[size + i] = arr[i];
        }
        // Fill internal nodes
        for (int i = size - 1; i > 0; --i) {
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // Update a value in the segment tree
    void update(int index, int value) {
        // Update the leaf node
        index += size;
        tree[index] = value;
        // Update internal nodes
        while (index > 1) {
            index /= 2;
            tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
        }
    }

    // Query for a range [left, right)
    int query(int left, int right) {
        left += size;
        right += size;
        int result = INT_MIN; // Initialize to identity for `max`
        while (left < right) {
            if (left % 2 == 1) {
                result = combine(result, tree[left]);
                left++;
            }
            if (right % 2 == 1) {
                right--;
                result = combine(result, tree[right]);
            }
            left /= 2;
            right /= 2;
        }
        return result;
    }

    // Print the segment tree (for debugging)
    void print() {
        for (int i = 1; i < 2 * size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    vector<int> arr = {2, 6, 10, 4, 7, 28, 9, 11, 6, 33};
    SegmentTree segTree(arr);

    // Example queries and updates
    cout << "Maximum in range [1, 5): " << segTree.query(0,5) << endl;

    segTree.update(5, 32); // Update index 5 to 32
    cout << "After update, maximum in range [2, 8): " << segTree.query(2, 8) << endl;

    return 0;
}
