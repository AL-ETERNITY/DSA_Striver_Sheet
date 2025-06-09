// function to solve the problem of finding the maximum number of meetings that can be attended
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> vec;
        
        for(int i=0;i<start.size();i++) {
            vec.push_back({start[i], end[i]});
        }

        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        
        int cnt = 0;
        int endtime = -1;
        for(int i = 0;i<vec.size();i++){
            if(vec[i].first > endtime){
                cnt++;
                endtime = vec[i].second;
            }
        }
        return cnt;
    }
};