// function to solve the problem of finding the largest divisible subset
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxLength = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxLength){
                maxLength = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};