#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                ans.push_back(mp[complement]); 
                ans.push_back(i);             
                break;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};
