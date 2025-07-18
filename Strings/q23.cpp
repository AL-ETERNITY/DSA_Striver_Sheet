# include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) {
            return dp[i][j] = 1 + solve(s, i + 1, j, dp) + solve(s, i, j - 1, dp);
        } 
        else {
            return dp[i][j] = solve(s, i + 1, j, dp) + solve(s, i, j - 1, dp) - solve(s, i + 1, j - 1, dp);
        }
        return -1;
    }
    
  public:
    int countPS(string &s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        return solve(s, 0, s.length() -  1, dp);
    }
};