#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        vector<int> ans;

        // Separate positive and negative numbers
        for (int num : nums) {
            if (num > 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }

        // Merge positive and negative numbers alternatively
        int posIdx = 0, negIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans.push_back(positive[posIdx++]);
            } else {
                ans.push_back(negative[negIdx++]);
            }
        }

        return ans;
    }
};
