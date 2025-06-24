// function to solve the problem of finding all unique combinations of k numbers that add up to n
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findcombinations(vector<int>& arr, int k, int target, vector<vector<int>>& ans, vector<int>& output, int index) {
        if (target == 0) {
            if (output.size() == k)
                ans.push_back(output);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (arr[i] > target) break;
            output.push_back(arr[i]);
            findcombinations(arr, k, target - arr[i], ans, output, i + 1);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> output;
        findcombinations(arr, k, n, ans, output, 0);
        return ans;
    }
};
