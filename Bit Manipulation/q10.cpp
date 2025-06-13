// // Problem: Given a non-empty array of integers, every element appears twice except for one. Find that single one.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};