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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;    
        }
        map<int,int> m;
        queue<pair<TreeNode*, int> > q;
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* frnt= q.front().first;
            int levl  = q.front().second;
            q.pop();
            
            m[levl] = frnt->val;
            
            if(frnt->left){
                q.push({frnt->left,levl+1});
            }
            if(frnt->right){
                q.push({frnt->right,levl+1});
            }
        }
        for(auto el:m){
            ans.push_back(el.second);
        }
        return ans;
    }
};