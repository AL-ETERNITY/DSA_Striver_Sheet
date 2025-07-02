// function to solve the problem of finding the number of connected components in an undirected graph represented by an adjacency matrix.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
        visited[node] = 1;

        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        vector<vector<int>> adjList(v);
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(v, 0);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adjList, visited);
            }
        }

        return cnt;
    }
};

// time complexity is O(N) + O(V +2E) 
// space complexity is O(V) + O(V) + O(V) = O(3V) which is equivalent to O(V) in big O notation.