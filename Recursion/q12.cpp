// function to solve the problem of finding all unique combinations of candidates that sum up to a target value.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findcombinations(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> output){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }

        // include
        if(candidates[index] <= target){
            output.push_back(candidates[index]);
            findcombinations(index, candidates, target-candidates[index], ans, output);
            output.pop_back();
        }

        // exclude
        findcombinations(index+1, candidates, target, ans, output);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        findcombinations(0, candidates, target, ans, output);
        return ans;
    }
};