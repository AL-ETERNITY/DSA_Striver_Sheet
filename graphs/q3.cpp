// function to perform a breadth-first traversal of a graph represented as an adjacency list.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> visited(v, 0);
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

// space complexity is O(3 * V) where V is the number of vertices. which is equivalent to O(V) in big O notation.
// time complexity is , since while lopp is running on queue which will traverse for all the nodes once and the for loop will run for the degree of the graph which is O(2*no.of edges) which is equivalent to O(V) + O(2*E) in big O notation.