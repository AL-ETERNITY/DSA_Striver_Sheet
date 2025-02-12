#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target , bool isLeftSearch){
    int s = 0;
    int e = arr.size()-1;
    int index = -1; 
    
    while(s<=e){
        int mid = s + (e-s)/2;
        
        if(arr[mid] > target){
            e = mid-1;
        }
        else if(arr[mid] < target){
            s = mid+1;
        }
        else{
            index = mid;
            if(isLeftSearch){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
    }
    return index;
}

int countFreq(vector<int>& arr, int target) {

        int left = binarySearch(arr, target, true);
        int right = binarySearch(arr, target, false);
        if(left != -1 && right != -1)
            return (right-left+1);
        else
            return 0;
            
}