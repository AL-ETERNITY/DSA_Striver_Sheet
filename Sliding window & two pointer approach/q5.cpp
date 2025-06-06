// function to find the number of subarrays with a sum equal to a given goal
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int numSubarraysWithSumlteq(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int left = 0;
        int cnt = 0;
        int sum = 0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum>goal){
                sum -= nums[left];
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int goallteqgoal = numSubarraysWithSumlteq(nums,goal);
        int goallteqgoalminusone = numSubarraysWithSumlteq(nums,goal-1);
        int ans = goallteqgoal - goallteqgoalminusone;
        return ans;
    }
};