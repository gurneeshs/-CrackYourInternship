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
    bool solve(TreeNode* root1, TreeNode* subRoot1){
        if(root1==NULL && subRoot1==NULL){
            return true;
        }
        if(root1==NULL || subRoot1==NULL){
            return false;
        } 
        if(root1->val!=subRoot1->val){
            return false;
        }
        return solve(root1->left,subRoot1->left) && solve(root1->right,subRoot1->right) ;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(subRoot==NULL){
        return true;
      }
      if(root==NULL){
        return false;
      }
      if(solve(root,subRoot)){
        return true;
      }
      return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};