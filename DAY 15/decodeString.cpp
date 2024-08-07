#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &indx, string str){
        int n=0;
        string ans="";

        while(indx<str.size()){
            char curr=str[indx];
            if(curr>='0' && curr <='9'){
                n= n*10 + curr- '0';
            }
            else if( curr=='['){
                string temp=solve(++indx, str);
                while(n>0){
                    ans+= temp;
                    n--;
                }
            }
            else if(curr==']'){
                return ans;
            }
            else{
                ans+=curr;
            }
            indx++;
        }
        return ans;
        
    }
    string decodeString(string s) {
        int i=0;
        return solve(i,s);   
    }
};