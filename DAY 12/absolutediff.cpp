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
    void inorder(TreeNode* root, vector<int> &inord){
        if(root==NULL){
            return;
        }
        inorder(root->left,inord);
        inord.push_back(root->val);
        inorder(root->right,inord);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        vector<int> inord;
        inorder(root,inord);

        for(int i=1;i<inord.size();i++){
            int diff = abs(inord[i] - inord[i-1]);
            mini = min(mini,diff);
        }
        return mini;



    }
};