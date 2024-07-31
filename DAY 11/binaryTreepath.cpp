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
    void solve(TreeNode* root, vector<string>& ans, string s){
        if(!root){
            return;
        }
        if(!(root->left) && !(root->right)){
            // s += "->";
            s += to_string(root->val);
            ans.push_back(s);
            cout<<"pushed";
            return;
        }
        s += to_string(root->val);
        s += "->";

        if(root->left){
            cout<<s;
            solve(root->left,ans,s);
            cout<<endl;
        }
        if(root->right){
            cout<<s;
            solve(root->right,ans,s);
            cout<<endl;
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL){
            return ans;
        }
        if(!root->left && !root->right){
            ans.push_back(to_string(root->val));
            return ans;
        }
        solve(root,ans,"");
        return ans;

    }   
};