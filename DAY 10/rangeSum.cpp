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
    void findSum(TreeNode* root, int low, int high, int &sum){
        if(root==NULL){
            return;
        }
        findSum(root->left,low,high,sum);
        if(low<=root->val && root->val<=high){
            sum+=root->val;
        }
        findSum(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        findSum(root,low,high,sum);
        return sum;
    }
};