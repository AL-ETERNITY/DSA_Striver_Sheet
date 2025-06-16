// function to solve the problem of converting a min heap to a max heap
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void heapify(vector<int> &arr, int N, int i){
        int parentindex = i;
        int leftindex = 2*i + 1;
        int rightindex = 2*i + 2;
        if(leftindex < N && arr[parentindex] < arr[leftindex]){
            parentindex = leftindex;
        }
        if(rightindex < N && arr[parentindex] < arr[rightindex]){
            parentindex = rightindex;
        }
        if (parentindex != i){
            swap(arr[parentindex], arr[i]);
            heapify(arr, N, parentindex);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i = N/2 - 1;i>=0;i--){
            heapify(arr,N,i);
        }
        return;
    }
};