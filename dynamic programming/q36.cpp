// function to solve the problem of maximizing profit with at most k transactions
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // after[buy][cap]: profit on the next day with 'buy' status and 'cap' transactions left
        vector<vector<int>> after(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        curr[buy][cap] = max(
                            -prices[i] + after[0][cap],  // buy
                            0 + after[1][cap]            // skip
                        );
                    } else {
                        curr[buy][cap] = max(
                            prices[i] + after[1][cap - 1],  // sell
                            0 + after[0][cap]               // skip
                        );
                    }
                }
            }
            after = curr;  // move to the previous day
        }

        return after[1][k];  // start with buy allowed and 2 transactions
    }
};