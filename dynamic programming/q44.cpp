// function to solve the problem of finding the longest bitonic subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp1[i] = max(dp1[i], dp1[prev] + 1);
                }
            }
        }

        vector<int> dp2(n, 1);
        for (int i = n-1; i >= 0; i--) {
            for (int next = n-1; next > i; next--) {
                if (nums[i] > nums[next]) {
                    dp2[i] = max(dp2[i], dp2[next] + 1);
                }
            }
        }
        
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(dp1[i] != 1 && dp2[i] != 1)
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
        
        return maxi;
    }
};
