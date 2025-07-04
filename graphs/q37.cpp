// Function to find sum of weights of edges of the Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(V, 0);
        
        pq.push({0,0}); //wt,node
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(visited[node] == 1) continue;
            
            visited[node] = 1;
            sum += wt;
            
            for(auto adjNode : adj[node]){
                int neighbour = adjNode[0];
                int edgeWeight = adjNode[1];
                
                if(!visited[neighbour]){
                    pq.push({edgeWeight, neighbour});
                }
            }
        }
        return sum;
    }
};