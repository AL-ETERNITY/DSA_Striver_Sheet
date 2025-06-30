// function to solve the problem of finding the longest increasing subsequence (LIS) in an array
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n);
        int maxLength = 1;
        int lastIndex = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev] && dp[i] < dp[prev] + 1) {
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
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};