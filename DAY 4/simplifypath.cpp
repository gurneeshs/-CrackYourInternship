#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // use stack to solve problem

    string simplifyPath(string path) {
        stack<string> s;
        string ans;

        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }

            string temp;
            while(i<path.size() && path[i]!='/'){
                temp += path[i];
                i++;
            }

            if(temp=="."){
                // ignore .
                continue;
            }
            else if(temp==".."){
                // one directory up
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(temp);
            }
        }   
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        if(ans.size()==0){
            return "/";
        }
        return ans;
    }
};