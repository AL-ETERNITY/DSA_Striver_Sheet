// function to solve the problem of detecting a cycle in an undirected graph using BFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detect(int src, vector<vector<int>>& adjList, vector<int>& visited){
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adjList[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (adjacentNode != parent) {
                    return true; // cycle detected
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detect(i, adjList, visited)) return true;
            }
        }

        return false;
    }
};

// time complexity is O(V + 2*E) + O(N) where V is the number of vertices and E is the number of edges.
// space complexity is O(V) + O(V) + O(V) = O(3V) which is equivalent to O(V) in big O notation.