// function to solve the problem of finding unique combinations of numbers that sum up to a target value
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findcombinations(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> output){
        if(target == 0){
            ans.push_back(output);
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            output.push_back(candidates[i]);
            findcombinations(i+1, candidates, target-candidates[i], ans, output);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        findcombinations(0, candidates, target, ans, output);
        return ans;
    }
};