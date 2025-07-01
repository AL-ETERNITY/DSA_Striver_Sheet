// function to solve the problem of bursting balloons to maximize coins
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming approach to solve the problem of bursting balloons to maximize coins
class Solution {
private:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for(int index = i; index <= j; index++){
            int coins = nums[i-1]*nums[index]*nums[j+1] + f(i, index-1, nums, dp) + f(index + 1, j, nums, dp);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    }
};

// bottom-up dynamic programming approach to solve the problem of bursting balloons to maximize coins
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;
                int maxi = INT_MIN;
                for (int index = i; index <= j; index++) {
                    int coins = nums[i - 1] * nums[index] * nums[j + 1] 
                                + dp[i][index - 1] 
                                + dp[index + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};