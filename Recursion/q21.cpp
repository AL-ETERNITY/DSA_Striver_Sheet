// function to solve the Rat in a Maze problem using backtracking
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(vector<string>& ans, vector<vector<int>>& maze, int n, int x, int y, string output, vector<vector<int>> visited) {
        if(x == n - 1 && y == n - 1) {
            ans.push_back(output);
            return;
        }
        
        visited[x][y] = 1;
        
        int newx, newy;
        
        //Down
        newx = x + 1;
        newy = y;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1) {
            output.push_back('D');
            solve(ans, maze, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Left
        newx = x;
        newy = y - 1;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1) {
            output.push_back('L');
            solve(ans, maze, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Right
        newx = x;
        newy = y + 1;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1) {
            output.push_back('R');
            solve(ans, maze, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        //Up
        newx = x - 1;
        newy = y;
        if(newx >=0 && newx < n && newy >=0 && newy < n && visited[newx][newy] == 0 && maze[newx][newy] == 1) {
            output.push_back('U');
            solve(ans, maze, n, newx, newy, output, visited);
            output.pop_back();
        }
        
        visited[x][y] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if(maze[n-1][n-1] == 0 || maze[0][0] == 0) {
            return ans;
        }
        
        vector<vector<int>> visited = maze;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        
        int x = 0, y = 0;
        string output = "";
        
        solve(ans, maze, n, x, y, output, visited);
        
        return ans;
    }
};