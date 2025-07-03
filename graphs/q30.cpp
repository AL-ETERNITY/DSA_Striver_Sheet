// function to solve the problem of finding the cheapest flight with at most k stops
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        for(int i = 0; i < flights.size(); i++){
            adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int,int>>> q; // {stops, {node, cost}}
        vector<int> distance(n, INT_MAX);

        q.push({0, {src, 0}});
        distance[src] = 0;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto adjNode: adjList[node]){
                int neighbour = adjNode.first;
                int edgeCost = adjNode.second;

                if(cost + edgeCost < distance[neighbour]){
                    distance[neighbour] = cost + edgeCost;
                    q.push({stops + 1, {neighbour, cost + edgeCost}});
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
