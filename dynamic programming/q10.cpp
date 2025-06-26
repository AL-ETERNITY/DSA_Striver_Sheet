// function to solve the problem of finding the minimum path sum in a grid using recursion and memoization
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Minimum Path Sum problem
class Solution {
private:
    int f(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 || j < 0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(grid, dp, i - 1, j);
        int left = f(grid, dp, i, j - 1);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(grid, dp, m - 1, n - 1);
    }
};


// bottom-up dynamic programming solution to the Minimum Path Sum problem
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = (i > 0) ? dp[i-1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j-1] : INT_MAX;

                    dp[i][j] = grid[i][j] + min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// space-optimized bottom-up dynamic programming solution to the Minimum Path Sum problem
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else{
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? curr[j-1] : INT_MAX;

                    curr[j] = grid[i][j] + min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
