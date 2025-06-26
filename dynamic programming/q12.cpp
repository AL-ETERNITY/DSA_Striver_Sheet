// function to solve the minimum falling path sum problem using recursion with memoization
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Minimum Falling Path Sum problem
class Solution {
private:
    int f(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int n) {
        if (col < 0 || col >= n) return INT_MAX;
        if (row == n - 1) return matrix[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int right_diagonal = f(matrix, dp, row + 1, col - 1, n);
        int down = f(matrix, dp, row + 1, col, n);
        int left_diagonal = f(matrix, dp, row + 1, col + 1, n);

        return dp[row][col] = matrix[row][col] + min({right_diagonal, down, left_diagonal});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int col = 0; col < n; col++) {
            ans = min(ans, f(matrix, dp, 0, col, n));
        }

        return ans;
    }
};

// bottom-up dynamic programming solution to the Minimum Falling Path Sum problem
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int mini = dp[i + 1][j];  // down

                if (j > 0) mini = min(mini, dp[i + 1][j - 1]);      // down-left
                if (j < n - 1) mini = min(mini, dp[i + 1][j + 1]);  // down-right

                dp[i][j] = matrix[i][j] + mini;
            }
        }

        // Result: min in top row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};

// space-optimized bottom-up dynamic programming solution to the Minimum Falling Path Sum problem
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n,0);

        // Base case: last row
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[n - 1][j];
        }

        // Bottom-up DP
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n,0);
            for (int j = 0; j < n; j++) {
                int mini = prev[j];  // down

                if (j > 0) mini = min(mini, prev[j - 1]);      // down-left
                if (j < n - 1) mini = min(mini, prev[j + 1]);  // down-right

                curr[j] = matrix[i][j] + mini;
            }
            prev = curr;
        }

        // Result: min in top row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, prev[j]);
        }

        return ans;
    }
};

