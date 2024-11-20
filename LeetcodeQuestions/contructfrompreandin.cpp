#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inOrder(TreeNode *root){
    if (root != nullptr){
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
void preOrder(TreeNode *root){
    if (root != nullptr){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
class Solution{
public:
    TreeNode *buildTree(vector<int> &preorder, int &m, vector<int> &inorder, int i, int j,unordered_map<int,int>&mapper){
        if (i > j) return nullptr;
        if (i == j){
            m++;
            return new TreeNode(inorder[i]);
        }
        int k=mapper[preorder[m++]];
        TreeNode *left = buildTree(preorder, m, inorder, i, k - 1,mapper);
        TreeNode *right = buildTree(preorder, m, inorder, k + 1, j,mapper);
        return new TreeNode(inorder[k], left, right);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int m = 0;
        unordered_map<int,int> mapper;
        for(int i=0;i<inorder.size();i++)mapper[inorder[i]]=i;
        return buildTree(preorder, m, inorder, 0, inorder.size() - 1,mapper);
    }
};
int main(){
    Solution a;
    vector<int> preorder{5, 2, 1, 3, 4, 7, 6, 9, 8, 10}, inorder{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *root = a.buildTree(preorder, inorder);
    inOrder(root);
    preOrder(root);
}