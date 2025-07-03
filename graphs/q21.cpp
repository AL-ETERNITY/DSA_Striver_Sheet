// function to solve the problem of detecting a cycle in a directed graph using Kahn's algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(V,0);
        for(int i = 0; i<V; i++){
            for(auto adjNode : adjList[i]){
                indegree[adjNode]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto adjNode : adjList[front]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        if(ans.size() != V) return true;
        else return false;
    }
};
