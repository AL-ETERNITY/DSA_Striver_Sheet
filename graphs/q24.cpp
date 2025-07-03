// function to solve the problem of finding eventual safe nodes in a directed graph using Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Step 1: Reverse the graph
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);  // reverse the edge u -> v to v -> u
                indegree[u]++;             // original outdegree becomes indegree in reversed
            }
        }

        // Step 2: Kahn's algorithm on reversed graph
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            safe.push_back(node);

            for (int adj : revGraph[node]) {
                indegree[adj]--;
                if (indegree[adj] == 0) {
                    q.push(adj);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
