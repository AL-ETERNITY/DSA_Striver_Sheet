#include<bits/stdc++.h>
using namespace std;

class Solution {
  
  private:
    int lowerBound(vector<int> arr, int n, int x){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
  
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        int cnt_max = 0;
        int index = -1;
        for(int i=0;i<rows;i++){
            int cnt_ones = cols - lowerBound(arr[i],cols,1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};