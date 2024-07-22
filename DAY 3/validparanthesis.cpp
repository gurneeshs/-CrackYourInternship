#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('e');
        for(auto el:s){
            if(el=='(' || el=='{' || el=='['){
                st.push(el);
            }
            else{
                if(el==')'){
                    if(st.top()!='('){
                        return false;
                    }
                    st.pop();
                }
                else if(el=='}'){
                    if(st.top()!='{'){
                        return false;
                    }
                    st.pop();
                }
                else if(el==']'){
                    if(st.top()!='['){
                        return false;
                    }
                    st.pop();
                }
            }
        }
        if(st.top()=='e'){
            return true;
        }
        return false;
    }
};