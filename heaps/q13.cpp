// function to solve the problem of finding the minimum cost to combine elements in an array
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int minCost(vector<int>& arr) {
          priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end()); // Min heap
  
          int totalCost = 0;
  
          while (pq.size() > 1) {
              int first = pq.top(); pq.pop();
              int second = pq.top(); pq.pop();
  
              int cost = first + second;
              totalCost += cost;
  
              pq.push(cost);
          }
  
          return totalCost;
      }
  };