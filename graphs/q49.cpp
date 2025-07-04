// function to solve the problem of finding articulation points in a graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:  
    void dfs(int node, int parent, vector<int>& visited, vector<int>& mark, vector<int> adjList[], vector<int>& time, vector<int>& low, int& timer){
        visited[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        
        for(auto adjNode: adjList[node]){
            if(adjNode == parent) continue;
            if(!visited[adjNode]){
                dfs(adjNode, node, visited, mark, adjList, time, low, timer);
                
                low[node] = min(low[node], low[adjNode]);
                
                if(low[adjNode] >= time[node] && parent != -1){
                    mark[node] = 1;
                }
                
                child++;
            }
            else{
                low[node] = min(low[node], time[adjNode]);
            }
        }
        
        if(parent == -1 && child > 1){
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        int timer = 0;
        vector<int> visited(V, 0);
        vector<int> time(V);
        vector<int> low(V);
        vector<int> mark(V,0);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1, visited, mark, adj, time, low, timer);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }
        return ans.size() == 0 ? vector<int>{-1} : ans;
    }
};