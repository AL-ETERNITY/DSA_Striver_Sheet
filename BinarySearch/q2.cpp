#include<bits/stdc++.h>
using namespace std;


int findFloor(vector<int>& arr, int k) {

    int left = 0;
    int right = arr.size() - 1;
    int ans = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] <= k){
            ans = mid;
            left = left + 1;
        }
        else if(arr[mid] > k) right = mid - 1;
    }
    return ans;
}