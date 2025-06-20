// function to solve the problem of selection sort
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        for(int i=0;i<arr.size();i++){
            int minindex = i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<arr[minindex]){
                    minindex = j;
                }
            }
            swap(arr[minindex],arr[i]);
        }
    }
};