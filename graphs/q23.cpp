// function to solve the problem of finding the order of courses to take given prerequisites
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<vector<int>> adjList(V);
        for (auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto adjNode : adjList[i]) {
                indegree[adjNode]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto adjNode : adjList[front]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        if (ans.size() == numCourses)
            return ans;
        return {}; 
    }
};
