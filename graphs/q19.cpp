// function to solve the problem of topological sorting in a directed acyclic graph (DAG)
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, stack<int>& st) {
        visited[node] = 1;
        for (auto adjNode : adjList[node]) {
            if (!visited[adjNode]) {
                dfs(adjNode, visited, adjList, st);
            }
        }
        st.push(node);  // post-order
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0);
        stack<int> st;
        vector<vector<int>> adjList(V);

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adjList, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
