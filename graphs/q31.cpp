// function to solve the problem of counting paths in a graph with given roads and weights
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        unordered_map<int, vector<pair<int,int>>> adjList;

        for (auto& road : roads) {
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> time(n, 1e18);
        vector<int> ways(n,0);
        priority_queue<pair<long long, int>, 
                vector<pair<long long, int>>, 
                greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        time[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long tm = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& adjNode : adjList[node]) {
                int neighbour = adjNode.first;
                int edgeTime = adjNode.second;

                if (tm + edgeTime < time[neighbour]) {
                    time[neighbour] = tm + edgeTime;
                    ways[neighbour] = ways[node];
                    pq.push({time[neighbour], neighbour});
                } 
                else if (tm + edgeTime == time[neighbour]) {
                    ways[neighbour] = (ways[neighbour] + ways[node]) % mod;
                }
            }
        }

        return (ways[n - 1]) % mod;
    }
};
