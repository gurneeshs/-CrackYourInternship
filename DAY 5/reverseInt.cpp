#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while(x!=0){
            int digit = x%10;
            if(reverse>INT32_MAX/10 || reverse<INT32_MIN/10){
                return 0;
            }
            reverse = reverse*10+digit;
            x=int(x/10);
        }
        return reverse;
    }
};
