#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        map<int,int> m;

        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }

            if(st.empty()){
                m[nums2[i]] = -1;
            }
            else{
                m[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<n1;i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};