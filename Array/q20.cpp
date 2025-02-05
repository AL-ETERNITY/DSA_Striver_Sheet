#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++){
            int cost = prices[i]-mini;
            maxProfit = max(cost,maxProfit);
            mini = min(prices[i],mini);
        }
        return maxProfit;
    }
};