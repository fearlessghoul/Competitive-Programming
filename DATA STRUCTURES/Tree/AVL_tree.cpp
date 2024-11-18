#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};
// Balanced Tree height can at max be Log2N

int height(Node *N){
    return (N == nullptr) ? 0 : N->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getBalance(Node *N){
    return (N == nullptr) ? 0 : height(N->left) - height(N->right);
}

Node *rotateRight(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

Node *rotateLeft(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

Node *insert(Node *node, int key){
    // 1. Perform the normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node to check whether
    //    this node became unbalanced
    int balance = getBalance(node);

    // 4. If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Return the (unchanged) node pointer
    return node;
}
Node *minValueNode(Node *node){
    Node *current = node;

    // Find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int key){
    // 1. Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)){
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr){
                temp = root;
                root = nullptr;
            }
            else               // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        }
        else{
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // 2. Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Get the balance factor
    int balance = getBalance(root);

    // 4. If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preOrder(Node *root){
    if (root != nullptr){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node *root = nullptr;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal before deletion: ";
    preOrder(root);
    cout << endl;

    // Delete node 40
    root = deleteNode(root, 40);

    cout << "Preorder traversal after deletion: ";
    preOrder(root);

    return 0;
}
