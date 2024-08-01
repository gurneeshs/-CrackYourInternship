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

class BSTIterator {
    
public:
    vector<TreeNode*> inorderList;

    void inorder(TreeNode* root, vector<TreeNode*>& lst){
        if(!root){
            return;
        }
        inorder(root->left,lst);
        lst.push_back(root);
        inorder(root->right,lst);

    }
    int start = 0;
    BSTIterator(TreeNode* root) {
        inorder(root,inorderList);
    }
    
    int next() {
        int nxt = inorderList[start]->val;
        start++;
        return nxt;
    }
    
    bool hasNext() {
        if(start < inorderList.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */