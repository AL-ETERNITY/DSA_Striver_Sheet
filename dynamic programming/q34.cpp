// function to solve the problem of maximum profit from stock prices with buy/sell options
#include <bits/stdc++.h>
using namespace std;

// recursive function to calculate maximum profit from stock prices
class Solution {
private:
    int f(vector<int>& prices, int index, int buy, int n){
        if(index == n){
            return 0;
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[index] + f(prices, index + 1, 0, n), 0 + f(prices, index+1, 1, n));
        }
        else{
            profit = max(prices[index] + f(prices, index+1, 1, n), 0 + f(prices, index+1, 0, n));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(prices, 0, 1, n);
    }
};

// top-down dynamic programming approach
class Solution {
private:
    int f(vector<int>& prices, int index, int buy, int n, vector<vector<int>>& dp){
        if(index == n){
            return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[index] + f(prices, index + 1, 0, n, dp), 0 + f(prices, index+1, 1, n, dp));
        }
        else{
            profit = max(prices[index] + f(prices, index+1, 1, n, dp), 0 + f(prices, index+1, 0, n, dp));
        }

        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(prices, 0, 1, n, dp);
    }
};

// bottom-up dynamic programming approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0), curr(2,0);

        ahead[0] = ahead[1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                } 
                else {
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
};
