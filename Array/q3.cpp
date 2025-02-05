#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums,int x){
        vector<int> temp(nums.size());
        for (int i=0;i<nums.size();i++)
        {
            temp[(i+x)%nums.size()]=nums[i];
        }
        nums=temp;
    }
    
    
    
    bool check(vector<int>& nums) {
        int x=0;
        int k=0;
        while (k<=nums.size())
        {
            if (nums.size()==1)
            {
                return true;
            }
            rotate(nums,x);
            for (int j=1;j<nums.size();j++)
            {
                if (nums[j-1]>nums[j])
                {
                  k++;
                  x=1;
                  break;
                }
                else if(j==nums.size()-1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};