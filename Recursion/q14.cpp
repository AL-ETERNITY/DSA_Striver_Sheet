// function to solve the problem of finding all subset sums of an array
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void findsubsets(vector<int>& arr, vector<int>& ans, int index, int sum){
        if(index == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        // exclude
        findsubsets(arr, ans, index+1, sum);
        
        // include
        findsubsets(arr, ans, index+1, sum+arr[index]);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        findsubsets(arr,ans,0, 0);
        return ans;
    }
};