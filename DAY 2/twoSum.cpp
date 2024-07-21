#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int siz= nums.size();

        for(int i=0;i<siz;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<siz;i++){
            int comp = target - nums[i];
            if(mp.count(comp) && mp[comp]!=i){
                return {i,mp[comp]};
            }
        }
        return {};
    }
};