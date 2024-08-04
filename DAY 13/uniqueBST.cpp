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
    vector<TreeNode*> solve(int st, int end, map<pair<int,int>, vector<TreeNode*>>& dp ){
        if(st>end){
            return dp[{st,end}] = {NULL};
        }
        if(st==end){
            TreeNode* temp = new TreeNode(st);
            return dp[{st,end}] = {temp};
        }
        if(dp.find({st,end})!=dp.end()){
            return dp[{st,end}];
        }
        vector<TreeNode*> Result;
        for(int i = st;i<=end;i++){
            // root is i
            auto leftTree = solve(st,i-1,dp);
            auto rightTree = solve(i+1,end,dp);

            for(auto node:leftTree){
                for(auto nd:rightTree){
                    auto root = new TreeNode(i);
                    root->left = node;
                    root->right = nd;
                    Result.push_back(root);
                }
            }
        }
        return dp[{st,end}] = Result;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>, vector<TreeNode*> > dp;
        return solve(1,n,dp);

    }
};