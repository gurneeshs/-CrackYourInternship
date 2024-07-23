#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string> > m;

        for(auto strng:strs){
            string temp = strng;
            sort(temp.begin(),temp.end());
            m[temp].push_back(strng);
        }

        for(auto key:m){
            vector<string> temp;
            for(auto el:key.second){
                temp.push_back(el);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};