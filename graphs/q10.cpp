// function to solve the problem of detecting a cycle in an undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detect(int src, int parent, vector<vector<int>>& adjList, vector<int>& visited){
        visited[src] = 1;
        for(auto adjacentNode : adjList[src]){
            if(!visited[adjacentNode]){
                if(detect(adjacentNode, src, adjList, visited) == true) return true;
            }
            else if(adjacentNode != parent){
                return true;
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
                if (detect(i, -1, adjList, visited)) return true;
            }
        }

        return false;
    }
};
