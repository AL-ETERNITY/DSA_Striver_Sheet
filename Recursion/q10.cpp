// function to count the number of subsets with a given sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void count(vector<int> &arr, int target, int index, int &cnt, int sum) {
        if(index == arr.size()) {
            if(sum == target)
                cnt++;
            return;
        }
        
        if(sum > target) return;
        
        // Include 
        count(arr, target, index + 1, cnt, sum + arr[index]);
        
        // Exclude
        count(arr, target, index + 1, cnt, sum);
    }

  public:
    int perfectSum(vector<int>& arr, int target) {
        int cnt = 0;
        count(arr, target, 0, cnt, 0);
        return cnt;
    }
};