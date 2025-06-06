// function to find the number of subarrays with exactly k odd numbers
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
            sum += nums[right]%2;
            while(sum>goal){
                sum -= nums[left]%2;
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int goallteqgoal = numSubarraysWithSumlteq(nums,k);
        int goallteqgoalminusone = numSubarraysWithSumlteq(nums,k-1);
        int ans = goallteqgoal - goallteqgoalminusone;
        return ans;
    }
};