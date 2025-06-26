// function to solve the subset sum problem using dynamic programming
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Subset Sum problem
class Solution {
private:
    bool countDP(vector<int>& arr, int target, int index, vector<vector<int>>& dp) {
        if (target == 0) return true;

        if (index == 0) return arr[0] == target;

        if (dp[index][target] != -1) return dp[index][target];

        bool notTake = countDP(arr, target, index - 1, dp);
        bool take = false;
        if (arr[index] <= target)
            take = countDP(arr, target - arr[index], index - 1, dp);

        return dp[index][target] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return countDP(arr, sum, n - 1, dp);
    }
};

// bottom-up dynamic programming solution to the Subset Sum problem
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if (arr[i] <= j)
                    take = dp[i-1][j-arr[i]];
        
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};

// space-optimized bottom-up dynamic programming solution to the Subset Sum problem
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        
        if(arr[0] <= sum) prev[arr[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = prev[j];
                bool take = false;
                if (arr[i] <= j)
                    take = prev[j-arr[i]];
        
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
