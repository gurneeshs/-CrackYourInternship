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
    TreeNode* insertNode(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = left + (right-left)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = insertNode(nums,left, mid-1);
        newNode->right = insertNode(nums,mid+1,right);

        return newNode;


    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insertNode(nums,0,nums.size()-1);
    }
};