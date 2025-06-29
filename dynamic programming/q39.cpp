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

// bottom-up dynamic programming approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int prevIndex = index-1; prevIndex >= -1; prevIndex--){
                int len = 0 + dp[index+1][prevIndex+1];
                if(prevIndex == -1 || nums[index] > nums[prevIndex]){
                    len = max(len, 1 + dp[index+1][index+1]);
                }
                dp[index][prevIndex+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};

// space optimized bottom-up dynamic programming approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int index = n-1; index >= 0; index--){
            for(int prevIndex = index-1; prevIndex >= -1; prevIndex--){
                int len = 0 + next[prevIndex+1];
                if(prevIndex == -1 || nums[index] > nums[prevIndex]){
                    len = max(len, 1 + next[index+1]);
                }
                curr[prevIndex+1] = len;
            }
            next = curr;
        }
        return next[-1+1];
    }
};

// even more space optimized bottom-up dynamic programming approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);  // Initialize dp array with 1s
        int maxLength = 1;  // At least one element is always an increasing subsequence
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};