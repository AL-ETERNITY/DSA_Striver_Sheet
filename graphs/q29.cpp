// function to solve the problem of finding the minimum effort path in a grid
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m,1e9));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        distance[0][0] = 0;

        vector<pair<int, int>> directions = {
                      {-1, 0},
            {0, -1},           {0, 1},
                      {1, 0}
        };

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int diff = it.first;

            for(auto dir : directions){
                int dx = dir.first, dy = dir.second;
                int nx = r + dx, ny = c + dy;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newEffort = max(abs(heights[r][c] - heights[nx][ny]), diff);
                    if(newEffort < distance[nx][ny]){
                        distance[nx][ny] = newEffort;
                        pq.push({newEffort, {nx,ny}});
                    }
                }
            }
        }

        return distance[n-1][m-1] != 1e9 ? distance[n-1][m-1] : 0;
    }
};
