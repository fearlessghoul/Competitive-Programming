#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = nullptr;
        color = RED; // New nodes are always RED initially
    }
};

class RedBlackTree {
private:
    Node *root;
    Node *NIL; // NIL (Leaf) nodes are always BLACK

    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        if (x->right != NIL) x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node *z) {
        while (z->parent && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right; // Uncle node
                if (y->color == RED) { // Case 1: Uncle is RED
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) { // Case 2: z is right child
                        z = z->parent;
                        leftRotate(z);
                    }
                    // Case 3: z is left child
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else { // Same as above, but mirror image
                Node *y = z->parent->parent->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node *u, Node *v) {
        if (!u->parent) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    Node* minimum(Node* node) {
        while (node->left != NIL)
            node = node->left;
        return node;
    }

    void fixDelete(Node *x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {  // If x is a left child
                Node *w = x->parent->right; // Sibling of x

                // Case 1: Sibling w is red
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }

                // Case 2: Sibling w is black and both its children are black
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;  // Move problem upwards
                } else {
                    // Case 3: Sibling w is black, and its left child is red, but right child is black
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }

                    // Case 4: Sibling w is black, and its right child is red
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;  // Fix is complete
                }
            } else {  // Mirror case: x is a right child
                Node *w = x->parent->left; // Sibling of x

                // Case 1: Sibling w is red
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }

                // Case 2: Sibling w is black and both children are black
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;  // Move problem upwards
                } else {
                    // Case 3: Sibling w is black, and its right child is red, but left child is black
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }

                    // Case 4: Sibling w is black, and its left child is red
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;  // Fix is complete
                }
            }
        }
        x->color = BLACK;  // Ensure x is black to maintain balance
    }

    void deleteNode(Node *z) {
        Node *y = z, *x;
        Color yOriginalColor = y->color;  // Store the original color of y

        if (z->left == NIL) {  // Case 1: z has no left child
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {  // Case 2: z has no right child
            x = z->left;
            transplant(z, z->left);
        } else {  // Case 3: z has two children
            y = minimum(z->right);  // Find successor
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z)
                x->parent = y;  // Maintain parent reference
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;  // Copy color

        }

        // If deleted node was black, fix potential violations
        if (yOriginalColor == BLACK)
            fixDelete(x);
    }


    void inorder(Node *node) {
        if (node == NIL) return;
        inorder(node->left);
        cout << node->data << " (" << (node->color == RED ? "R" : "B") << ") ";
        inorder(node->right);
    }

public:
    RedBlackTree() {
        NIL = new Node(0);
        NIL->color = BLACK;
        root = NIL;
    }

    void insert(int data) {
        Node *z = new Node(data);
        Node *y = nullptr, *x = root;
        while (x != NIL) {
            y = x;
            x = (z->data < x->data) ? x->left : x->right;
        }
        z->parent = y;
        if (!y) root = z;
        else if (z->data < y->data) y->left = z;
        else y->right = z;
        z->left = z->right = NIL;
        fixInsert(z);
    }

    void remove(int data) {
        Node *z = root;
        while (z != NIL && z->data != data)
            z = (data < z->data) ? z->left : z->right;
        if (z != NIL)
            deleteNode(z);
    }

    void inorder() { inorder(root); cout << endl; }
};

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    cout << "Inorder before deletion: ";
    rbt.inorder();

    rbt.remove(20);
    cout << "Inorder after deletion of 20: ";
    rbt.inorder();

    return 0;
}
