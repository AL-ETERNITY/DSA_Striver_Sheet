// function to solve the Coin Change problem using memoization
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Coin Change problem
class Solution {
private:
    const int INF = 1e9;  // large constant instead of INT_MAX

    int f(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return INF;
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        int notTake = f(coins, amount, index - 1, dp);
        int take = INF;

        if (coins[index] <= amount) {
            take = 1 + f(coins, amount - coins[index], index, dp);
        }

        return dp[index][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins, amount, n - 1, dp);
        return (ans == INF) ? -1 : ans;
    }
};

// bottom-up dynamic programming solution to the Coin Change problem
class Solution {
private:
    const int INF = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Initialize base case for first coin
        for(int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = INF;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = dp[i - 1][j];
                int take = INF;
                if (coins[i] <= j) {
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans == INF) ? -1 : ans;
    }
};

// bottom-up dynamic programming solution to the Coin Change problem using space optimization
class Solution {
private:
    const int INF = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);

        // Initialize base case for first coin
        for(int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = INF;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = INF;
                if (coins[i] <= j) {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return (ans == INF) ? -1 : ans;
    }
};
