// Problem: Given a set of coins of different denominations and a total amount of money, find the minimum number of coins needed to make up that amount. If that amount cannot be made up by any combination of the coins, return -1.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    public:
    int sol(vector<int>& coins, int sum,int ind,vector<vector<int>> & dp){
        if(sum ==0) return 0;
        if(ind == 0&& sum>0) return 1e6;
        
        if(dp[sum][ind]!=-1) return dp[sum][ind];
        
        int take =1e6;
        if(sum>=coins[ind-1])
            take = 1 + sol(coins,sum-coins[ind-1],ind,dp);
            
        int not_take = sol(coins,sum,ind-1,dp);
        
        return dp[sum][ind] = min(take,not_take);
    }
    int minCoins(vector<int>& coins, int sum) {
        int N = coins.size();
        vector<vector<int>> dp(sum+1,vector<int>(N+1,-1));
        int ans = sol(coins,sum,N,dp);
        return ans >=1e6 ? -1 : ans;
    }
};