// function to solve the problem of Course Schedule using Kahn's Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<vector<int>> adjList(V);
        for (auto& edge : prerequisites) {
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
        
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(auto adjNode : adjList[front]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        if(cnt != numCourses) return false;
        else return true;
    }
};