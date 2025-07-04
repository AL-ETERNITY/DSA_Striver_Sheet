// function to solve the problem of finding the number of strongly connected components (SCCs) in a directed graph using Kosaraju's algorithm.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfsTopo(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!visited[adjNode]) {
                dfsTopo(adjNode, adj, visited, st);
            }
        }
        st.push(node);
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!visited[adjNode]) {
                dfs(adjNode, adj, visited);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfsTopo(i, adj, visited, st);
            }
        }

        // Transpose graph
        vector<vector<int>> transpose(V);
        for(int i = 0; i < V; i++) {
            for(auto adjNode : adj[i]) {
                transpose[adjNode].push_back(i);
            }
        }

        for(int i = 0; i < visited.size(); i++) {
            visited[i] = 0;
        }

        int sccCount = 0;

        while(!st.empty()) {
            int top = st.top(); st.pop();
            if(!visited[top]) {
                dfs(top, transpose, visited);
                sccCount++;
            }
        }

        return sccCount;
    }
};
