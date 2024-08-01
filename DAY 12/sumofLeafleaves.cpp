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
    void solve(TreeNode* root, bool isLeft, int& sum){
        if(!root->left && !root->right){
            if(isLeft){
                sum += root->val;
                return;
            }
            else{
                return;
            }
        }

        if(root->left){
            solve(root->left,true,sum);
        }
        if(root->right){
            solve(root->right,false,sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,false,sum);
        return sum;
        
    }
};