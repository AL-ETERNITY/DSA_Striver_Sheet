// function to solve the problem of finding the minimum difference between two subsets of an array.
#include<bits/stdc++.h>
using namespace std;

// for doing ninjas and gfg problem
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();

        int total_sum = 0;
        for (int num : nums) total_sum += num;

        vector<bool> prev(total_sum + 1, false), curr(total_sum + 1, false);

        prev[0] = curr[0] = true;
        if (nums[0] <= total_sum) prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= total_sum; j++) {
                bool notTake = prev[j];
                bool take = false;
                if (nums[i] <= j)
                    take = prev[j - nums[i]];

                curr[j] = take || notTake;
            }
            prev = curr;
        }

        int mini = INT_MAX;
        for (int s1 = 0; s1 <= total_sum / 2; s1++) {
            if (prev[s1]) {
                int s2 = total_sum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};

// for leetcode problem
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int N = n/2;
        // Divide array into two subparts of equal size - left and right
        vector<vector<int>> left(N+1), right(N+1); // Value on Index 0 in left means possible sums of size 0 from left subpart of array
        
		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0; sz<=N; ++sz){
            sort(right[sz].begin(), right[sz].end());
        }

        // All n elements in first subset from left part or right part
        res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));

		//iterating over left part
        for(int sz=1; sz<N; ++sz){  // sz is number of elements in first subset from left array
            for(auto &a : left[sz]){
                int b = (sum - 2*a)/2; // ideal value of b (ideally a + b = (sum / 2))
                int rsz = N-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part
                // in array of 4,5,9,10  lower bound of 6 will return 9, but actually 5 is closer, so also check for previous element to itr
                
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
                if(itr!= v.begin()){
                    auto it = itr; --it;
                    res = min(res, abs(sum-2*(a+(*it))));
                }                
            }
        }
        return res;
        
    }
};
