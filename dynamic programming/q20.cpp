// function to solve the problem of finding the number of ways to assign signs to make the sum equal to a target value.
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        if (arr[0] == 0)
            dp[0][0] = 2;  // Take or not take zero
        else
            dp[0][0] = 1;  // Only not take

        if (arr[0] != 0 && arr[0] <= target)
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

    int countPartitions(vector<int>& arr, int d) {
        int total_sum = 0;
        for (int num : arr) total_sum += num;

        if ((total_sum - d) < 0 || (total_sum - d) % 2 != 0)
            return 0;

        int target = (total_sum - d) / 2;
        return perfectSum(arr, target);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};
