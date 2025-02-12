#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
        
    int ans=0;
    int st=0,end=arr.size()-1;
    
    while(st<=end){
        
        int mid=st+(end-st)/2;
        
        if(arr[0]<=arr[mid]){
            st=mid+1;
        }
        else 
        {
            ans=mid;
            end=mid-1;
        }
        
    }    
    return ans;
}