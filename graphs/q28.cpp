// function to solve the problem of finding the shortest path in a binary matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<pair<int, int>, int>> q;  // ((x, y), distance)
        q.push({{0, 0}, 1});
        grid[0][0] = 2;

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int x = front.first.first, y = front.first.second;
            int dist = front.second;

            if (x == n - 1 && y == n - 1) return dist;

            for (auto dir : directions) {
                int dx = dir.first, dy = dir.second;
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    q.push({{nx, ny}, dist + 1});
                    grid[nx][ny] = 2;  // mark as visited
                }
            }
        }

        return -1;
    }
};
