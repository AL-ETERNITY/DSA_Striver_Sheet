// function to find the minimum cost to reach the last stair in frog jump problem
#include<bits/stdc++.h>
using namespace std;

// Recursive solution to the Frog Jump problem
class Solution {
private:
    int solve(int index, vector<int>& height) {
        if (index == 0) {
            return 0;
        }

        int left = solve(index - 1, height) + abs(height[index] - height[index - 1]);
        int right = INT_MAX;
        if (index > 1) {
            right = solve(index - 2, height) + abs(height[index] - height[index - 2]);
        }

        return min(left, right);

    }

public:
    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(n-1,height);
    }
};


// Top-down dynamic programming solution to the Frog Jump problem
class Solution {
private:
    int solve(vector<int>& height, vector<int>& dp, int index) {
        if(index == 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int left = solve(height, dp, index-1) + abs(height[index] - height[index - 1]);
        int right = INT_MAX;
        if (index > 1) {
            right = solve(height, dp, index-2) + abs(height[index] - height[index - 2]);
        }
        
        return dp[index] = min(left,right);
    }

public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        return solve(height,dp,n-1);
    }
};


// Bottom-up dynamic programming solution to the Frog Jump problem
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,0);
        for(int i=1;i<height.size();i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            
            dp[i] = min(fs,ss);
        }
        
        return dp[n-1];
    }
};

// Optimized bottom-up dynamic programming solution to the Frog Jump problem
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev2 = 0;
        int prev = 0;
        for(int i=1;i<height.size();i++){
            int fs = prev + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = prev2 + abs(height[i] - height[i-2]);
            }
            
            int curr = min(fs,ss);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};
