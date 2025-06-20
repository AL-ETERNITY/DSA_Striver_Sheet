// function to sort an array using merge sort algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void merge(vector<int>& arr, int l, int mid, int r){
        int n1 = mid-l+1;
        int n2 = r-mid;
        vector<int> L(n1);
        vector<int> R(n2);
        
        for(int i=0;i<n1;i++){
            L[i] = arr[l+i];
        }
        for(int j=0;j<n2;j++){
            R[j] = arr[mid+1+j];
        }
        
        int i = 0 , j = 0;
        int k = l;

        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l>=r){
            return;
        }
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};