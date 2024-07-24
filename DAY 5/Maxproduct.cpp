#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3){
            return nums[2]*nums[1]*nums[0];
        }
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;

        int Min1 = nums[0];
        int Min2 = nums[1];


        int Max1 = nums[n];
        int Max2 = nums[n-1];
        int Max3 = nums[n-2];

        int p1 = Max1 * Max2 * Max3;
        int p2 = Max1 * Min1 * Min2;
        return max(p1,p2);

    }
};