#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize 2 strings
        string temp1=strs[0];
        string temp2="";

        for(int i=1;i<strs.size();i++){
            string temp = strs[i];
            // Comparing with previous string 
            for(int j=0;j<temp1.size();j++){
                if(temp1[j]==temp[j]){
                    temp2+=temp1[j];
                }
                else if(temp1[j]!=temp2[j]){
                    break;
                }
            }
            temp1 = temp2;
            temp2 = "";
        }   
        return temp1;
    }
};