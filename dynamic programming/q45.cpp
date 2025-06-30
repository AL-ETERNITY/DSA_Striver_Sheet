// function to solve the problem of finding the number of longest increasing subsequences in a given array of integers.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n,1); 
        int maxLength = 1;  
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && 1 + dp[prev] > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if(nums[i] > nums[prev] && 1 + dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxLength) ans += cnt[i];
        }

        return ans;
    }
};