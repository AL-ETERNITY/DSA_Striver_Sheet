// function to solve the fractional knapsack problem
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int,int>> vec;
        
        for(int i=0;i<val.size();i++) {
            vec.push_back({val[i], wt[i]});
        }
        
        sort(vec.begin(),vec.end(),[&](auto a, auto b){
            return (double(a.first)/double(a.second)) > (double(b.first)/double(b.second));
        });
        
        double ans = 0;
        
        for(auto element : vec) {
            if(capacity >= element.second) {
                ans += element.first;
                capacity -= element.second;
            } else {
                double perGm = double(element.first) / double(element.second);
                ans += capacity * perGm;
                break;
            }
        }
        
        return ans;
    }
};