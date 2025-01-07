#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree; // Segment tree storage
    int n;            // Size of the original array

    int getSize(int n){
        if(n==1) return 1;
        int c=0,i=0;
        while(n){
            if(n&1)c++;
            n=n>>1;
            i++;
        }
        return 1<<(i+(c>1));
    }
    // Function to build the tree recursively
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            buildTree(arr, leftChild, start, mid);
            buildTree(arr, rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Function to update the tree recursively
    void updateTree(int node, int start, int end, int idx, int value) {
        if (start == end) {
            // Update the leaf node
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updateTree(leftChild, start, mid, idx, value);
            } else {
                updateTree(rightChild, mid + 1, end, idx, value);
            }

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Function to query the sum in a range recursively
    int queryTree(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            // Range outside the current segment
            return 0;
        }

        if (l <= start && r >= end) {
            // Current segment completely within the range
            return tree[node];
        }

        // Partial overlap, split range
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryTree(leftChild, start, mid, l, r);
        int rightSum = queryTree(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(getSize(n), 0);
        buildTree(arr, 0, 0, n - 1);
    }

    // Update a value in the array
    void update(int idx, int value) {
        updateTree(0, 0, n - 1, idx, value);
    }

    // Query the sum in a range [l, r]
    int query(int l, int r) {
        return queryTree(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Initialize segment tree
    SegmentTree segTree(arr);

    // Query the sum in range [1, 3)
    cout << "Sum in range [1, 3): " << segTree.query(1, 2) << endl;

    // Update element at index 2
    segTree.update(2, 1);

    // Query the sum in range [1, 3) again
    cout << "Sum in range [1, 3) after update: " << segTree.query(1, 2) << endl;

    return 0;
}
