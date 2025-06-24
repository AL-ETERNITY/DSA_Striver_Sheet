// function to solve the problem of generating all subsets of a set with possible duplicates
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &output, int index) {
        if(index == arr.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude 
        // Before excluding, skip all duplicates
        int next = index + 1;
        while(next < arr.size() && arr[next] == arr[next - 1]) {
            next++;
        }
        solve(arr, ans, output, next);
        
        // Include 
        output.push_back(arr[index]);
        solve(arr, ans, output, index + 1);
        output.pop_back();
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, 0);
        return ans;
    }
};