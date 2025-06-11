// function to solve the problem of merging overlapping intervals
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rows = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<rows;i++){
            vector<int>& last = ans.back(); 
            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            } 
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};