// function to solve the problem of robbing houses without alerting the police
#include<bits/stdc++.h>
using namespace std;

// bottom-up dynamic programming solution to the House Robber problem
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += dp[i-2];

            int nottake = 0 + dp[i-1];

            dp[i] = max(take,nottake);
        }
        return dp[n-1];
    }
};

// space-optimized bottom-up dynamic programming solution to the House Robber problem
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;

            int nottake = 0 + prev;

            int curr = max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};