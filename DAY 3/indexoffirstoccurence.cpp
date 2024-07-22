#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        for(int i=0;i<haystack.size();i++){
            if(needle[0]==haystack[i]){
                index = i;
                int k = i;
                for(int j=0;j<needle.size();j++){
                    if(needle[j]!=haystack[k]){
                        index = -1;
                    }
                    k++;
                    if(k>haystack.size()){
                        break;
                    }
                }
                if(index!=-1){
                    return index;
                }
            }
        }

        return index; 
    }
};