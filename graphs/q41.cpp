// function to solve the problem of finding the sum of weights of edges of the Minimum Spanning Tree (MST) using Kruskal's algorithm.
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
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
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int,int>>> edges; //{wt, {node, adjNode}}
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                edges.push_back({it[1], {i,it[0]}});
            }
        }
        
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int sum = 0;
        
        for(auto it : edges){
            int wt = it.first;
            int node = it.second.first;
            int neighbour = it.second.second;
            
            if(ds.parentFind(node) != ds.parentFind(neighbour)){
                sum += wt;
                ds.unionBySize(node, neighbour);
            }
        }
        
        return sum;
    }
};