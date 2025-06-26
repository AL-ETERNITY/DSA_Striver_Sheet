// function to solve the problem of partitioning an array into two subsets with equal sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSubsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        
        if(nums[0] <= sum) prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = prev[j];
                bool take = false;
                if (nums[i] <= j)
                    take = prev[j-nums[i]];
        
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i = 0;i<n;i++) total_sum += nums[i];
        if(total_sum % 2) return false;

        int sum = total_sum/2;
        return isSubsetSum(nums, sum);
    }
};