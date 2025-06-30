// function to solve the problem of finding the length of the longest increasing subsequence in an array
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            else{
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[index] = arr[i];
            }
        }
        return len;
    }
};