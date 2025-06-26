// function to solve the problem of robbing houses in a circular street
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rob1(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int prev = arr[0], prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = arr[i] + (i > 1 ? prev2 : 0);
            int nottake = prev;
            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> temp2(nums.begin(), nums.end() - 1);

        return max(rob1(temp1), rob1(temp2));
    }
};
