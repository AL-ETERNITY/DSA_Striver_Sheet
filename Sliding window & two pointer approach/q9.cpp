// function to solve the problem of counting subarrays with exactly k distinct integers
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    int subarraysWithKDistinctlteq(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int left = 0;
        int cnt = 0;
        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinctlteq(nums, k) - subarraysWithKDistinctlteq(nums, k - 1);
    }
};
