#include<bits/stdc++.h>
using namespace std;

// Function to return the adjacency matrix for the graph.
// space complexity : O(V^2) where V is the number of vertices.
class Solution {
  public:
    vector<vector<int>> buildAdjMatrix(int V, vector<pair<int, int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adj_mat(V, vector<int>(V, 0));
        for(int i = 0; i < m; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            adj_mat[u][v] = 1;
            adj_mat[v][u] = 1; // undirected
        }
        return adj_mat;
    }
};


// Function to return the adjacency list for each vertex.
// space complexity : O(2 * E) where E is the number of edges.
class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList (V);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i].first].push_back(edges[i].second);
            adjList[edges[i].second].push_back(edges[i].first); // undirected graph
        }
        return adjList;
    }
};

// so if directed graph is given then we can use the same code but we will not add the reverse edge.
// if its the weighted graph then we can use pair<int, int> to store the weight of the edge in the adjacency list code.
// and for adjacency matrix we can store the weight in the matrix instead of 1.