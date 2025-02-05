#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

    bool searchInSorted(vector<int>& arr, int k) {

        int n = arr.size();
        for(int i = 0;i<n;i++){
           if(arr[i] == k) {
            return true;
           }
        }
        return false;
    }