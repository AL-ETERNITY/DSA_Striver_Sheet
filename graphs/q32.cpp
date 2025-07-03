// function to solve the problem of finding the time it takes for a signal to travel through a network of nodes.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adjList;
        for(auto time : times){
            adjList[time[0]].push_back({time[1], time[2]});
        }

        vector<int> time(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {time, node}

        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()){
            int tm = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto adjNode : adjList[node]){
                int neighbour = adjNode.first;
                int edgeTime = adjNode.second;

                if(tm + edgeTime < time[neighbour]){
                    time[neighbour] = tm + edgeTime;
                    pq.push({tm + edgeTime, neighbour});
                }
            }
        }

        int minTime = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(time[i] == INT_MAX) return -1;
            minTime = max(minTime, time[i]);
        }

        return minTime;
    }
};
