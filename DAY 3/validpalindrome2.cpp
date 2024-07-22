#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s, int st, int end){
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        int ignore = 0;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(s[i]!=s[j]){
                // ignoring ith non match and ignoring jth non match
                return check(s,i+1,j) || check(s,i,j-1);
            }
        }   
        return true;
    }
};