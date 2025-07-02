// function to solve the problem of performing a depth-first search (DFS) on a graph represented as an adjacency list
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfs, int node){
        visited[node] = 1;
        dfs.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                solve(adj, visited, dfs, it);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> visited(v,0);
        vector<int> dfs;
        solve(adj, visited, dfs, 0);
        return dfs;
    }
};

// space complexity is O(3 * V) where V is the number of vertices. which is equivalent to O(V) in big O notation.
// time complexity is O(V) + O(2*E) where V is the number of vertices and E is the number of edges. This is because we visit each vertex once and traverse its neighbours once , so summation of degree of nodes is equal to degree of a graph which is 2*E