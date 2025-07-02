// function to solve the problem of flood fill in an image
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor == color) return image; // Avoid infinite loop

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                    image[nrow][ncol] == originalColor) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};
