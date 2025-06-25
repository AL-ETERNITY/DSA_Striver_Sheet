// function to solve the problem of minimizing the cost of jumping through an array
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to minimize the cost of jumping through an array
class Solution {
private:
    int solve(vector<int>& arr, vector<int>& dp, int k, int index) {
        if(index == 0) return 0;

        if(dp[index] != -1) return dp[index];

        int mini = INT_MAX;
        for(int i = 1; i <= k; i++) {
            if(index - i >= 0) {
                int cost = solve(arr, dp, k, index - i) + abs(arr[index] - arr[index - i]);
                mini = min(mini, cost);
            }
        }
        return dp[index] = mini;
    }

public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, dp, k, n - 1);
    }
};

// bottom-up dynamic programming solution to minimize the cost of jumping through an array
class Solution {
public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for(int i=1;i<arr.size();i++){
            int mini = INT_MAX;
            for(int jumps = 1; jumps<=k; jumps++){
                if(i-jumps >= 0){
                    int cost = dp[i-jumps] + abs(arr[i] - arr[i - jumps]);
                    mini = min(mini,cost);
                }
            }
            dp[i] = mini;
        }
        return dp[n-1];
    }
};

