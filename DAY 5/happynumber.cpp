
class Solution {
public:
    int sumSquare(int x){
        if(x<9){
            return x*x;
        }
        int temp = x;
        int sum = 0;
        while(temp>=1){
            int dig = temp%10;
            sum += (dig*dig);
            temp = temp/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slowPointer = n;
        int fastPointer = sumSquare(n);
        while(fastPointer != 1 && fastPointer != slowPointer){
            slowPointer = sumSquare(slowPointer);
            fastPointer = sumSquare(sumSquare(fastPointer));
        }
        return fastPointer==1;    
    }
};