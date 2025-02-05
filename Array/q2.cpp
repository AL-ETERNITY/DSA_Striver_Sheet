#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
    
    int getSecondLargest(vector<int> &arr) {
        int Second_largest = -1;
        int First_largest = -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>First_largest){
                Second_largest=First_largest;
                First_largest=arr[i];
            }
            else if(arr[i]<First_largest && arr[i]>Second_largest){
                Second_largest = arr[i];
            }
        }
        return Second_largest;
    }