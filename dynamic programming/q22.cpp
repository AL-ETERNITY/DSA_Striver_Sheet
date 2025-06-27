// function to solve the 0/1 Knapsack problem using recursion and memoization
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the 0/1 Knapsack problem 
class Solution {
  private:
    int f(vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp, int index) {
        if(index == 0){
            return (capacity / wt[0]) * val[0];
        }
        
        if(dp[index][capacity] != -1) return dp[index][capacity];
        
        int not_take = f(val, wt, capacity, dp, index-1);
        int take = 0;
        if(wt[index] <= capacity) 
            take = val[index] + f(val, wt, capacity - wt[index], dp, index);
            
        return dp[index][capacity] = max(not_take, take);
    }

  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return f(val, wt, capacity, dp, n-1);
    }
};

// bottom-up dynamic programming solution to the 0/1 Knapsack problem
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

        for(int i = 0; i <= capacity; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int not_take = dp[i-1][j];
                int take = 0;
                if(wt[i] <= j) 
                    take = val[i] + dp[i][j - wt[i]];
                
                dp[i][j] = max(not_take, take);
            }
        }
        return dp[n-1][capacity];
    }
};


// space-optimized bottom-up dynamic programming solution to the 0/1 Knapsack problem
class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<int> dp(capacity + 1, 0);

        // Base case for item 0
        for (int c = 0; c <= capacity; ++c) {
            dp[c] = (c / wt[0]) * val[0];
        }

        // Iterating over remaining items
        for (int i = 1; i < n; ++i) {
            for (int c = 0; c <= capacity; ++c) {
                int notTake = dp[c];
                int take = 0;
                if (wt[i] <= c) {
                    take = val[i] + dp[c - wt[i]];
                }
                dp[c] = max(take, notTake);
            }
        }

        return dp[capacity];
    }
};
