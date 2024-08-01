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
    int heightBalanced(TreeNode* node, int &flag){
        if(node==NULL){
            return 0;
        }
        int leftHeight = heightBalanced(node->left,flag);
        int rightHeight = heightBalanced(node->right,flag);

        if(leftHeight-rightHeight>1 || rightHeight-leftHeight>1){
            flag = 1;
        }
        return 1 + max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int flag = 0;
        int height = heightBalanced(root,flag);
        if(flag){
            return false;
        }
        else{
            return true;
        }
    }
};