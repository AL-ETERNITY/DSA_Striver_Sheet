// function to solve the problem of making a network connected with minimum operations
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.parentFind(u) == ds.parentFind(v)){
                extras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int nc = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) nc++;
        }
        int ans = nc -1;
        if(extras >= ans) return ans;
        return -1;
    }
};