// function to solve the problem of merging accounts based on email addresses
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node) return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> mailsOfNode(n);
        for(auto it : mp){
            string mail = it.first;
            int node = ds.parentFind(it.second);
            mailsOfNode[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mailsOfNode[i].size()) {
                // Non empty
                sort(mailsOfNode[i].begin(), mailsOfNode[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Name
                for(auto it : mailsOfNode[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};