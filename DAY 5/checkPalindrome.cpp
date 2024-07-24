#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            long long int reverse = 0;
            long long int temp = x;
            while(temp>=1){
                int digit = temp%10;
                reverse = (reverse*10)+digit;
                temp = temp/10;
            }

            if(reverse==x){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
};