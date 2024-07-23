#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // take two count openCount and closeCount
    // We can take opening bracket, if openCount < n
    // We can take close bracket, if closeCount < openCount
    // if openCount == closeCount, push the pattern into vector list
    void solve(vector<string>& v, int openCount, int closeCount, int n, string s){
        if(openCount==n && closeCount==n){
            v.push_back(s);
            return;
        }

        if(openCount < n){
            solve(v,openCount+1,closeCount,n,s+'(');
        }
        if(closeCount < openCount){
            solve(v,openCount,closeCount+1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,0,0,n,"");
        return ans;
    }
};