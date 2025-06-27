// function to solve the problem of counting partitions with a given difference
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the countPartitions problem
class Solution {
  private:
    int countDP(vector<int> &arr, int target, int index, vector<vector<int>> &dp) {
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if (dp[index][target] != -1) return dp[index][target];

        int take = 0;
        if (arr[index] <= target)
            take = countDP(arr, target - arr[index], index - 1, dp);

        int notTake = countDP(arr, target, index - 1, dp);

        return dp[index][target] = take + notTake;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return countDP(arr, target, n - 1, dp);
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        int total_sum = 0;
        for(auto &it : arr) total_sum += it;
        if((total_sum-d) < 0 || (total_sum-d)%2 != 0) return 0;
        return perfectSum(arr, (total_sum-d)/2);
    }
};

// bottom-up dynamic programming solution to the countPartitions problem
class Solution {
  private:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = 1;

        if (arr[0] == 0)
            dp[0][0] = 2;
        else if (arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int take = 0;
                if (arr[i] <= sum)
                    take = dp[i - 1][sum - arr[i]];

                int notTake = dp[i - 1][sum];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        int total_sum = 0;
        for(auto &it : arr) total_sum += it;
        if((total_sum-d) < 0 || (total_sum-d)%2 != 0) return 0;
        return perfectSum(arr, (total_sum-d)/2);
    }
};

// space-optimized dynamic programming solution to the countPartitions problem
class Solution {
  private:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target+1,0), curr(target+1,0);

        prev[0] = curr[0] = 1;

        if (arr[0] == 0)
            prev[0] = 2;
        else if (arr[0] <= target)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int take = 0;
                if (arr[i] <= sum)
                    take = prev[sum - arr[i]];

                int notTake = prev[sum];

                curr[sum] = take + notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
    
  public:
    int countPartitions(vector<int>& arr, int d) {
        int total_sum = 0;
        for(auto &it : arr) total_sum += it;
        if((total_sum-d) < 0 || (total_sum-d)%2 != 0) return 0;
        return perfectSum(arr, (total_sum-d)/2);
    }
};