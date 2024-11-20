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
    void flatten(TreeNode* root){
        flattenize(root);
        return;
    }
    TreeNode* flattenize(TreeNode* root) {
        if(!root->left && !root->right) return root;
        if(!root->left){
            root->right=flattenize(root->right);
        }else{
            TreeNode*right=root->right,*left=root;
            root->right=flattenize(root->left);
            root->left=nullptr;
            while(left->right){
                left=left->right;
            }
            left->right=flattenize(right);
        }
        return root;
    }
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
    vector<int> preorder{1, 2, 3, 4, 5, 6}, inorder{3,2,4,1,5,6};
    TreeNode *root = a.buildTree(preorder, inorder);
    inOrder(root);
    cout<<endl;
    a.flatten(root);
    inOrder(root);
    cout<<endl;
}