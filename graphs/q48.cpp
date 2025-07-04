// function to solve the problem of finding critical connections in a network
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adjList,
             vector<int>& time, vector<int>& low, vector<vector<int>>& bridges, int& timer) {
        
        visited[node] = 1;
        time[node] = low[node] = timer++;
        
        for(auto adjNode : adjList[node]) {
            if(adjNode == parent) continue;

            if(!visited[adjNode]) {
                dfs(adjNode, node, visited, adjList, time, low, bridges, timer);

                low[node] = min(low[node], low[adjNode]);

                if(low[adjNode] > time[node]) {
                    bridges.push_back({node, adjNode});
                }
            } 
            else {
                low[node] = min(low[node], time[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto& edge : connections) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int timer = 0;
        vector<int> visited(n, 0);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, -1, visited, adjList, time, low, bridges, timer);
            }
        }

        return bridges;
    }
};

// space complexity is O(V + 2E) + O(3V)
// time complexity is O(V + 2E)