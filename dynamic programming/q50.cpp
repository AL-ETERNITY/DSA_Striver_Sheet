// function to solve the problem of minimum cuts for a palindrome partitioning
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming approach to solve the problem of minimum cuts for a palindrome partitioning
class Solution {
private:
    bool isPalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string& s, vector<int>& dp){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int mincost = 1e9;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)) {
                int cost = 1 + f(j + 1, n, s, dp);
                mincost = min(mincost, cost);
            }
        }

        return dp[i] = mincost;
    }

public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};

// bottom-up dynamic programming approach to solve the problem of minimum cuts for a palindrome partitioning
class Solution {
private:
    bool isPalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int mincost = 1e9;
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j+1];
                    mincost = min(mincost, cost);
                }
            }

            dp[i] = mincost;
        }
        return dp[0] - 1;
    }
};