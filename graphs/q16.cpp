// function to solve the problem of counting distinct islands in a grid
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m, vector<pair<int,int>>& output, int baseRow, int baseCol) {
        visited[row][col] = 1;
        output.push_back({0, 0});
        queue<pair<int,int>> q;
        q.push({row, col});

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 1;
                    output.push_back({nrow - baseRow, ncol - baseCol});
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> shapes;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int,int>> output;
                    bfs(i, j, grid, visited, n, m, output, i, j);
                    shapes.insert(output);
                }
            }
        }

        return shapes.size();
    }
};
