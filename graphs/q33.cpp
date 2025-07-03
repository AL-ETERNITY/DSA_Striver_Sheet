// function to solve the problem of finding the minimum number of multiplications
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;

        const int mod = 100000;
        queue<pair<int,int>> q;
        vector<int> steps(mod, 1e9);
        
        q.push({start, 0});
        steps[start] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for(auto i : arr){
                int num = (node * i) % mod;
                if(step + 1 < steps[num]){
                    steps[num] = step + 1;
                    if(num == end) return step + 1;
                    q.push({num, step + 1});
                }
            }
        }
        return -1;
    }
};
