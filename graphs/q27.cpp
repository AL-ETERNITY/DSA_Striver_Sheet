#include <bits/stdc++.h>
using namespace std;

// function to solve the problem of finding the shortest distance from source to vertices in a weighted undirected graph using Dijkstra's algorithm using a priority queue
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int,int>>> adjList;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});  // Remove this line if graph is directed
        }

        // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(V, INT_MAX);
        
        distance[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adj : adjList[node]){
                int neighbour = adj.first;
                int edgeWeight = adj.second;
            
                if (dist + edgeWeight < distance[neighbour]) {
                    distance[neighbour] = dist + edgeWeight;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }

        return distance;
    }
};

// function to solve the problem of finding the shortest distance from source to vertices in a weighted undirected graph using Dijkstra's algorithm using a set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int,int>>> adjList;

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});  // Remove this line if graph is directed
        }

        // set: {distance, node}
        set<pair<int,int>> st;
        vector<int> distance(V, INT_MAX);
        
        distance[src] = 0;
        st.insert({0, src});

        while(!st.empty()){
            auto it = *(st.begin());
            
            int dist = it.first;
            int node = it.second;
            st.erase(it);

            for(auto adj : adjList[node]){
                int neighbour = adj.first;
                int edgeWeight = adj.second;
            
                if (dist + edgeWeight < distance[neighbour]) {
                    if(distance[neighbour] != INT_MAX){
                        st.erase({distance[neighbour], neighbour});
                    }
                    
                    distance[neighbour] = dist + edgeWeight;
                    st.insert({distance[neighbour], neighbour});
                }
            }
        }

        return distance;
    }
};

// function to solve the problem of finding the shortest path in an undirected weighted graph using Dijkstra's algorithm
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adjList;

        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});  // for undirected graph
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> distance(n+1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i = 1; i <= n; i++) parent[i] = i;
        distance[1] = 0;
        pq.push({0, 1});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adj : adjList[node]){
                int neighbour = adj.first;
                int edgeWeight = adj.second;

                if (dist + edgeWeight < distance[neighbour]) {
                    distance[neighbour] = dist + edgeWeight;
                    parent[neighbour] = node;
                    pq.push({distance[neighbour], neighbour});
                }
            }
        }

        if(distance[n] == INT_MAX) return {-1};

        // Reconstruct path
        vector<int> path;
        int node = n;
        while (node != parent[node]) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);  // finally push the source node
        path.push_back(distance[n]);
        reverse(path.begin(), path.end());

        return path;
    }
};


// time complexity is O(E log V) where E is the number of edges and V is the number of vertices.