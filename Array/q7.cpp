#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=1;i<nums.size();i++)
        {
            int temp=nums[i];
            int j=i-1;
            for (;j>=0;j--)
            {
                if (nums[j]==0)
                {
                    nums[j+1]=nums[j];
                }
                else
                {
                    break;
                }
            }
            nums[j+1]=temp;
        }
    }
};