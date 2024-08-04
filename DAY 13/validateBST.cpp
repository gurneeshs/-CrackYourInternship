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
public:
    void inorder(TreeNode* root, vector<int>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        if(arr.size()<=1){
            return true;
        }

        for(int i=1;i<arr.size();i++){
            if(arr[i] <= arr[i-1]){
                return false;
            }
        }
        return true;
    }
};