#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int low = 0;
            int high = nums.size()-1;
            int ans = 0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[0] <= nums[mid]){
                    low = mid + 1;
                }
                else{
                    ans = mid;
                    high = mid - 1;
                }
            }
            return nums[ans];
        }
    };