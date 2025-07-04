// function to solve the problem of finding the Minimum Spanning Tree (MST) using Prim's algorithm.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<vector<int>> spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<int> visited(V, 0);
        vector<vector<int>> MST;
        
        pq.push({0,{0,-1}}); //{wt,{node,parentnode}}
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second.first;
            int parentNode = it.second.second;
            
            if(visited[node] == 1) continue;
            
            visited[node] = 1;
            sum += wt;
            if(parentNode != -1) MST.push_back({node, parentNode});

            
            for(auto adjNode : adj[node]){
                int neighbour = adjNode[0];
                int edgeWeight = adjNode[1];
                
                if(!visited[neighbour]){
                    pq.push({edgeWeight, {neighbour, node}});
                }
            }
        }
        
        return MST;
    }
};