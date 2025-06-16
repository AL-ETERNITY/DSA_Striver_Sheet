using namespace std;
#include <bits/stdc++.h>

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int> pq (hand.begin(), hand.end());
        int cnt = 0;
        int prev = -1;
        vector<int> temp;
        
        while(!pq.empty()) {
            int top = pq.top(); pq.pop();
            if(cnt != 0 && top == prev) { // if cnt = 0 then starting of new group
                temp.push_back(top);
            } 
            else if(prev == -1 || top == prev - 1 || cnt == 0) {
                cnt++;
                if(cnt == groupSize) {
                    cnt = 0;
                    for(auto i : temp) {
                        pq.push(i);
                    }
                    temp.clear();
                }
                prev = top;
            } 
            else {
                return false;
            }
        }

        if(cnt == 0) return true;
        else return false;
    }
};