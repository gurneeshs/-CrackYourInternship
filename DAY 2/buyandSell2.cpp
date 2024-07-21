#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices,int index, int buy){
        // base case
        if(index == prices.size()){
            return 0;
        }

        int profit = 0;
        if(buy){
            profit = max((-prices[index]+solve(prices,index+1,0)),(0 + solve(prices,index+1,1)));
        }
        else{
            profit = max((prices[index]+solve(prices,index+1,1)),(0 + solve(prices,index+1,0)));        
        }
        return profit;
    }
    int solveMem(vector<int>& prices,int index, int buy, vector<vector<int> >& dp){
        // base case
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy){
            profit = max((-prices[index]+solveMem(prices,index+1,0,dp)),(0 + solveMem(prices,index+1,1,dp)));
        }
        else{
            profit = max((prices[index]+solveMem(prices,index+1,1,dp)),(0 + solveMem(prices,index+1,0,dp)));        
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int>& prices){
        int n  = prices.size();
        vector<vector<int> > dp(n+1, vector<int>(2,0));

        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[index]+ dp[index+1][0]),(0 + dp[index+1][1]));
                }
                else{
                    profit = max((prices[index]+dp[index+1][1]),(0 + dp[index+1][0]));        
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];

    }
    int solveSO(vector<int>& prices){
        int n  = prices.size();
        // vector<vector<int> > dp(2, vector<int>(2,0));

        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max((-prices[index]+ next[0]),(0 + next[1]));
                }
                else{
                    profit = max((prices[index]+next[1]),(0 + next[0]));        
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];

    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,1);
        // int n  = prices.size();
        // vector<vector<int> > dp(n, vector<int>(2,-1));
        // return solveMem(prices,0,1,dp);
        // return solveTab(prices);
        return solveSO(prices);
    }
};