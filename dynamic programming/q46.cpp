// function to solve the matrix chain multiplication problem using recursion
#include <bits/stdc++.h>
using namespace std;

// Function to solve the matrix chain multiplication problem using recursion
class Solution {
  private:
    int f(vector<int> &arr, int i, int j){
        if(i == j) return 0; // single matrix, no multiplication needed
        
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i - 1] * arr[k] * arr[j] 
                        + f(arr, i, k) 
                        + f(arr, k + 1, j);
            mini = min(steps, mini);
        }
        
        return mini;
    }

  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        return f(arr, 1, n - 1);
    }
};


// function to solve the matrix chain multiplication problem using memoization
class Solution {
  private:
    int f(vector<int> &arr, int i, int j, vector<vector<int>>& dp){
        if(i == j) return 0; // single matrix, no multiplication needed
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int k = i; k < j; k++){
            int steps = arr[i - 1] * arr[k] * arr[j] 
                        + f(arr, i, k, dp) 
                        + f(arr, k + 1, j, dp);
            mini = min(steps, mini);
        }
        
        return dp[i][j] = mini;
    }

  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(arr, 1, n - 1, dp);
    }
};

// function to solve the matrix chain multiplication problem using tabulation
class Solution {
    public:
        int matrixMultiplication(vector<int> &arr) {
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
            
            for(int i = n - 1; i >= 1; i--){
                for(int j = i + 1; j < n; j++){
                    int mini = 1e9;
                    for(int k = i; k < j; k++){
                        int steps = arr[i - 1] * arr[k] * arr[j] 
                                    + dp[i][k] 
                                    + dp[k + 1][j];
                        mini = min(steps, mini);
                    }
                    dp[i][j] = mini;
                }
            }
            
            return dp[1][n - 1];
        }
    };