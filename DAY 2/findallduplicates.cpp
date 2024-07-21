#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> retArr;
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                retArr.push_back(nums[i]);
            }
        }
        return retArr;
    }
};