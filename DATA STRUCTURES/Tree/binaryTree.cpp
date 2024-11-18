#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

// Depth-First Traversal

void inOrder(Node *root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void inOrderIterative(Node *root){
    stack<Node *> auxStack;
    Node *current = root;

    while (current != nullptr || !auxStack.empty()){
        // Reach the leftmost node of the current node
        while (current != nullptr){
            auxStack.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = auxStack.top();
        auxStack.pop();

        // Visit the node
        cout << current->data << " ";

        // Go to the right subtree
        current = current->right;
    }
}

void preOrder(Node *root){
    if (root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void preOrderIterative(Node *root){
    if (root == nullptr)
        return;

    stack<Node *> auxStack;
    Node *node;
    auxStack.push(root);

    while (!auxStack.empty()){
        node = auxStack.top();
        auxStack.pop();

        // Visit the node
        cout << node->data << " ";

        // Push right child first so that left child is processed first
        if (node->right != nullptr){
            auxStack.push(node->right);
        }

        if (node->left != nullptr){
            auxStack.push(node->left);
        }
    }
}
void preorderTraversalOptimal(Node *root){
    if (root == nullptr)
        return;

    stack<Node *> auxStack; // Stack to store right children
    Node *current = root;

    // Run till stack is not empty or current is not NULL
    while (!auxStack.empty() || current != nullptr){
        // Print left children while they exist and keep pushing right into the stack
        while (current != nullptr){
            cout << current->data << " ";

            if (current->right != nullptr){
                auxStack.push(current->right);
            }

            current = current->left;
        }

        // We reach when current is NULL, so we take out a right child from the stack
        if (!auxStack.empty()){
            current = auxStack.top();
            auxStack.pop();
        }
    }
}
void postOrder(Node *root){
    if (root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void postOrderTraversal_twoStack(Node *root){
    if (root == nullptr)
        return;

    stack<Node *> stack1, stack2;

    // Push root to the first stack
    stack1.push(root);

    // Run while the first stack is not empty
    while (!stack1.empty()){
        // Pop a node from the first stack and push it onto the second stack
        Node *node = stack1.top();
        stack1.pop();
        stack2.push(node);

        // Push left and right children of the popped node onto the first stack
        if (node->left){
            stack1.push(node->left);
        }
        if (node->right){
            stack1.push(node->right);
        }
    }

    // The second stack contains the nodes in postorder, so we print them
    while (!stack2.empty()){
        Node *node = stack2.top();
        stack2.pop();
        cout << node->data << " ";
    }
}
void postOrderTraversal_oneStack(Node *root){
    if (root == nullptr)
        return;

    stack<Node *> st;
    Node *current = root;
    Node *lastVisited = nullptr;

    while (!st.empty() || current != nullptr){
        // Go to the leftmost node
        while (current != nullptr){
            st.push(current);
            current = current->left;
        }

        // Peek the node at the top of the stack
        Node *topNode = st.top();

        // If the right child exists and traversing from the left child, move to the right child
        if (topNode->right != nullptr && lastVisited != topNode->right){
            current = topNode->right;
        }
        else{
            // Visit the node
            cout << topNode->data << " ";
            lastVisited = topNode;
            st.pop();
        }
    }
}
// Breadth-First Traversal

void levelOrder(Node *root){
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

int height(Node *root){
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Function to find the height of the tree
int height(Node* root, int &diameter) {
    if (root == nullptr) {
        return 0;
    }

    // Recursively get heights of left and right subtrees
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    // Update the diameter at this node
    diameter = max(diameter, leftHeight + rightHeight + 1);

    // Return the height of the tree at this node
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of the tree
int findDiameter(Node* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

// Insertion
Node *insert(Node *root, int data){
    if (root == nullptr){
        root = new Node(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *current = q.front();
        q.pop();

        if (current->left != nullptr){
            q.push(current->left);
        }
        else{
            current->left = new Node(data);
            return root;
        }

        if (current->right != nullptr){
            q.push(current->right);
        }
        else{
            current->right = new Node(data);
            return root;
        }
    }
    return root;
}

// Function to delete the deepest node in the tree
void deleteDeepest(Node* root, Node* d_node) {
    queue<Node*> q;
    q.push(root);

    // Use BFS to find the deepest node and delete it
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == d_node) {
            temp = nullptr;
            delete(d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = nullptr;
                delete(d_node);
                return;
            } else {
                q.push(temp->right);
            }
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = nullptr;
                delete(d_node);
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

// Function to delete a node with a specific key
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    // If the tree has only one node
    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
            delete(root);
            return nullptr;
        } else {
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node* key_node = nullptr;
    Node* temp;

    // Use BFS to find the target node and the deepest node
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key) {
            key_node = temp;
        }

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    // If the node to delete was found, replace it with the deepest node's value
    if (key_node != nullptr) {
        key_node->data = temp->data;
        deleteDeepest(root, temp);
    }
    return root;
}
int main(){
    Node *root = new Node(50); // Root node

    // Level 1
    root->left = new Node(30);
    root->right = new Node(70);

    // Level 2
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    // Level 3
    root->left->left->left = new Node(10);
    root->right->right->right = new Node(90);
    root->right->left->right = new Node(65);
    //
    //        50
    //       /  \
    //     30    70
    //    / \    / \
    //  20  40  60  80
    //  /        \   \
    // 10        65  90
    cout << findDiameter(root) << endl;
    postOrderTraversal_oneStack(root);
    return 0;
}