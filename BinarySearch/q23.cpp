#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool isPossible(vector<int>& nums, int k, int mid, int n){
            int arrayCount = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] <= mid) {
                    sum += nums[i];
                } 
                else {
                    arrayCount++;
                    if (arrayCount > k || nums[i] > mid) {
                        return false;
                    }
                    sum = nums[i];
                }
            }
            return true;
        }
    
    
    public:
        int splitArray(vector<int>& nums, int k) {
            int n = nums.size();
            int s = *max_element(nums.begin(), nums.end());
            int e = accumulate(nums.begin(), nums.end(), 0);
            int ans = -1;
    
            while(s<=e){
                int mid = s + (e-s)/2;
                if (isPossible(nums,k,mid,n)){
                    ans = mid;
                    e = mid-1;
                }
                else{
                    s = mid + 1;
                }
            }
            return ans;
        }
    };