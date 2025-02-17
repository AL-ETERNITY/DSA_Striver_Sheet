#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        int maxindex(vector<vector<int>>& mat,int& col){
            int index = -1;
            int maxi = INT_MIN;
            for(int i = 0;i<mat.size();i++){
                if(mat[i][col] > maxi){
                    maxi = mat[i][col];
                    index = i;
                }
            }
            return index;
        }
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            int s = 0;
            int e = m-1;
            int mid;
            while(s<=e){
                mid = s + (e-s)/2;
                int maxRowIndex = maxindex(mat,mid);
                int left = -1;
                int right = -1;
                if(mid-1 >= 0){
                    left = mat[maxRowIndex][mid-1];
                }
                if(mid+1 < m){
                    right = mat[maxRowIndex][mid+1];
                }
                //cout<<left<<" "<<right<<endl;
                if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                    return {maxRowIndex,mid};
                }
                else if(mat[maxRowIndex][mid] < left){
                    e = mid-1;
                }
                else{
                    s = mid + 1;
                }
            }
            return {-1,-1};
        }
        
    };