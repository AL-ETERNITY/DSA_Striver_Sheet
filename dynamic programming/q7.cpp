// function to solve the problem of maximizing points from tasks with constraints
#include<bits/stdc++.h>
using namespace std;

// top-down dynamic programming solution to maximize points from tasks with constraints
class Solution {
  private:
    int f(vector<vector<int>>& arr, vector<vector<int>>& dp, int day, int last){
        if(day == 0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i != last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int task = 0; task<3; task++){
            if(task != last){
                int point = arr[day][task] + f(arr,dp,day-1,task);
                maxi = max(maxi,point);
            }
        }
        
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return f(arr, dp, n-1, 3);
    }
};

// bottom-up dynamic programming solution to maximize points from tasks with constraints
class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

// space-optimized bottom-up dynamic programming solution to maximize points from tasks with constraints
class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(4,0);

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++) {
            vector<int> curr(4,0);
            for (int last = 0; last < 4; last++) {
                curr[last]=0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        curr[last] = max(curr[last],arr[day][task] + prev[task]);
                    }
                }
            }
            prev = curr;
        }

        return prev[3];
    }
};