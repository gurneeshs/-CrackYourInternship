#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1;
        int j = b.size()-1;
        int car = 0;
        int sum = 0;
        while(i>=0 && j>=0){
            int n1 = a[i]-'0';
            int n2 = b[j]-'0';
            sum = n1 + n2 + car;
            if(sum>1){
                car = 1;
                sum = sum-2;
            }
            else{
                car = 0;
            }

            if(sum){
                ans += "1";
            }
            else{
                ans += "0";
            }
            sum = 0;
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0){
                int n1 = a[i]-'0';
                sum = n1 + car;
                if(sum>1){
                    car = 1;
                    sum = sum-2;
                }
                else{
                    car = 0;
                }
                ans += to_string(sum);
                sum = 0;
                i--;
            }
        }
        if(j>=0){
            while(j>=0){
                int n1 = b[j]-'0';
                sum = n1 + car;
                if(sum>1){
                    car = 1;
                    sum = sum-2;
                }
                else{
                    car = 0;
                }
                ans += to_string(sum);
                sum = 0;
                j--;
            }
        }
        if(car==1){
            ans += to_string(car);
            car = 0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};