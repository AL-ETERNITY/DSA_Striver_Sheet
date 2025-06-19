// function to solve the problem of finding the K maximum combinations from two sorted arrays A and B
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxCombinations(int K, vector<int> &A, vector<int> &B) {
        int n = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
        st.insert({n - 1, n - 1});
        vector<int> ans;
        while(K--){
            auto curr = pq.top();
            ans.push_back(curr.first);
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            if(i - 1 >= 0 && st.find({i - 1, j}) == st.end()){
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            if(j - 1 >= 0 && st.find({i, j - 1}) == st.end()){
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
        }
        return ans;
    }
};