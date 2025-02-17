#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int upperBound(vector<int> mat, int num) {
            int n = mat.size();
            int low = 0;
            int high = n - 1;
            int cnt = n;
    
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                if (mat[mid] > num) {
                    cnt = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
    
            return cnt;
        }
    
        int NoOfSmallerNum(vector<vector<int>> &mat, int num) {
            int n = mat.size();
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upperBound(mat[i], num);
            }
            return cnt;
        }
    
        int median(vector<vector<int>> &mat) {
            int low = INT_MAX;
            int high = INT_MIN;
            int R = mat.size();
            int C = mat[0].size();
    
            for (int i = 0; i < R; i++) {
                if (mat[i][0] < low) {
                    low = mat[i][0];
                }
                if (mat[i][C - 1] > high) {
                    high = mat[i][C - 1];
                }
            }
    
            int req = (R * C) / 2;
    
            int ans = -1; 
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                int smallernum = NoOfSmallerNum(mat, mid);
    
                if (smallernum > req) {
                    ans = mid; 
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            }
    
            return low;
        }
    };