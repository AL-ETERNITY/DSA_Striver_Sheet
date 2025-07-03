// function to solve the problem of finding the shortest path in a directed acyclic weighted graph (DAG) using topological sorting
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int>& visited, unordered_map<int, vector<pair<int,int>>>& adjList, stack<int>& topo){
        visited[node] = 1;
        
        for(auto adjNode : adjList[node]){
            if(!visited[adjNode.first]){
                dfs(adjNode.first, visited, adjList, topo);
            }
        }
        
        topo.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        
        for(int i = 0; i<E; i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int> topo;
        vector<int> visited(V,0);
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, adjList, topo);
            }
        }
        
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;
        
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();
            
            if(distance[node] != INT_MAX){
                for(auto adjNode : adjList[node]){
                    int neighbour = adjNode.first;
                    int edgeWeight = adjNode.second;
                    
                    if(distance[node] + edgeWeight < distance[neighbour]){
                        distance[neighbour] = distance[node] + edgeWeight;
                    }
                }
            }
        }
        
        for(int i = 0; i<V; i++){
            if(distance[i] == INT_MAX) distance[i] = -1;
        }
        
        return distance;
    }
};
