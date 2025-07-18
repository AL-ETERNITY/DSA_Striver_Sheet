// function to solve the problem of maximizing profit from stock prices with cooldown period
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));  // fix: n+2 rows

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } 
                else {
                    profit = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
