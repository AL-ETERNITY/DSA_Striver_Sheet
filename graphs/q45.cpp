// function to solve the problem of counting the number of islands after each operation
#include <bits/stdc++.h>
using namespace std;
 
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int parentFind(int node) {
        if (parent[node] == node) return node;
        return parent[node] = parentFind(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = parentFind(u);
        int pv = parentFind(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
  private:
    bool isValid(int nrow, int ncol, int n, int m){
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) return true;
        else return false;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> visited(n, vector<int>(m,0));
        int cnt = 0;
        vector<int> ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(visited[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            
            vector<int> dirx = {0, 0, 1, -1}, diry = {1, -1, 0, 0};
            for(int i = 0; i<4; i++){
                int nrow = row + dirx[i];
                int ncol = col + diry[i];
                if(isValid(nrow, ncol, n, m)){
                    if(visited[nrow][ncol] == 1){
                        int curr = row*m + col;
                        int neighbour = nrow*m + ncol;
                        if(ds.parentFind(curr) != ds.parentFind(neighbour)){
                            cnt--;
                            ds.unionBySize(curr, neighbour);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
