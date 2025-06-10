// function to solve the problem of minimizing the average waiting time in a bank queue
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        long long wt=0;
        long long t=0;
        int n=bt.size();
        for(int i=0;i<n;i++){
            
            wt+=t;
            t+=bt[i];
        }
        return wt/n;
    }
};