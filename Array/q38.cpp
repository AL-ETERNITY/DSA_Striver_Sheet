#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int left,int mid,int right){
        int n1 = mid-left+1,n2 = right-mid;
        
        vector<int>temp1(n1),temp2(n2);
        for(int i=0;i<n1;i++){
            temp1[i] = arr[i+left];
        }
        for(int j=0;j<n2;j++){
            temp2[j] = arr[j+mid+1];
        }
        int i=0,j=0,k=left,count=0;
        while(i<n1 && j<n2){
            if(temp1[i]<=temp2[j]){
                arr[k] = temp1[i];
                k++;
                i++;
            }else{
                count+=(n1-i);
                arr[k] = temp2[j];
                k++;
                j++;
            }
        }
        while(i<n1){
            arr[k] = temp1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = temp2[j];
            j++;
            k++;
        }
        return count;
    }
    int mergesort(vector<int>&arr,int left,int right){
        if(left>=right){
            return 0;
        }
        int mid=left+(right-left)/2;
        int left1 = mergesort(arr,left,mid);
        int right1 = mergesort(arr,mid+1,right);
        
        int mer=merge(arr,left,mid,right);
        return left1+right1+mer;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergesort(arr,0,arr.size()-1);
    }
};