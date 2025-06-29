// function to solve the problem of finding the length of the longest increasing subsequence in an array of integers.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(vector<int>& nums, int index, int prevIndex, int n, vector<vector<int>>& dp){
        if(index == n) return 0;

        if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex+1];

        int len = 0 + f(nums, index+1, prevIndex, n, dp);
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            len = max(len, 1 + f(nums, index+1, index, n, dp));
        }

        return dp[index][prevIndex+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(nums, 0, -1, n, dp);
    }
};