// function to find the maximum number of content children given their greed factors and the sizes of cookies available.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        if(n == 0)  return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int cnt = 0;
        int j = 0;
        int i = 0;
        while(i<m && j<n){
            if(s[j] >= g[i]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};