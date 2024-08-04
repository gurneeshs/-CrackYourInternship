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
//  Approach
/*
    1. Create a mapping for node to parent
    2. Since refrence of target is given you can directly start from target
*/
class Solution {
public:
    void findParent(TreeNode* root, map<TreeNode*,TreeNode*>& nodeToParent){
        if(root==NULL){
            return;
        }
        nodeToParent[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frnt = q.front();
            q.pop();

            if(frnt->left){
                q.push(frnt->left);
                nodeToParent[frnt->left] = frnt;
            }
            if(frnt->right){
                q.push(frnt->right);
                nodeToParent[frnt->right] = frnt;
            }

        }
    }
    void findAns(TreeNode* target, int k, map<TreeNode*, TreeNode*>& nodeToParent, map<TreeNode*,bool>& visited, vector<int>&ans){

        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        // visited[target] = true;

        while(!q.empty()){
            TreeNode* frnt = q.front().first;
            int currDis = q.front().second;
            q.pop();

            if(currDis==k && !visited[frnt]){
                ans.push_back(frnt->val);
            }
            visited[frnt] = true;

            if(frnt->left && !visited[frnt->left]){
                q.push({frnt->left,currDis+1});
            }
            if(frnt->right && !visited[frnt->right]){
                q.push({frnt->right,currDis+1});
            }
            if(nodeToParent[frnt] && !visited[nodeToParent[frnt]]){
                q.push({nodeToParent[frnt],currDis+1});
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<TreeNode*, bool> visited;
        map<TreeNode*, TreeNode*> nodeToParent; //{node,parent};
        findParent(root,nodeToParent);
        
        findAns(target,k,nodeToParent,visited,ans);
        return ans;
        
    }
};