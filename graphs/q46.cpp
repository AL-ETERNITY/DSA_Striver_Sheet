// function to solve the problem of finding the largest island in a grid by converting one 0 to 1
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
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
private:
    bool isValid(int nrow, int ncol, int n, int m){
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> dirx = {0, 0, 1, -1}, diry = {1, -1, 0, 0};

        // Step 1: Connect all 1s
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                for(int i = 0; i < 4; i++){
                    int nrow = row + dirx[i];
                    int ncol = col + diry[i];
                    if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                        int curr = row * n + col;
                        int neighbour = nrow * n + ncol;
                        ds.unionBySize(curr, neighbour);
                    }
                }
            }
        }

        int maxSize = 0;

        // Step 2: Try converting 0s to 1s and check connected island size
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;

                set<int> components;
                for(int i = 0; i < 4; i++){
                    int nrow = row + dirx[i];
                    int ncol = col + diry[i];
                    if(isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1){
                        components.insert(ds.parentFind(nrow * n + ncol));
                    }
                }

                int sizeTotal = 0;
                for(auto it : components){
                    sizeTotal += ds.size[it];
                }

                maxSize = max(maxSize, sizeTotal + 1);
            }
        }

        // Step 3: In case grid has all 1s
        for(int cell = 0; cell < n * n; cell++){
            maxSize = max(maxSize, ds.size[ds.parentFind(cell)]);
        }

        return maxSize;
    }
};
