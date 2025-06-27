// function to solve the coin change problem 
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Coin Change problem
class Solution {
private:
    int f(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        if (index == 0) {
            return (amount % coins[0] == 0);
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        int notTake = f(coins, amount, index - 1, dp);

        int take = 0;
        if (coins[index] <= amount) {
            take = f(coins, amount - coins[index], index, dp);
        }

        return dp[index][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(coins, amount, n - 1, dp);
    }
};

// bottom-up dynamic programming solution to the Coin Change problem
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        // Initialize base case for first coin
        for(int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                unsigned long long notTake = dp[i - 1][j];
                unsigned long long take = 0;
                if (coins[i] <= j) {
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};

// space-optimized bottom-up dynamic programming solution to the Coin Change problem
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, 0), curr(amount + 1, 0);  // changed to long long

        // Base case: ways to make amounts using only the first coin
        for(int i = 0; i <= amount; i++) {
            prev[i] = (i % coins[0] == 0);
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                unsigned long long notTake = prev[j];
                unsigned long long take = 0;
                if (coins[i] <= j) {
                    take = curr[j - coins[i]];
                }
                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};
