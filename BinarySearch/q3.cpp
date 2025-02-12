#include<bits/stdc++.h>
using namespace std;


int binarySearchfloor(vector<int> &arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int index = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] <= target){
            index = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return index;
}

int binarySearchceil(vector<int> &arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int index = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        
        if(arr[mid] < target){
            s = mid + 1;
        }
        else{
            index = mid;
            e = mid - 1;
        }
    }
    return index;
}

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int floorIndex = binarySearchfloor(arr, x);
    int ceilIndex = binarySearchceil(arr, x);

    vector<int> ans;

    ans.push_back(floorIndex != -1 ? arr[floorIndex] : -1);

    ans.push_back(ceilIndex != -1 ? arr[ceilIndex] : -1);

    return ans;
}