#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                if(count>ans){
                    ans=count;
                }
                count=0;
            }
        }
        if(count!=0 && count>ans){
            ans=count;
        }
        return ans;
    }
};