// fucntion to solve the problem of cutting a rod into pieces to maximize profit
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to the Rod Cutting problem
class Solution {
  private:
    int f(vector<int> &price, vector<vector<int>>& dp, int index, int size){
        if(index == 0){
            return size * price[0];
        }
        
        if(dp[index][size] != -1) return dp[index][size];
        
        int not_take = f(price, dp, index - 1, size);
        int take = INT_MIN;
        if(index + 1 <= size)
            take = price[index] + f(price, dp, index, size - (index + 1));
        
        return dp[index][size] = max(take, not_take);
    }

  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(price, dp, n - 1, n);
    }
};

// bottom-up dynamic programming solution to the Rod Cutting problem
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        for(int size=0;size<=n;size++){
            dp[0][size] = size * price[0];
        }
        
        for(int index = 1; index<n; index++){
            for(int size = 0; size<=n; size++){
                int not_take = dp[index-1][size];
                int take = INT_MIN;
                if(index + 1 <= size)
                    take = price[index] + dp[index][size-(index+1)];
                
                dp[index][size] = max(take, not_take);
            }
        }
        
        return dp[n-1][n];
    }
};

// space-optimized bottom-up dynamic programming solution to the Rod Cutting problem
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1,0), curr(n+1,0);
        
        for(int size=0;size<=n;size++){
            prev[size] = size * price[0];
        }
        
        for(int index = 1; index<n; index++){
            for(int size = 0; size<=n; size++){
                int not_take = prev[size];
                int take = INT_MIN;
                if(index + 1 <= size)
                    take = price[index] + curr[size-(index+1)];
                
                curr[size] = max(take, not_take);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};
