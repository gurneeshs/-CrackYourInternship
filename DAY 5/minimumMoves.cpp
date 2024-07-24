#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // take minimum from array and subtract it from each element
    // the answer is sum of array elements
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto el:nums){
            mini = min(mini,el);
        }

        int ans = 0;
        for(auto el:nums){
            ans += (el-mini);
        }
        return ans;
    }
};