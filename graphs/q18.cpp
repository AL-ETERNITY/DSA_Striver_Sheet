// function to solve the problem of detecting cycles in a directed graph using DFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adjList){
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto adjNode : adjList[node]){
            if (!visited[adjNode]) {
                if (dfs(adjNode, visited, pathVisited, adjList)) return true;
            }
            else if (pathVisited[adjNode]) {
                return true;  // back edge → cycle
            }
        }

        pathVisited[node] = 0;  // backtrack
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        vector<vector<int>> adjList(V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, adjList)) return true;
            }
        }

        return false;
    }
};
