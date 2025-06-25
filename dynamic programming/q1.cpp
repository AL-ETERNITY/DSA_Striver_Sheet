// function to solve the Fibonacci problem using both top-down and bottom-up approaches
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    
    const int MOD = 1e9 + 7;
  
    long long int solve(int n, vector<long long int>& dp){
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp))%MOD;
    }

  public:
    long long int topDown(int n) {
        vector<long long int> dp(n + 1, -1);
        return solve(n, dp);
    }

    long long int bottomUp(int n) {
        if(n == 0) return 0;
        long long int prev2 = 0;
        long long int prev = 1;

        for(int i = 2; i <= n; i++){
            long long int curr = (prev + prev2)%MOD;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
