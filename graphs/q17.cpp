// function to solve the problem of checking if a graph is bipartite using DFS
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;

        for(auto adjacentNode : graph[node]){
            if(color[adjacentNode] == -1){
                if(dfs(adjacentNode, !col, color, graph) == false) return false;
            }
            else if(color[adjacentNode] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);

        for(int i = 0; i<v; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};