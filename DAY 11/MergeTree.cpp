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
    TreeNode* solve(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2==NULL){
            return NULL;
        }
        if(r1 && r2){
            r1->val = r1->val+r2->val;
        }
        else{
            if(r1 && !r2){
                r1->left = solve(r1->left,NULL);
                r1->right = solve(r1->right,NULL);
                return r1;
            }
            else if(!r1 && r2){
                r2->left = solve(NULL,r2->left);
                r2->right = solve(NULL,r2->right);
                return r2;
            }
        }
        r1->left = solve(r1->left,r2->left);
        r1->right = solve(r1->right,r2->right);

        return r1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){
            return NULL;
        }
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }
        
        return solve(root1, root2);
    }
};