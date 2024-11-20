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
        preOrder(root->left);
        preOrder(root->right);
        cout << root->val << " ";
    }
}
class Solution{
public:
    TreeNode *buildTree(vector<int> &postorder, int &m, vector<int> &inorder, int i, int j,unordered_map<int,int>&mapper){
        if (i > j) return nullptr;
        if (i == j){
            m--;
            return new TreeNode(inorder[i]);
        }
        int k=mapper[postorder[m--]];
        TreeNode *right = buildTree(postorder, m, inorder, k + 1, j,mapper);
        TreeNode *left = buildTree(postorder, m, inorder, i, k - 1,mapper);
        return new TreeNode(inorder[k], left, right);
    }
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size()-1;
        unordered_map<int,int> mapper;
        for(int i=0;i<inorder.size();i++)mapper[inorder[i]]=i;
        return buildTree(postorder, m, inorder, 0, m,mapper);
    }
};
int main(){
    Solution a;
    vector<int> postorder{9,3,15,20,7}, inorder{9,15,7,20,3};
    TreeNode *root = a.buildTree(postorder, inorder);
    inOrder(root);
    preOrder(root);
}