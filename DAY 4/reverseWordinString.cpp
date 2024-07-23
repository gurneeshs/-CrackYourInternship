#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string newString = "";
        string temp = "";
        stack<string> st;

        for(int i=0;i<s.size();i++){
            
            if(s[i]==' '){
                if(temp==""){
                    // ignoring extra space
                    continue;
                }
                st.push(temp);
                temp = "";
            }
            else{
                temp+=s[i];
                if(i==s.size()-1){
                    st.push(temp);   
                }
            }
        }
        // st.pop();

        while(!st.empty()){
            string temp1 = st.top();
            st.pop();
            newString+=temp1;
            if(!st.empty()){
                newString+=" ";
            }

        }
        return newString;

    }
};