// functiont to solve the Climbing Stairs problem using recursion, top-down dynamic programming, and bottom-up dynamic programming
#include<bits/stdc++.h>
using namespace std;

// recursive solution to the Climbing Stairs problem
class Solution {
private:
    void solve(int n, int index, int& cnt){
        if(index >= n){
            if(index == n) cnt++;
            return;
        }

        // take 1 step
        solve(n, index+1, cnt);

        // take 2 step
        solve(n, index+2, cnt);

    }
public:
    int climbStairs(int n) {
        int cnt = 0;
        solve(n,0,cnt);
        return cnt;
    }
};

// Top-down dynamic programming solution to the Climbing Stairs problem
class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// Bottom-up dynamic programming solution to the Climbing Stairs problem
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1, prev = 2;
        for(int i = 3; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};