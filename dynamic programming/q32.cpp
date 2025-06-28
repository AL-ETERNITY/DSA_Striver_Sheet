// function to solve the problem of finding the minimum edit distance between two strings
#include <bits/stdc++.h>
using namespace std;

// recursive solution to find the minimum edit distance between two strings
class Solution {
private:
    int f(int i, int j, string& word1, string& word2){
        if(i<0) return j+1; //this many insertions
        if(j<0) return i+1; //this many deletions

        if(word1[i] == word2[j]){
            return f(i-1, j-1, word1, word2);
        }
        return 1 + min({f(i-1,j,word1,word2), f(i,j-1,word1,word2), f(i-1,j-1,word1,word2)});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        return f(n-1, m-1, word1, word2);
    }
};

// top-down dynamic programming solution to find the minimum edit distance between two strings
class Solution {
private:
    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0) return j+1; //this many insertions
        if(j<0) return i+1; //this many deletions

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = f(i-1, j-1, word1, word2, dp);
        }

        return dp[i][j] = 1 + min({f(i-1,j,word1,word2,dp), f(i,j-1,word1,word2,dp), f(i-1,j-1,word1,word2,dp)});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1, m-1, word1, word2, dp);
    }
};

// bottom-up dynamic programming solution to find the minimum edit distance between two strings
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],     // delete
                                        dp[i][j - 1],     // insert
                                        dp[i - 1][j - 1]  // replace
                    });
                }
            }
        }
        return dp[n][m];
    }
};

// space-optimized bottom-up dynamic programming solution to find the minimum edit distance between two strings
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> prev(m+1), curr(m+1,0);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({prev[j],     // delete
                                        curr[j - 1],     // insert
                                        prev[j - 1]  // replace
                    });
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
