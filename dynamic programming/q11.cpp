// function to solve the problem of finding the minimum path sum in a triangle
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Minimum Path Sum in Triangle problem
class Solution {
private:
    int f(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j, int m) {
        if (i == m - 1) {
            return triangle[m - 1][j];
        }

        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(triangle, dp, i + 1, j, m);
        int diagonal = triangle[i][j] + f(triangle, dp, i + 1, j + 1, m);

        return dp[i][j] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(triangle, dp, 0, 0, m);
    }
};

// bottom-up dynamic programming solution to the Minimum Path Sum in Triangle problem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int j=0;j<m;j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};

// space-optimized bottom-up dynamic programming solution to the Minimum Path Sum in Triangle problem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> front(m,0);
        for(int j=0;j<m;j++){
            front[j] = triangle[m-1][j];
        }

        for(int i=m-2;i>=0;i--){
            vector<int> curr(m,0);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down,diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};

