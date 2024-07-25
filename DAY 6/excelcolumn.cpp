#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber>0){
            char ch = char(ceil((columnNumber-1)%26 + 65));
            ans = ch + ans;
            columnNumber = (columnNumber - 1)/26;
        }
        return ans;
    }
};