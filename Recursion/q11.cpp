// function to solve the subset sum problem using recursion
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void solve(vector<int>& arr, int target, int index, int sum, bool& found){
        if(index == arr.size()){
            if(target == sum) found = true;
            return;
        }
        
        if (sum > target) return;
        // include
        solve(arr,target, index+1, sum+arr[index], found);
        
        // exclude
        solve(arr,target, index+1, sum, found);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        bool found = false;
        solve(arr,sum,0,0,found);
        return found;
    }
};