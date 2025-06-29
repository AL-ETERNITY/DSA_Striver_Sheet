// function to solve the problem of maximizing profit from stock trading with at most two transactions
#include <bits/stdc++.h>
using namespace std;

// recursive function to calculate maximum profit from stock prices with at most two transactions
class Solution {
private:
    int f(vector<int>& prices, int index, int buy, int cap, int n){
        if(index == n || cap == 0){
            return 0;
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[index] + f(prices, index + 1, 0, cap, n), 0 + f(prices, index+1, 1, cap, n));
        }
        else{
            profit = max(prices[index] + f(prices, index+1, 1, cap-1, n), 0 + f(prices, index+1, 0, cap, n));
        }

        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(prices, 0, 1, 2, n);
    }
};

// top-down dynamic programming approach
class Solution {
private:
    int f(vector<int>& prices, int index, int buy, int cap, int n, vector<vector<vector<int>>>& dp){
        if(index == n || cap == 0){
            return 0;
        }
        
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];


        int profit = 0;
        if(buy){
            profit = max(-prices[index] + f(prices, index + 1, 0, cap, n, dp), 0 + f(prices, index+1, 1, cap, n, dp));
        }
        else{
            profit = max(prices[index] + f(prices, index+1, 1, cap-1, n, dp), 0 + f(prices, index+1, 0, cap, n, dp));
        }

        return dp[index][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3, -1)));
        return f(prices, 0, 1, 2, n, dp);
    }
};

// bottom-up dynamic programming approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {  // cap starts from 1 to avoid -1 index
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                    } else {
                        profit = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
                    }

                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2]; // start from day 0, buying allowed, 2 transactions allowed
    }
};

// space optimized bottom-up dynamic programming approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // after[buy][cap]: profit on the next day with 'buy' status and 'cap' transactions left
        vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        curr[buy][cap] = max(
                            -prices[i] + after[0][cap],  // buy
                            0 + after[1][cap]            // skip
                        );
                    } else {
                        curr[buy][cap] = max(
                            prices[i] + after[1][cap - 1],  // sell
                            0 + after[0][cap]               // skip
                        );
                    }
                }
            }
            after = curr;  // move to the previous day
        }

        return after[1][2];  // start with buy allowed and 2 transactions
    }
};
