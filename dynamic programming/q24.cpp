// function to solve the problem of finding the length of the longest common subsequence between two strings using recursion and memoization.
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Longest Common Subsequence problem
// we did index shifting so that we can write the base case for bottom-up approach
class Solution {
private:
    int f(string text1, string text2, vector<vector<int>>& dp, int index1, int index2){
        if(index1 == 0 || index2 == 0){
            return 0;
        }

        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(text1[index1-1] == text2[index2-1]) 
            return dp[index1][index2] = 1 + f(text1, text2, dp, index1 - 1, index2 - 1);

        return dp[index1][index2] = max(f(text1, text2, dp, index1 - 1, index2),f(text1, text2, dp, index1, index2 - 1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(text1, text2, dp, n, m);
    }
};

// bottom-up dynamic programming solution to the Longest Common Subsequence problem
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
            }
        }
        return dp[n][m];
    }
};
// space-optimized bottom-up dynamic programming solution to the Longest Common Subsequence problem
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), curr(m+1,0);
        
        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);    
            }
            prev = curr;
        }
        return prev[m];
    }
};

