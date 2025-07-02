// function to solve the problem of capturing surrounded regions in a board represented by a 2D grid.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs (int i, int j, vector<vector<int>> &visited, vector<vector<int>>& grid, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] != 1 || visited[i][j]) return;

        visited[i][j] = 1;

        dfs(i + 1, j, visited, grid, m, n);
        dfs(i - 1, j, visited, grid, m, n);
        dfs(i, j + 1, visited, grid, m, n);
        dfs(i, j - 1, visited, grid, m, n);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++) {
            if(!visited[i][0]) {
                dfs(i, 0, visited, grid, m, n);
            }

            if(!visited[i][n - 1]) {
                dfs(i, n - 1, visited, grid, m, n);
            }
        }

        for(int j = 0; j < n; j++) {
            if(!visited[0][j]) {
                dfs(0, j, visited, grid, m, n);
            }

            if(!visited[m - 1][j]) {
                dfs(m - 1, j, visited, grid, m, n);
            }
        }

        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};
