// function to solve the problem of jumping game
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIndex) return false;
            maxIndex = max(maxIndex,i+nums[i]);
        }
        return true;
    }
};