// function to solve the problem of counting ways to parenthesize a boolean expression
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int solve(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if(i > j) return 0;

        if(i == j) {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;

        for(int ind = i + 1; ind < j; ind += 2) {
            char op = s[ind];

            // Evaluate all 4 possibilities
            int lt = solve(i, ind - 1, true, s, dp);
            int lf = solve(i, ind - 1, false, s, dp);
            int rt = solve(ind + 1, j, true, s, dp);
            int rf = solve(ind + 1, j, false, s, dp);

            if(op == '&') {
                if(isTrue) ways = (ways + lt * rt);
                else ways = (ways + lt * rf + lf * rt + lf * rf);
            }
            else if(op == '|') {
                if(isTrue) ways = (ways + lt * rt + lt * rf + lf * rt);
                else ways = (ways + lf * rf);
            }
            else if(op == '^') {
                if(isTrue) ways = (ways + lt * rf + lf * rt);
                else ways = (ways + lt * rt + lf * rf);
            }
        }

        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, true, s, dp);
    }
};