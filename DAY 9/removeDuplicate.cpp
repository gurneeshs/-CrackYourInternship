#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int> > st; // char,count

        for(auto ch:s){
            if(!st.empty() && st.top().first==ch){
                // Increment Count
                st.top().second++;
            }
            else{
                st.push({ch,1});
            }

            if(st.top().second == k){
                st.pop();
            }
        }

        string ans;
        while(!st.empty()){
            string topAns;
            topAns.append(st.top().second, st.top().first);
            cout<<st.top().first;
            ans = topAns+ans;
            st.pop();
        }
        return ans;


    }
};