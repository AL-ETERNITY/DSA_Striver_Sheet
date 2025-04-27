#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int> m;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            for (int j = i + 1; j < s.size(); j++) {
                m[s[j]]++;
                int mini = INT_MAX;
                int maxi = INT_MIN;
                for(auto i: m){
                    if(i.second > maxi){
                        maxi = i.second;
                    }
                    if(i.second < mini){
                        mini = i.second;
                    }
                }
                res += maxi - mini;
            }
            m.clear();
        }
        return res;
    }
};