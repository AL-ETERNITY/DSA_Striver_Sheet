// function to solve the problem of finding the shortest path in an unweighted graph using BFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        queue<int> q;
        vector<int> dist(adj.size(), -1);  // Use -1 directly for unvisited
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int adjNode : adj[node]) {
                if (dist[adjNode] == -1) {
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }

        return dist;
    }
};