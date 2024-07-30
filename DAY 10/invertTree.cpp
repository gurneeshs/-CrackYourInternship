#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // swap left and right child
public:
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (!root->left && !root->right)){
            return root;
        }
        solve(root);
        return root;

    }
};