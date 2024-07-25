
class Solution {
    // if a number is power of 2, it has exactly only 1 bit set to 1;
    // and if we subtract 1 from it, remaining bits set to 1 and this bit set to 0;
    // eg: 4(0100) 3(0011) [4 & 3 == 0]
public:
    bool isPowerOfTwo(int n) {
        if(n>=1 && (n & (n-1))==0){
            return true;
        }
        return false;
    }
};