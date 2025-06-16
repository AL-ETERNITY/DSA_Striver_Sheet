// function to solve the problem of merging K sorted arrays
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        
        vector<int>ans;
        int n=arr.size();
        int m=arr[0].size();
        priority_queue<int,vector<int> , greater<int> > pq;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push(arr[i][j]);
            }
        }
        while(pq.size() > 0){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};