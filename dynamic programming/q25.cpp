// function to solve the problem of finding all longest common subsequences (LCS) of two strings
// using dynamic programming and recursion with memoization.
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    set<string> LCS(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp, map<pair<int, int>, set<string>> &memo) {
        if (i == 0 || j == 0)
            return {""};
    
        if (memo.count({i, j}))
            return memo[{i, j}];
    
        if (s1[i - 1] == s2[j - 1]) {
            set<string> prev = LCS(i - 1, j - 1, s1, s2, dp, memo);
            set<string> result;
            for (const string &str : prev)
                result.insert(str + s1[i - 1]);
            return memo[{i, j}] = result;
        }
    
        set<string> result;
        if (dp[i - 1][j] >= dp[i][j - 1])
            result = LCS(i - 1, j, s1, s2, dp, memo);
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            set<string> temp = LCS(i, j - 1, s1, s2, dp, memo);
            result.insert(temp.begin(), temp.end());
        }
    
        return memo[{i, j}] = result;
    }
  public:
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
    
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    
        map<pair<int, int>, set<string>> memo;
        set<string> result = LCS(n, m, s1, s2, dp, memo);
    
        vector<string> ans (result.begin(), result.end());
        
        return ans;
    }
};
