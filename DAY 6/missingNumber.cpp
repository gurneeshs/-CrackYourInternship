#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // vector<int> temp(n+1,0);
        // for(auto el:nums){
        //     temp[el] = 1;
        // }

        // for(int i=0;i<=n;i++){
        //     if(temp[i]==0){
        //         return i;
        //     }
        // }
        // return 0;

        // Sum Approach
        int sum = (n*(n+1))/2;
        int sum2 = 0;

        for(int i=0;i<n;i++){
            sum2 += nums[i];
        }
        return sum - sum2;
    }
};