// function to solve the problem of checking if a given array represents a max heap or not
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        for(int i=0;i<n;i++){
            int leftindex = 2*i + 1;
            int rightindex = 2*i + 2;
            if((leftindex <= n && arr[i] < arr[leftindex]) || (rightindex <= n && arr[i] < arr[rightindex])) 
                return false;
        }
        return true;
    }
};