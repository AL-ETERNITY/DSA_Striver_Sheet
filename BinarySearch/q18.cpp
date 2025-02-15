#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (s <= e) {
            int divisor = s + (e - s) / 2;
            int quotient = 0;

            for (int i = 0; i < nums.size(); i++) {
                quotient += ceil((double)nums[i] / divisor);
            }

            if (quotient > threshold) {
                s = divisor + 1;
            } else {
                ans = divisor;
                e = divisor - 1; 
            }
        }
        return ans;
    }
};
