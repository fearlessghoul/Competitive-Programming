#include <iostream>
#include <vector>
#include <functional>
using namespace std;
class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

TreeNode *findMin(TreeNode *node){
    while (node->left != nullptr){
        node = node->left;
    }
    return node;
}

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->value) {
        root->left = insertNode(root->left, val);
    } else if (val > root->value) {
        root->right = insertNode(root->right, val);
    }
    
    // Return the unchanged root pointer
    return root;
}
TreeNode *deleteNode(TreeNode *root, int key){
    if (root == nullptr){
        return root; // Base case: the tree is empty
    }

    // Recursively traverse the tree to find the node to delete
    if (key < root->value){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->value){
        root->right = deleteNode(root->right, key);
    }
    else{
        // Node found

        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        // Case 2: Node has one child
        else if (root->left == nullptr){
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr){
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        else{
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode *temp = findMin(root->right);

            // Replace root's value with the inorder successor's value
            root->value = temp->value;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->value);
        }
    }

    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums){
    if (nums.empty()){
        return nullptr;
    }

    function<TreeNode *(int, int)> convert = [&](int left, int right) -> TreeNode *{
        if (left > right){
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = convert(left, mid - 1);
        node->right = convert(mid + 1, right);
        return node;
    };

    return convert(0, nums.size() - 1);
}

void inorderTraversal(TreeNode *root){
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main(){
    // Create a sample BST:
    //       5
    //      / \
    //     3   8
    //    / \   \
    //   2   4   9

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(10);
    root->right->right->left=new TreeNode(9);

    // Perform inorder traversal before deletion
    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 3
    root = deleteNode(root, 8);

    // Perform inorder traversal after deletion
    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up memory (not shown here for brevity)

    vector<int> sortedArray = {-10, -3, 0, 5, 9};
    root = sortedArrayToBST(sortedArray);

    // Test the tree by printing it in-order
    cout << "In-order traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
