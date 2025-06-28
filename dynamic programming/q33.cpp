// function to solve the problem of wildcard matching
#include <bits/stdc++.h>
using namespace std;

// recursive function to check if the string matches the pattern
class Solution {
private:
    bool f(string& s, string& p, int i, int j) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) {
            for(int jj = 0; jj <= j; jj++) {
                if(p[jj] != '*') return false;
            }
            return true;
        }
        if(j < 0 && i >= 0) return false;

        if(p[j] == s[i] || p[j] == '?') {
            return f(s, p, i-1, j-1);
        } 
        else if(p[j] == '*') {
            return f(s, p, i-1, j) || f(s, p, i, j-1);
        } 
        else {
            return false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return f(s, p, n-1, m-1);
    }
};

// top-down dynamic programming approach
class Solution {
private:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) {
            for(int jj = 0; jj <= j; jj++) {
                if(p[jj] != '*') return false;
            }
            return true;
        }
        if(j < 0 && i >= 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == s[i] || p[j] == '?') {
            return dp[i][j] = f(s, p, i-1, j-1, dp);
        } 
        else if(p[j] == '*') {
            return dp[i][j] = f(s, p, i-1, j, dp) || f(s, p, i, j-1, dp);
        } 
        else {
            return dp[i][j] = false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(s, p, n-1, m-1, dp);
    }
};

// bottom-up dynamic programming approach
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[0][0] = 1;
        // for(int i=1; i<=n; i++) dp[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

// space optimized bottom-up dynamic programming approach
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> prev(m+1,0), curr(m+1,0);

        prev[0] = 1;
        // for(int i=1; i<=n; i++) dp[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = 0;
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } 
                else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } 
                else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};
