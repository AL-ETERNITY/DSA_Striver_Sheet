// function to solve the problem of replacing each element in an array with its rank
using namespace std;
#include <bits/stdc++.h>

class Solution {
    public:
  
      vector<int> replaceWithRank(vector<int> &arr, int N) {
          priority_queue<int, vector<int>, greater<int>> minHeap;
          
          for(int i : arr) {
              minHeap.push(i);
          }
          
          int cnt = 1;
          unordered_map<int, int> map;
          
          while(!minHeap.empty()) {
              int temp = minHeap.top(); minHeap.pop();
              
              if(map.find(temp) == map.end()) {
                  map[temp] = cnt++;
              }
          }
          
          for(int i = 0; i < arr.size(); i++) {
              arr[i] = map[arr[i]];
          }
          
          return arr;
      }
  };
