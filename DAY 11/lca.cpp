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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
        if(root==NULL){
            return NULL;
        }

        if((P->val<root->val && Q->val>root->val) ||(P->val>root->val && Q->val<root->val)){
            return root;        
        }
        else if(P->val==root->val || Q->val==root->val){
            return root;
        }

        else if(P->val<root->val && Q->val<root->val){
            return lowestCommonAncestor(root->left,P,Q);
        }
        else{
            return lowestCommonAncestor(root->right,P,Q);
        }
    }
};